#include <iostream>

#include "Josephus.h"

template <typename T>
T
prompt(char const * const string) {
  T value;
  std::cout << string;
  std::cin >> value;
  return value;
}

int
main ()
{
  const auto N = prompt<int>("N ==> ");
  const auto k = prompt<int>("k ==> ");
  int survivor = josephus(N, k);
  std::cout << "The survivor is " << survivor << std::endl;
  return 0;
}
