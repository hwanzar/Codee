// Search index position:

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        // cout << nums.size();
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= target)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int>nums;
    for(int i = 0; i < n;i++){
	    int x; cin >> x;
	    nums.push_back(x);
    }
    int tar;
    cin >> tar;
    Solution solved;
    int res = solved.searchInsert(nums,tar);
    cout << res << endl;
    return 0;
}

