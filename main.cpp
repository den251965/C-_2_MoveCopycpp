#include <iostream>
#include <set>
#include <vector>

#include "testcllass.h"


int main() {
  TestObj<int> test;
  int it = 100;
  test.set(it);
  TestObj<int> test_5(it);
  std::cout << "test = " << test.get() << " test_5 = " << test_5.get() << "\n";

  std::cout << "it Upload" << it << " ";

  test = 56;
  std::cout << " -> " << it << "\n";
  std::cout << "test = " << test.get() << " test_5 = " << test_5.get() << "\n";

  std::cout << "---------------------------------  " << "\n";

  TestObj<int> test_2(std::move(test));
  std::cout << "test_2.item_ = " << test_2.get() << " test.item_  = " << test.get() << "\n";

  std::cout << "---------------------------------  " << "\n";

  TestObj<int> test_3(std::move(test_5));
  std::cout << "test_3.item_ = " << test_3.get() << " test_5.item_ = " << test_5.get() << "\n";
  std::cout << "test_3 -> test_5 " << "\n";
  test_5 = std::move(test_3);
  std::cout << test_5.get() << " " << test_5.get() << "\n";

  std::cout << "---------------------------------  " << "\n";

  std::cout << " std::vector<TestObj<int>> vec \n";
  std::vector<TestObj<int>> vec;
  vec.push_back(test_2);
  vec.push_back(std::move(test_5));
  vec.push_back(test);
  vec.push_back(2);
  std::cout << " print vec \n";
  for (auto& m : vec) {
    std::cout << m.get() << " ";
  }
  std::cout << "\n";

  std::cout << "---------------------------------  " << "\n";

  std::cout << " std::set<TestObj<int>> vec \n";
  std::set<TestObj<int>> sec;
  sec.insert(test_2);
  sec.insert(std::move(test_5));
  sec.insert(test);
  sec.insert(2);
  std::cout << " print set \n";
  for (auto& m : vec) {
    std::cout << m.get() << " ";
  }
  std::cout << "\n";

  std::cout << "---------------------------------  " << "\n";

  TestObj<int> test_4;
  test_4 = test_2;
  std::cout << "test_4.item_ = " << test_4.get() << "\n";

  std::cout << "---------------------------------  " << "\n";

  std::cout << "Succeses!!!\n";
  return 0;
}
