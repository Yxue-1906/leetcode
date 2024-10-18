//
// Created by unrelated on 24-10-16.
//

#include <iostream>
#include <vector>

class Solution {
 public:
  int findKthLargest(std::vector<int> &nums, int k) {
    size_t left = 0;
    size_t right = nums.size();

    size_t idx1 = left;
    size_t idx2 = left;
    while (true) {
      while (idx2 < right) {
        if (nums[idx2] > nums[idx1]) {
          std::swap(nums[idx1++], nums[idx2]);
          std::swap(nums[idx1], nums[idx2]);
        }
        idx2++;
      }
      if (idx1 - left + 1 == k) {
        return nums[idx1];
      } else if (idx1 - left + 1 < k) {
        k -= idx1 - left + 1;
        left = idx1 + 1;
      } else {
        right = idx1;
      }
      idx1 = left;
      idx2 = left;
    }
  }
};

int main() {
  std::vector<int> nums = {2,1};

  Solution s;
  std::cout << s.findKthLargest(nums, 2) << std::endl;
}