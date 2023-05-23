#ifndef JUG_H
#define JUG_H

class Jug {
  const int capacity_;
  int current_;

public:
  Jug(int capacity);
  bool fill();
  bool drain();
  bool pour(Jug &other);

  int &current();
  int capacity();
  bool empty();
  void print_info();
};

#endif
