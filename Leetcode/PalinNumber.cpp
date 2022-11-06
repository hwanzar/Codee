#include <bits/stdc++.h>
using namespace std;

bool Palindrome(int x)
{
    int old = x;
    int reverse = 0;
    if (old < 0)
        return false;
    while (x != 0)
    {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }
    // cout << reverse << endl;
    if (reverse == old)
    {

        return true;
    }
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    cout << Palindrome(n);
    return 0;
}