#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ln cout << endl;
// MIN HEAP

void reHeapUp(vector<int> &hp, int pos)
{
    if (pos < 0)
        return;
    int parent = (pos - 1) / 2;
    if (pos > 0 && hp[pos] < hp[parent])
    {
        swap(hp[pos], hp[parent]);
        reHeapUp(hp, parent);
    }
}
void reHeapDown(vector<int> &hp, int pos)
{
    int leftPos = 2 * pos + 1;
    int rightPos = 2 * pos + 2;
    int smallestPos = pos;

    if (leftPos < hp.size() && hp[leftPos] < hp[pos])
        smallestPos = leftPos;
    if (rightPos < hp.size() && hp[rightPos] < hp[pos])
        smallestPos = rightPos;

    if (smallestPos != pos)
    {
        swap(hp[pos], hp[smallestPos]);
        reHeapDown(hp, smallestPos);
    }
}

int main()
{

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    vector<int> a{7, 6, 8, 5, 4, 3, 2, 1};
    for (int i = 0; i < a.size(); i++)
    {
        reHeapUp(a, i);
    }
    // for (int i = 0; i < a.size(); i++)
    // {
    //     reHeapDown(a, i);
    // }

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}