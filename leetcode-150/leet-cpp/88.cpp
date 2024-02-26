// C++ template for LeetCode problems

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Function signature might vary depending on the problem
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        cout << "Hello\n";
        int p = m + n - 1;
        int p1 = m - 1;
        int p2 = n - 1;
        while (p2 >= 0)
        {
            if (p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[p--] = nums1[p1--];
            }
            else
            {
                nums1[p--] = nums2[p2--];
            }
        }
        for (auto x : nums1)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution solution;
    // Test your solution
    vector<int> nums1 = {2, 4, 6, 0, 0, 0};

    vector<int> nums2 = {1, 2, 3};
    solution.merge(nums1, 3, nums2, 3);
    return 0;
}