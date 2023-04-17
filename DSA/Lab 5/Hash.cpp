#include <bits/stdc++.h>
#include <string>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int foldShift(long long key, int addressSize)
{
    string keyStr = to_string(key);
    int size = (int)(keyStr.length() / addressSize) + 1;
    string ans[size];
    int k = 0;
    for (int i = 0; i < keyStr.length(); i++)
    {
        if (i == (k + 1) * addressSize)
            k++;
        ans[k] += keyStr[i];
    }
    int result = 0;
    for (int i = 0; i <= k; i++)
    {
        result += (stoi(ans[i]) % (long long int)pow(10, addressSize));
    }
    result %= (long long int)pow(10, addressSize);
    return result;
}

int rotation(long long key, int addressSize)
{
    string keyStr = to_string(key);
    int size = keyStr.length();

    string res = keyStr.substr(size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        res += keyStr[i];
    }
    long long int result = (long long int)stol(res);
    // cout << res << endl;
    return foldShift(result, addressSize);
}

long int midSquare(long int seed)
{
    long long square = seed * seed;

    string sqrStr = to_string(square);
    int size = sqrStr.length();
    sqrStr = sqrStr.substr(2, size);

    size = sqrStr.length();
    string ans = sqrStr.substr(0, size - 2);
    return stol(ans);
}

long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}

long int digitExtraction(long int seed, int *extractDigits, int size)
{
    string digits = to_string(seed);
    string ans = "";
    for (int i = 0; i < size; i++)
    {
        ans += digits[extractDigits[i]];
    }
    return stol(ans);
}

int main()
{
    outtext;
    _io;
    cout << foldShift(600101, 2);
    cout << rotation(600101, 2) << endl;
    cout << rotation(1234567891234, 5);
    cout << endl;
    cout << midSquare(9452);
    cout << endl;
    int a[] = {1, 2, 5};
    cout << digitExtraction(122443, a, 3);
    return 0;
}