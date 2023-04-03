#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string S)
{
    stack<char> checkDup;
    for (char c : S)
    {
        if (!checkDup.empty() && checkDup.top() == c)
        {
            checkDup.pop();
        }
        else
        {
            checkDup.push(c);
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
    cout << removeDuplicates("abbaca");
    cout << endl;
    cout << removeDuplicates("aab");

    return 0;
}