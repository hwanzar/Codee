#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int reduceSum(vector<int> &nums)
{
    int cost = 0;
    // int sum = 0;
    sort(nums.begin(), nums.end());
    while (nums.size() != 1)
    {
        int sum = (nums[0] + nums[1]);
        cost += sum;
        nums.erase(nums.begin());
        nums.erase(nums.begin());
        nums.push_back(sum);
        sort(nums.begin(), nums.end());
    }
    return cost;
}

int ReducedSum(vector<int> &nums)
{
    int cost = 0;
    priority_queue<int> pq;
    for (auto x : nums)
    {
        pq.push(x);
    }
    while (pq.size() != 1)
    {
        
    }
}

int main()
{
    outtext;
    _io;
    vector<int> nums{1, 2, 3, 4};
    cout << reduceSum(nums) << endl;
    return 0;
}