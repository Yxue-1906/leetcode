//
// Created by unrelated on 24-10-24.
//
#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

struct Wrapper {
  std::string &s_;

  Wrapper(string &s) : s_(s) {
  }

  auto operator[](size_t idx) {
    if (idx > s_.size()) {
      std::cerr << "overflow :" << "[str_size: " << s_.size() << "][idx: " << idx << "]" << std::endl;
      std::exit(0);
    }
    return s_[idx];
  }
  size_t size() {
    return s_.size();
  }
  std::string substr(size_t start, size_t cnt) {
    return s_.substr(start, cnt);
  }
};

class Solution {
 public:
  string longestPalindrome(string str) {
    size_t start = 0;
    size_t end = 0;
    Wrapper s(str);
    for (int i = 0; i < s.size(); ++i) {
      size_t half_len = 0;
      // count odd len substring
      for (; i + half_len < s.size() && i - half_len >= 0; ++half_len) {
        if (s[i + half_len] != s[i - half_len]) break;
      }
      half_len -= 1;
      if (2 * half_len + 1 > end - start + 1) {
        start = i - half_len;
        end = i + half_len;
      }
      int j = i, k = i + 1;
      for (; j >= 0 && k < s.size(); --j, ++k) {
        if (s[j] != s[k]) break;
      }
      if (k - j - 1 > end - start + 1)
        std::tie(start, end) = std::make_pair(j + 1, k - 1);
    }

    std::cout << start << ' ' << end << std::endl;
    return s.substr(start, end - start + 1);
  }
};

int main() {
  string s = "cbbd";

  Solution so;
  std::cout << so.longestPalindrome(s) << std::endl;
  return 0;
}