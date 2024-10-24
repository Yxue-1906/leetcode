//
// Created by unrelated on 24-10-24.
//

#include <iostream>
#include <tuple>

int main() {
  int a, b;
  int b, c;
  std::tie(a, b) = std::tie(b, c);
}