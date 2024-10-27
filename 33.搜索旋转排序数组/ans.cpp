#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    // find k

    int left = 0, right = nums.size();
    int k;
    while(true) {
      if(right - left < 2) {
        k = left;
        break;
      }
      k = (right - left) / 2 + left;

      if(nums[k] >= nums[0]) {
        left = k + 1;
      } else {
        right = k + 1;
      }
    }

    // binary search
    left = 0, right = k;
    int mid;
    while(true) {
      if(right - left < 2) {
        if(nums[mid] == target) return mid;
        else break;
      }
      mid = (right - left) / 2 + left;

      if(nums[mid] == target) return mid;
      if(nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    while(true) {
      if(right - left < 2) {
        if(nums[mid] == target) return mid;
        else break;
      }
      mid = (right - left) / 2 + left;

      if(nums[mid] == target) return mid;
      if(nums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return -1;
  }
};

int main() {
  vector<int> data = {4,5,6,7,0,1,2};
  int target = 0;

  Solution s;

  std::cout << s.search(data, target) << std::endl;

  return 0;
}