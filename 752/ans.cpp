#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  unordered_map<string, int> min_steps;
  string target_;

  void sroll_char(char &c, int offset) {
    auto v = c - '0' + offset;
    c = '0' + (v % 10);
  }
  void travel(string &now, int steps) {
    auto ite = min_steps.find(now);
    if (ite != min_steps.end()) {
      auto v = ite->second;
      if (v == -1 || v < steps) return;
      else ite->second = steps;
    } else {
      min_steps.emplace(now, steps);
      if (now == target_) return;
    }
    for (auto &c: now) {
      auto save = c;
      sroll_char(c, 1);
      travel(now, steps + 1);
      c = save;
      sroll_char(c, -1);
      travel(now, steps + 1);
    }
  }

  int openLock(vector<string> &deadends, string target) {
    if (target == "0000") return 0;

    for (auto &dead: deadends) {
      min_steps.emplace(dead, -1);
    }
    target_ = std::move(target);

    if (min_steps.count("0000")) return -1;

    string from = "0000";
    travel(from, 0);

    auto ite = min_steps.find(target);
    if (ite == min_steps.end()) return -1;
    else return ite->second;
  }
};

int main() {
  vector<string> dead = {"0201", "0101", "0102", "1212", "2002"};
  string target = "0202";

  Solution s;
  std::cout << s.openLock(dead, target);

  return 0;
}