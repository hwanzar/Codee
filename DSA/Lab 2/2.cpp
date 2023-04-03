#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &arr)
{
    int i = 0;
    vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        res.push_back(-1);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] > arr[i])
            {
                res[i] = arr[j];
                break;
            }
        }
    }
    return res;
}
int main()
{

    cout << "debug" << endl;
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    vector<int> greaterNums = nextGreater(nums);
    for (int i : greaterNums)
        cout << i << ' ';
    cout << '\n';
    return 0;
}