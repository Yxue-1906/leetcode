//
// Created by unrelated on 24-10-17.
//

#include <vector>
#include <iostream>

class Solution {
 public:
  void sort(std::vector<int> &nums, size_t left, size_t right) {
    if (right - left <= 1) return;
    size_t partition = left;

    size_t i = left, j = right;
    while (i < j) {
      do ++i; while (i < right && nums[i] <= nums[partition]);
      do --j; while (j > left && nums[j] >= nums[partition]);
      if (i < j)
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[partition], nums[j]);
    sort(nums, left, j - 1);
    sort(nums, j + 1, right);
  }

  void sortArray(std::vector<int> &nums) {
    std::vector<std::pair<int, int>> to_sorts;

    if (nums.size() < 2) return;

    to_sorts.emplace_back(0, nums.size() - 1);

    for (int i = 0; i < to_sorts.size(); ++i) {
      auto [left_end, right_end] = to_sorts[i];
      if (right_end - left_end < 1) continue;

      auto partition = left_end;

      auto left = left_end, right = right_end;
      while (left < right) {
        while (left < right_end && nums[left] <= nums[partition]) ++left;
        while (right > left_end && nums[right] > nums[partition]) --right;
        if (left < right)
          std::swap(nums[left], nums[right]);
      }

      std::swap(nums[partition], nums[right]);

      to_sorts.emplace_back(left_end, right - 1);
      to_sorts.emplace_back(right + 1, right_end);
    }
  }
};

int main() {
  std::vector<int> data = {3, -1};

  Solution s;
  s.sortArray(data);
  for (auto &v: data) {
    std::cout << v << ' ';
  }
  return 0;
}