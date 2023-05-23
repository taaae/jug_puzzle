#include "jug.h"
#include <iostream>

int main(int argc, char **argv) {
  (void)argc;
  // first < goal < second
  Jug first(3);
  Jug second(7);
  // auto print = [&first, &second]{ first.print_info(); second.print_info();
  // std::cout << '\n'; };
  int goal = atoi(argv[1]);
  second.current() = goal;
  int counter1 = 0;
  while (!second.empty() || !first.empty()) {
    if (first.pour(second) == false) {
      if (second.current() == second.capacity())
        second.drain();
      else
        first.fill();
    }
    counter1++;
  }
  second.current() = goal;
  int counter2 = 0;
  while (!second.empty() || !first.empty()) {
    if (second.pour(first) == false) {
      if (first.current() == first.capacity())
        first.drain();
      else
        second.fill();
    }
    counter2++;
  }
  // total: 2(a + b) - 1
  std::cout << counter1 << ' ' << counter2 << '\n';
}
