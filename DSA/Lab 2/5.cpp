#include <bits/stdc++.h>
using namespace std;

string deleteDuplicate(string s, int k)
{
    stack<char> checkDup;
    int cnt[256] = {0};
    for (char c : s)
    {
        if (!checkDup.empty() && checkDup.top() == c && cnt[c] == k - 1)
        {
            for (int i = 0; i < k - 1; i++)
            {
                checkDup.pop();
            }
            cnt[c] = 0;
        }
        else
        {
            checkDup.push(c);
            cnt[c]++;
        }
    }
    string res = "";
    while (!checkDup.empty())
    {
        res += checkDup.top();
        checkDup.pop();
    }
    res = string(res.rbegin(), res.rend());
    return res;
}

int main()
{
    string s = "aaabbbbccddddefffghiiiiihhhhggggffda";
    int k = 5;
    cout << deleteDuplicate(s, k);
}