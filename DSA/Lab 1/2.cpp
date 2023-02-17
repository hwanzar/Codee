#include <bits/stdc++.h>
using namespace std;

int Rev(float n, float curr)
{
    if (n == 1)
        return curr - 1;
    if (n < 1)
        return -1;
    n /= curr;
    curr++;
    return Rev(n, curr);
}

int reverseFactorial(int n)
{
    if (n == 1)
    {
        return 0;
    }
    float curr = 1;
    return Rev((float)n, curr);
}

int main() { cout << reverseFactorial(120); }
