//
// Created by unrelated on 24-10-20.
//



#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
  vector<vector<int>> threeSum(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    vector<int> sorted_nums;
    vector<int> freq;
    sorted_nums.reserve(nums.size());
    freq.reserve(nums.size());
    for (auto num: nums) {
      if (sorted_nums.empty() || sorted_nums.back() != num) {
        sorted_nums.push_back(num);
        freq.emplace_back(0);
      }
      freq.back()++;
    }

    for (size_t i = 0; i < sorted_nums.size(); ++i) {
      
    }
  }
};