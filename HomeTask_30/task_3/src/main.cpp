#include <iostream>
#include "requests.h"

int main() {
  std::cout << "Задание 3. Запросы с аргументами" << std::endl << std::endl;
  Requests req;

  std::string typeReq {""};
  while((typeReq = req.enter()) == "");

  if(typeReq == "get") { req.get(); }
  if(typeReq == "post") { req.post(); }

  return 0;
}
