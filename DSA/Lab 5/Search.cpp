#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int binarySearch(int arr[], int left, int right, int x)
{
    if (left > right)
        return -1;
    int mid = (left + right) / 2;

    cout << "We traverse on index: " << mid << endl;

    if (arr[mid] == x)
        return mid;
    if (arr[mid] > x)
        return binarySearch(arr, left, mid - 1, x);
    return binarySearch(arr, mid + 1, right, x);
}

int jumpSearch(int arr[], int x, int n)
{
    int step = (int)sqrt(n);
    int curID = 0;
    while (curID < n && arr[curID] < x)
    {
        cout << curID << " ";
        curID += step;
    }
    if (arr[curID] == x)
    {
        cout << curID << " ";
        return curID;
    }
    int tmpID = curID - step + 1;
    if (curID < n)
        cout << curID << " ";
    for (int i = tmpID; i <= min(curID, n - 1); i++)
    {
        if (arr[i] > x)
            break;
        if (arr[i] == x)
        {
            cout << i << " ";
            return i;
        }
        cout << i << " ";
    }
    if (arr[n - 1] < x)
        cout << n;
    return -1;
}

int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos;
    if (left <= right && x >= arr[left] && x <= arr[right])
    {
        pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (x - arr[left]));
        // probing the position
        cout << "We traverse on index: " << pos << endl;
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, right, x);
        if (arr[pos] > x)
            return interpolationSearch(arr, left, pos - 1, x);
    }
    return -1;
}

int main()
{
    outtext;
    _io;
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int x = 3;
    // int n = sizeof(arr) / sizeof(arr[0]);
    // // int result = binarySearch(arr, 0, n - 1, x);
    // int result = interpolationSearch(arr, 0, n - 1, x);
    // (result == -1) ? cout << "Element is not present in array"
    //                : cout << "Element is present at index " << result;
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    int index = jumpSearch(arr, x, n);

    if (index != -1)
    {
        cout << "\nNumber " << x << " is at index " << index;
    }
    else
    {
        cout << "\n"
             << x << " is not in array!";
    }
    return 0;
}