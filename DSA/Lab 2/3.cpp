#include <iostream>
#include <stack>
#include <vector>
// #include "1.cpp"
using namespace std;

string reverseSubstr(string str, int &start, int &end)
{
    string subStr = str.substr(start, end - start + 1);
    subStr = string(subStr.rbegin(), subStr.rend());
    return subStr;
}

string parenthesesReversal(string s)
{
    // STUDENT ANSWER
    stack<int> checkBrackets;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            checkBrackets.push(i);
            // checkBrackets.push(i);
        }
        if (s[i] == ')')
        {
            int start = checkBrackets.top() + 1;
            int end = i - 1;
            checkBrackets.pop();
            string res = reverseSubstr(s, start, end);
            s.replace(start, end - start + 1, res);
        }
    }
    /// remove ()

    string ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            continue;
        }
        else
        {
            ans += s[i];
        }
    }
    // cout << ans << endl;
    return ans;
}

int main()
{
    cout << "debug" << endl;
    string s = "(ab(cd)ef)";
    cout << parenthesesReversal(s);
}