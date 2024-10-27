// O(n^2) 做法

#include <iostream>
#include <vector>
#include <memory>
#include <map>

using namespace std;

template<class F>
struct Guard {
  bool dismiss_ = false;
  F f_;
  Guard(F f) : f_(std::forward<F>(f)) {
  }
  ~Guard() {
    if (!dismiss_) f_();
  }
};

template<class F>
auto create_guard(F &&f) {
  return std::make_unique<Guard<F>>(std::forward<F>(f));
}

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;

    map<int, int> nums_to_freq;
    for (auto num: nums) {
      nums_to_freq.insert({num, 0}).first->second++;
    }

    for (auto i = nums_to_freq.begin(); i != nums_to_freq.end(); ++i) {
      auto &[num1, freq1] = *i;
      --freq1;
      auto guard = create_guard([&freq = freq1] { ++freq; });
      for (auto j = i; j != nums_to_freq.end(); ++j) {
        auto &[num2, freq2] = *j;
        if (!freq2) continue;
        --freq2;
        auto guard = create_guard([&freq = freq2] { ++freq; });
        auto to_find = -num1 - num2;
        if (to_find < num2) break;
        auto ite = nums_to_freq.find(to_find);
        if (ite == nums_to_freq.end() || !ite->second) continue;
        ans.push_back({num1, num2, to_find});
      }
    }

    return std::move(ans);
  }
};

int main() {
  vector<int> data = {0, 0, 1};
  Solution s;

  auto ans = s.threeSum(data);

  for (auto &a: ans) {
    for (auto v: a) {
      std::cout << v << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}