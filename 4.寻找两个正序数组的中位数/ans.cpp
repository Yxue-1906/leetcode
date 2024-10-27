#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int find_in
  double find_one(vector<int> &nums1, vector<int> &nums2) {
    // when nums1.size() + nums2.size() is odd

    int to_find_idx = (nums1.size() + nums2.size()) / 2;

    int l1 = 0, r1 = nums1.size();
    int l2 = 0, r2 = nums2.size();

    while(true) {
      vector<int> &to_find_mid = (r1 - l1 > r2 - l2) ? nums1 : nums2;
      vector<int> &another = (r1 - l1 > r2 - l2) ? nums2 : nums1;
      int mid = (r1 - l1 > r2 - l2) ? ((r1 - l1) / 2) + l1 : ((r2 - l2) / 2 + l2);

      if()
    }
  }

  double find_two(vector<int> &nums1, vector<int> &nums2) {

  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> *nums_ptr;

    int left_1 = 0, right_1 = nums1.size();
    int left_2 = 0, right_2 = nums2.size();

    // 1) select longger vector
    // 2) get mid of it
    while(true) {

    }
  }
};