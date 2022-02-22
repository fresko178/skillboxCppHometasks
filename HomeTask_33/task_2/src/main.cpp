#include <iostream>
#include <map>
#include "myexceptions.h"
#include <random>
#include <ctime>

using std::cout;
using std::endl;
using std::cin;
using std::string;

constexpr int SIZE {9};
static int countTry{0};

void initialization(int array[]);
void fishing(int array[]);

int main()
{
// значения в массиве: 0 - пустой сектор; 1 - рыба; 2 - сапог
  int array[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
  initialization(array);
  try
  {
    fishing(array);
  }
  catch (const Win &e)
  {
    cout << e.what() << endl;
  }
  catch (const Losing &e)
  {
    cout << e.what() << endl;
  }
  cout << "number of attempts: " << countTry << endl;
  cout << "program close" << std::endl;
  return 0;
}

void initialization(int *array)
{
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  array[std::rand() % SIZE] = 1; // рыба моей мечты
  int boots = 3;  // сапоги колхозников
  int index {0};  // индекс массива
  while(boots > 0)
  {
    index = std::rand() % SIZE;
    if (array[index] == 0)
    {
       array[index] = 2; // рыба моей мечты
       boots--;
    }
  }
}

void fishing(int array[])
{
  int result {0};
  int index {0};  // индекс массива
  while(result == 0) // ловись рыбка большая и побольше
  {
    countTry++;
    index = std::rand() % SIZE;
    if (array[index] == 0)
    {
      cout << "one more time, just do it" << endl;
    }
    else if (array[index] == 1) // 777
    {
      throw Win();
    }
    else
    {
      throw Losing();
    }
  }
}
