#ifndef ANIMAL_H
#define ANIMAL_H

class Animal {
public:
  Animal();
  virtual ~Animal();
  virtual char* get() = 0;
};

#endif // ANIMAL_H
