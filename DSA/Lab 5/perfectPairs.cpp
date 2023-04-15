// exercise 3 from lab
#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int pairMatching(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int i = 0, j = nums.size() - 1;
    int cnt = 0;

    // cout << "\nInit vector" << endl;
    // for (auto x : nums)
    // {
    //     cout << x << " ";
    // }
    // cout << '\n';

    while (i < j)
    {
        if ((nums[i] + nums[j]) < target)
        {
            i++;
        }
        else if ((nums[i] + nums[j]) > target)
        {
            j--;
        }
        else
        {
            cnt++;
            i++;
            j--;
        }
    }

    // for (auto x : nums)
    // {
    //     cout << x << " ";
    // }
    // cout << "\nResult" << endl;
    return cnt;
}
int main()
{
    outtext;
    _io;
    vector<int> items{1, 3, 5, 3, 7};
    int target = 6;
    cout << pairMatching(items, target);
    return 0;
}