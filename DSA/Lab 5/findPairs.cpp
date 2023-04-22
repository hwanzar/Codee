#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#include <unordered_map>

#define intpair pair<int, int>

bool findPairs(int arr[], int n, pair<int, int> &pair1, pair<int, int> &pair2)
{
    unordered_map<int, vector<pair<int, int>>> map;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            if (map.find(sum) != map.end())
            {
                for (auto pair : map.find(sum)->second)
                {
                    int m = pair.first, n = pair.second;
                    if (m != i && m != j && n != i && n != j)
                    {
                        pair1.first = arr[i];
                        pair1.second = arr[j];
                        pair2.first = arr[m];
                        pair2.second = arr[n];
                        return true;
                    }
                                }
            }
            map[sum].push_back({i, j});
        }
    }
    return false;
}

int main()
{
    outtext;
    _io;

    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n = sizeof arr / sizeof arr[0];
    pair<int, int> pair1, pair2;
    if (findPairs(arr, n, pair1, pair2))
    {
        if (checkAnswer(arr, n, pair1, pair2))
        {
            printf("Your answer is correct.\n");
        }
        else
            printf("Your answer is incorrect.\n");
    }
    else
        printf("No pair found.\n");
    return 0;
}