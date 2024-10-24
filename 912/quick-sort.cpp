//
// Created by unrelated on 24-10-17.
//

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    // 三路排序？

    queue<pair<int, int>> ranges;
    ranges.push({0, nums.size()});
    while(!ranges.empty()) {
      auto [l, r] = ranges.front();
      ranges.pop();

      if(r - l < 2) continue;

      auto partition = nums[l];

      size_t i, j, k;
      i = j = l;
      k = r;
      while(i < k){
        if(nums[i] < partition) {
          std::swap(nums[i++], nums[j++]);
        } else if(nums[i] > partition) {
          std::swap(nums[i], nums[--k]);
        } else {
          ++i;
        }
      }

      ranges.push({l, j});
      ranges.push({k, r});
    }

    return std::move(nums);
  }
};

int main() {
  std::vector<int> data = {-4,0,7,4,9,-5,-1,0,-7,-1};

  Solution s;
  for (auto &v: s.sortArray(data)) {
    std::cout << v << ' ';
  }
  return 0;
}