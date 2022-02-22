#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;

template<typename T>
T average(std::vector<T> &v)
{
  T sum {0};
  for (auto x : v)
  {
    sum += x;
  }

  return sum / v.size();
}

int main()
{
  std::vector<double> vec;
  cout << "Enter 5 values: ";
  double d {0.0};
  for (int i{0}; i < 5; i++)
  {
    cin >> d;
    vec.push_back(d);
  }
  cout << "average = " << average(vec) << endl;

  cout << "program close" << std::endl;
  return 0;
}
