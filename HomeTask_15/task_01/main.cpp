// к сумме пары чисел index_0 и index_1 прибавляем следующий элемент index_2,
// если результат > этой суммы, то сумму увеличиваем на значение index_2
// иначе возможно cумма пары чесел index_1 и index_2 дадут результат превышающий
// предыдущий, если да, то у нас новая пара к которой потом, возможно, будем суммировать
// иначе сдвигаемся дальше по массиву

#include <iostream>
#include <array>
using std::cout;
using std::cin;
using std::endl;
using std::array;

constexpr int SIZE {9};

int main() {
  cout << "Задача 1" << endl;
  array<int, SIZE> arr {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int sum {arr[0] + arr[1]}; // текущая сумма
  int res {sum}; // итоговый результат
  size_t count {1}; // счётчик сложений (будет использоваться для расчёта начала подмассива)
  size_t end {1}; // индекс конца подмассива (1 т.к. в sum уже первые два элемента)
  for (size_t i {2}; i < SIZE; i++) {
    if (sum + arr[i] > res) { // сумма с следующим элементом выросла
      sum += arr[i];
      res = sum;
      count++; // подсчитываем кол. сложений
      end = i;
    } else if (arr[i] + arr[i - 1] > res) { // может след. пара даст бол. сумму
      res = sum = arr[i] + arr[i - 1];
      end = i;
      count = 1;
    } else { // сумма не выросла берём след. пару
      sum = arr[i] + arr[i - 1];
    }
  }

  cout << "array = ";
  for (size_t i = 0; i < SIZE; i++) {
    cout << arr[i] << "  ";
  }
  cout << endl << "sum = " << res << endl;
  cout << "index " << end - count << ":" << end << endl << "subarray = ";
  for (size_t i {end - count}; i <= end; i++) {
    cout << arr[i] << "  ";

  }
  cout << endl << endl;

  return 0;
}

