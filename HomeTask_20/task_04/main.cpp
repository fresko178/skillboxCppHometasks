#include <iostream>
#include <fstream>
#include <ctime>
#include <string_view>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::string_view;
using Bank = std::vector<std::vector<size_t>>; // хранит кол. банкнот и их достоинство
constexpr int MAX = 1000;

void refill(Bank &);
void getMoney(Bank &);
Bank getStatusBank();
void Initialisation();
size_t getAmountBanknotes(Bank &, Bank &, size_t, size_t);
bool checkBankSum(Bank &, size_t);
void saveToFile(Bank &);

int main() {
  cout << "Задание 4. Реализация симуляции банкомата" << endl << endl;
  Initialisation(); // автономный файл для хранения состояния банкомата
  Bank bank = getStatusBank();
  char operation {0};
  while (operation != '+' && operation != '-') {
    cout << endl << "Введите операцию (+/-  наполнить банкомат/снятие денег): ";
    cin >> operation;
    if (operation == '+') { // заполняем банкомат банкнотами
      refill(bank);
      getStatusBank();
    }
    else if (operation == '-') {
      getMoney(bank);
    }
  }

  return 0;
}

// если автономный файл для хранения состояния банкомата не существует
void Initialisation() {
  std::ifstream fileATM("atm.bin", std::ios::binary);
  if (!fileATM.is_open()) {
    std::ofstream file("atm.bin", std::ios::binary);
    file.close();
  } else {
    fileATM.close();
  }
}

Bank getStatusBank() {
  Bank bank {{0, 100}, {0, 200}, {0, 500}, {0, 1000}, {0, 2000}, {0, 5000}}; // счётчики купюр
  std::ifstream fileATM("atm.bin", std::ios::binary);
  size_t count {0}; // счётчик банкнот
  if (fileATM.is_open()) {
    fileATM.read((char*)&bank[0][0], (bank.size()+1) * sizeof(bank[0]));
    fileATM.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для чтения" << endl;
    exit(EXIT_FAILURE);
  }
  count = bank[0][0] + bank[1][0] + bank[2][0] + bank[3][0] + bank[4][0] + bank[5][0]; // считаем кол. банкнот
  cout << endl <<"[СТАТУС] в банкомате " << count << " банкнот" << endl;
  for (size_t codeBanknote {0}; codeBanknote < 6; codeBanknote++) {
    cout << "кол. банкнот " << bank[codeBanknote][1] << " = " << bank[codeBanknote][0] << endl;
  }
  return bank;
}

void refill(Bank &bank) {
  size_t count {0}; // счётчик банкнот
  for (size_t i {0}; i < 6; i++) { // считаем остаток банкнот в банкомате
    count += bank[i][0];
  }
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  size_t codeBanknote {0};
  while (count < MAX) { // заправляем банкомат до максимального кол. банкнот
    codeBanknote = std::rand() % 6; // получаем код банкноты
    bank[codeBanknote][0]++; // заполняем банкомат
    count++;
  }
  saveToFile(bank);
}

void getMoney(Bank &bank) {
  cout << "Введите сумму снятия: ";
  size_t sum {0};
  cin >> sum;
  Bank user {{0, 100}, {0, 200}, {0, 500}, {0, 1000}, {0, 2000}, {0, 5000}}; // каких банкнот и сколько будет выдано
  if (checkBankSum(bank, sum)) { // хватаетли денег в банкомате
    if (sum % 100 == 0) { // сумма кратна ста
      cout << "Выдано: " << endl;
      for (size_t codeBanknote {0}; codeBanknote < 6; codeBanknote++) {
        sum = getAmountBanknotes(bank, user, sum, 5 - codeBanknote);
      }
      saveToFile(bank);
      size_t countBanknotes {0}; // кол. выданных банкнот
      for (size_t codeBanknote {0}; codeBanknote < 6; codeBanknote++) {
        if (user[codeBanknote][0] > 0) {
          cout << "банкнот достоинством " << user[codeBanknote][1] << " = " << user[codeBanknote][0] << endl;
          countBanknotes = user[codeBanknote][0];
        }
      }
      if (countBanknotes == 0) {
        cout << "банкнот " << countBanknotes << endl;
        cout << "В банкомате нет банкнот соответствующего достоинства" << endl;
      }
    } else {
      cout << "[ОШИБКА] Банкомат выдаёт только суммы кратные ста" << endl;
    }
  } else {
    cout << "[ОШИБКА] В банкомате недостаточно средств" << endl;
  }
}

// определяет кол. банкнот соответствующего достоинства в сумме и сохраняет значение
// возвращает сумму после вычитания банкнот
size_t getAmountBanknotes(Bank &bank, Bank &user, size_t sum, size_t codeBanknote) {
  if (sum / bank[codeBanknote][1] > 0) { // определяем кол. банкнот
    if ((bank[codeBanknote][0] >= sum / bank[codeBanknote][1])) { // в банкомате хватает банкнот
      bank[codeBanknote][0] -= user[codeBanknote][0] = sum / bank[codeBanknote][1]; // выдаём из банкомата банкноты и запоминаем сколько выдали
      sum = sum % bank[codeBanknote][1]; // остаток суммы
    } else { // выдаём остатки банкнот
      sum -= bank[codeBanknote][1] * bank[codeBanknote][0]; // оставшаяся сумма (достоинство банкноты умножается на кол. банкнот)
      user[codeBanknote][0] = bank[codeBanknote][0]; // выдаём весь остаток банкнот
      bank[codeBanknote][0] = 0;
    }
  }
  return sum;
}

// проверяет хватаетли дененг в банкомате
bool checkBankSum(Bank &bank, size_t sum) {
  size_t sumBank {0};
  for (size_t codeBanknote {0}; codeBanknote < 6; codeBanknote++) {
    sumBank += bank[codeBanknote][0] * bank[codeBanknote][1];
  }
  if (sumBank >= sum) { return true;} // денег хватает

  return false; // денег не хватает
}

void saveToFile(Bank &bank) {
  std::ofstream fileATM("atm.bin", std::ios::binary);
  if (fileATM.is_open()) {
    fileATM.write((char*)&bank[0][0], (bank.size()+1) * sizeof(bank[0])); // сохраняем состояние банкомата
    fileATM.close();
  } else {
    cout << "[ОШИБКА] Не удалось открыть файл для записи" << endl;
    exit(EXIT_FAILURE);
  }
}

