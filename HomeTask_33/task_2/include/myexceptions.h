#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <exception>

class Win : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "win!";
  }
};

class Losing : public std::exception
{
public:
  const char* what() const noexcept override
  {
    return "loss!";
  }
};

#endif // MYEXCEPTIONS_H
