//
// Created by unrelated on 24-10-18.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int> &nums) {
    // 堆化

    for (size_t i = 0; i < nums.size(); ++i) {
      auto j = i;
      auto next = (j - 1) / 2;
      while (j && nums[j] > nums[next]) {
        std::swap(nums[j], nums[next]);
        j = next;
        next = (j - 1) / 2;
      }
    }

    std::pair<int, int> a;
    auto [_1, _2] = a;

    for (size_t i = 0; i < nums.size(); ++i) {
      auto to_swap_idx = nums.size() - i - 1;
      std::swap(nums[0], nums[to_swap_idx]);

      size_t idx = 0;
      size_t next_idx = 2 * idx + 1;
      while (next_idx < to_swap_idx) {
        if (next_idx + 1 < to_swap_idx && nums[next_idx + 1] > nums[next_idx]) ++next_idx;
        if (nums[next_idx] > nums[idx]) {
          std::swap(nums[next_idx], nums[idx]);
          idx = next_idx;
          next_idx = 2 * idx + 1;
        } else {
          break;
        }
      }
    }

    return std::move(nums);
  }
};

int main() {
  std::vector<int> data = {-74, 48, -20, 2, 10, -84, -5, -9, 11, -24, -91, 2, -71, 64, 63, 80, 28, -30, -58, -11, -44,
                           -87, -22, 54, -74, -10, -55, -28, -46, 29, 10, 50, -72, 34, 26, 25, 8, 51, 13, 30, 35, -8,
                           50, 65, -6, 16, -2, 21, -78, 35, -13, 14, 23, -3, 26, -90, 86, 25, -56, 91, -13, 92, -25, 37,
                           57, -20, -69, 98, 95, 45, 47, 29, 86, -28, 73, -44, -46, 65, -84, -96, -24, -12, 72, -68, 93,
                           57, 92, 52, -45, -2, 85, -63, 56, 55, 12, -85, 77, -39};

  Solution s;
  for (auto &v: s.sortArray(data)) {
    std::cout << v << ' ';
  }
  return 0;
}