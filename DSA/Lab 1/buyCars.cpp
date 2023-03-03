#include <bits/stdc++.h>

using namespace std;

int buyCar(int *nums, int length, int k)
{
    int sum = 0;
    int idx = 0;
    sort(nums, nums + length);

    for (int i = 0; i < length; i++)
    {

        if (sum >= k)
            break;
        else
        {
            sum += nums[i];
            idx++;
        }
        cout << sum << '\n';
    }
    return idx;
}

int main()
{
    int nums[] = {90, 30, 40, 90, 20};
    int length = sizeof(nums) / sizeof(nums[0]);
    cout << buyCar(nums, length, 90) << "\n";}