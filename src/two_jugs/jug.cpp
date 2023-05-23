#include "jug.h"
#include <iostream>
#include <stdlib.h>

Jug::Jug(int capacity) : capacity_(capacity), current_(0) {}

bool Jug::fill() {
  if (current_ == capacity_)
    return (false);
  current_ = capacity_;
  return (true);
}

bool Jug::drain() {
  if (current_ == 0)
    return (false);
  current_ = 0;
  return (true);
}

bool Jug::pour(Jug &other) {
  if (current_ == 0 || other.current_ == other.capacity_)
    return (false);
  if (other.capacity_ - other.current_ >= current_) {
    other.current_ += current_;
    drain();
  } else {
    current_ -= (other.capacity_ - other.current_);
    other.fill();
  }
  return (true);
}

void Jug::print_info() {
  std::cout << "Jug: " << current_ << " / " << capacity_ << '\n';
}

int &Jug::current() { return current_; }

int Jug::capacity() { return capacity_; }

bool Jug::empty() { return current_ == 0; }
