#pragma once

#include <iostream>

template <typename T>
class TestObj {
public:
  TestObj() = default;

  TestObj(const T item) {
    item_ = item;
    std::cout << "create const T " << item_ << "\n";
  }

  TestObj(T* item) {
    if (item)
      item_ = *item;
    std::cout << "create *item " << item_ << "\n";
  }

  TestObj(const TestObj& other) {
    item_ = other.item_;
    std::cout << "create &TestObj " << item_ << "\n";
  }

  TestObj(TestObj&& other) {
    std::cout << "create &&TestObj" << other.item_ << "\n";
    std::swap(item_, other.item_);
  }

  TestObj& operator=(const TestObj& rhs) {
    std::cout << "operator =& \n";
    item_ = rhs.item_;
    return *this;
  }

  TestObj& operator=(TestObj&& other) {
    std::cout << "operator =moved \n";
    if (this == &other) {
      return *this;
    }
    item_ = other.item_;
    other.item_;
    return *this;
  }

  bool operator<(const TestObj& rhs) const {
    std::cout << "operator < \n";
    return item_ < rhs.item_;
  }

  bool operator<=(const TestObj& rhs) const {
    std::cout << "operator <= \n";
    return item_ <= rhs.item_;
  }

  bool operator==(const TestObj& rhs) const {
    std::cout << "operator == \n";
    return item_ == rhs.item_;
  }
  
  bool operator!=(const TestObj& rhs) const {
    std::cout << "operator == \n";
    return !(item_ == rhs);
  }

  bool operator>(const TestObj& rhs) const {
    std::cout << "operator < \n";
    return !(item_ <= rhs);
  }

  bool operator>=(const TestObj& rhs) const {
    std::cout << "operator <= \n";
    return !(item_ < rhs);
  }


  void set(const T item) {
    item_ = item;
  }

  T get() const {
    return item_;
  }

private:
  T item_ = NULL;
};
