#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        bool flag = false;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] == nums[j])
                {
                    flag = true;
                }
            }
        }
        return flag;
    }
};

class Solution2
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
int main()
{
    vector<int> numbers;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        numbers.push_back(inp);
    }

    Solution2 solved;

    cout << solved.containsDuplicate(numbers) << endl;
}