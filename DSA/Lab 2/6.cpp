#include <bits/stdc++.h>
using namespace std;

int sumOfMinSubarray(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    int MOD = 10000;
    vector<int> left(n), right(n);

    // for every i find the Next smaller element to left and right

    // Left
    stack<int> st;
    st.push(0);
    left[0] = 1; // distance = 1, left not found, this is distance multiplied with num, so it can't be zero
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && nums[i] < nums[st.top()])
            st.pop();

        if (st.empty())
            left[i] = i + 1; // total distance if less element not found = i+1
        else
            left[i] = i - st.top(); // distance = i-st.top()

        st.push(i);
    }

    while (st.size())
        st.pop();

    // Right
    st.push(n - 1);
    right[n - 1] = 1; // distance = 1, right not found, this is distance multiplied with num, so it can't be zero
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && nums[i] <= nums[st.top()])
            st.pop();

        if (st.empty())
            right[i] = n - i; // distance
        else
            right[i] = st.top() - i;

        st.push(i);
    }

    // total number of subarrays : (Left[i] * Right[i])
    // total contribution in A[i] element in final answer : (Left * Right) * A[i]

    // for each i, contribution is (Left * Right) * Element

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        long long prod = (left[i] * right[i]) % MOD;
        prod = (prod * nums[i]) % MOD;
        res = (res + prod) % MOD;
    }

    return res % MOD;
}

int main()
{
    vector<int> nums{1, 2, 4, 3};
    cout << sumOfMinSubarray(nums);
}