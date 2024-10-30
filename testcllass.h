#pragma once

#include <iostream>

template <typename T>
class TestObj {
public:
  TestObj() {
    item_ = new T;
  }

  TestObj(const T item) {
    item_ = new T(item);
    std::cout << "create const T " << "\n";
  }

  TestObj(T* item) {
    if (item)
      item_ = *item;
    std::cout << "create *item " << "\n";
  }

  TestObj(const TestObj& other) {
    std::cout << "create &TestObj " << "\n";
    delete item_;
    T temp = *other.item_;
    item_ = new T(temp);
  }

  TestObj(TestObj&& other) {
    std::cout << "create &&TestObj" << "\n";
    item_ = other.item_;
    other.item_ = nullptr;
  }

  ~TestObj() {
    std::cout << "deleted" << "\n";
    delete item_;
    item_ = nullptr;
  }

  TestObj& operator=(const TestObj& rhs) noexcept {
    std::cout << "operator =& \n";
    item_ = rhs.item_;
    return *this;
  }

  TestObj& operator=(TestObj&& other) noexcept {
    std::cout << "operator =moved \n";
    if (this != &other) {
      delete item_;
      item_ = std::exchange(other.item_, nullptr);
    }
    return *this;
  }

  bool operator<(const TestObj& rhs) const noexcept {
    std::cout << "operator < \n";
    return *item_ < *rhs.item_;
  }

  bool operator<=(const TestObj& rhs) const noexcept {
    std::cout << "operator <= \n";
    return *item_ <= *rhs.item_;
  }

  bool operator==(const TestObj& rhs) const noexcept {
    std::cout << "operator == \n";
    return *item_ == *rhs.item_;
  }

  bool operator!=(const TestObj& rhs) const noexcept {
    std::cout << "operator == \n";
    return !(this == rhs);
  }

  bool operator>(const TestObj& rhs) const noexcept {
    std::cout << "operator < \n";
    return !(this <= rhs);
  }

  bool operator>=(const TestObj& rhs) const noexcept {
    std::cout << "operator <= \n";
    return !(this < rhs);
  }

  void set(T* item) {
    item_ = item;
  }

  T* get() const {
    return item_;
  }

  explicit operator bool() const {
    return (item_) ? true : false;
  }

  void swap(TestObj& other) noexcept {
    T* temp = other.item_;
    other.item_ = item_;
    item_ = temp;
  }

private:
  T* item_ = nullptr;
};
