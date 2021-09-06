#include <iostream>

using std::cout;
using std::endl;

void evendigits(long long, int &);

int main() {
  cout << "Задача 4." << endl << endl;
  int count {0}; // кол. чётных чисел в числе

  long long n = 9223372036854775806; // из задания
  cout << "n = " << n << endl;
  evendigits(n, count);
  cout << "Кол. чётных чисел = " << count << endl << endl;
  count = 0;

  n = 2222222222222222222; // все чётные
  cout << "n = " << n << endl;
  evendigits(n, count);
  cout << "Кол. чётных чисел = " << count << endl << endl;
  count = 0;

  n = 3333333333333333333; // все нечётные
  cout << "n = " << n << endl;
  evendigits(n, count);
  cout << "Кол. чётных чисел = " << count << endl << endl;
  count = 0;

  n = 3333333333433333333; // одна чётная
  cout << "n = " << n << endl;
  evendigits(n, count);
  cout << "Кол. чётных чисел = " << count << endl << endl;
  count = 0;

  n = 4444444444544444444; // одна нечётная
  cout << "n = " << n << endl;
  evendigits(n, count);
  cout << "Кол. чётных чисел = " << count << endl << endl;
  count = 0;

  cout << endl << endl;
  return 0;
}

// n - анализируемое число на предмет кол. чётных чисел
// ans – кол. чётных чисел
void evendigits(long long n, int &ans) {
  if (n != 0) {
    if ((n % 10) % 2 == 0) { // если цифра чётная
        ans++;
    }
    evendigits(n / 10, ans);
  }
}

