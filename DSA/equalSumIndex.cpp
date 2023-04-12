#include <bits/stdc++.h>
using namespace std;

int equalSumIndex(vector<int> &nums) {
  int sum = 0;
  sum = accumulate(nums.begin(), nums.end(), sum);
  cout << sum << endl;
  if (nums.size() == 2 || nums.size() == 0) {
    return -1;
  }
  if (nums.size() == 1) {
    return 0;
  }
  int LS = -1, RS = -1;
  for (int i = 1; i < (int)nums.size() - 1; i++) {
    if (LS == -1) {
      LS = nums[i - 1];
      RS = sum - LS - nums[i];
    } else {
      LS += nums[i - 1];
      RS -= nums[i];
    }
    if (LS == RS)
      return i;
  }
  return -1;
}

int main() {
  vector<int> nums{3, 5, 2, 7, 6, 4};
  cout << equalSumIndex(nums);
}
