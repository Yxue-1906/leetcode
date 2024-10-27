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

    for(auto num : nums) {
      std::cout << num << ' ';
    }
    std::cout << std::endl;

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

#include <limits>
int main() {
  std::vector<int> data = { 45, 78, 57, 25, 41, 89};
  Solution s;
  for (auto &v: s.sortArray(data)) {
    std::cout << v << ' ';
  }
  return 0;
}