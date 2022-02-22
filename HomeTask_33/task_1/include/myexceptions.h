#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <exception>

class NameEmpty : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "name is empty";
  }
};

class CountEmpty : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "count is zero";
  }
};

class BasketEmpty : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "Basket is already empty";
  }
};

#endif // MYEXCEPTIONS_H
