### Notes

##### Misc
- always use signed integer, otherwise it is easy overflow to huge integer 
    and cause overflow when use it as array index

##### Binary Search
- use left close right open range \[left, right)
- add special judges on occasions that mid should be included in the sub range
  - for example: find the last index in an ascending array which is not larger than m;
    * if nums\[mid] <= m: ans should be in \[mid, right)
    * if nums\[mid] > m: ans should be in \[left, mid)
  - as you can see, on occasion 1) if mid == left, the range is the same as before
  - so we should add special judge here
``` c++
if(mid == left) {
  -- right;
} else {
  left = mid;
}
```