#include <iostream>
#include <stack>
#include <string>
using namespace std;
string reverseStr(string str, int &start, int &end)
{
    string subStr = str.substr(start, end - start + 1);
    subStr = string(subStr.rbegin(), subStr.rend());
    return subStr;
}

string parenthesesReversal(string s)
{
    stack<int> bracketIdx;
    int size = s.length();
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(')
        {
            bracketIdx.push(i);
        }
        if (s[i] == ')')
        {
            int start = bracketIdx.top() + 1;
            int end = i - 1;
            bracketIdx.pop();
            string replaceStr = reverseStr(s, start, end);
            s.replace(start, end - start + 1, replaceStr);
        }
    }
    string ans = "";
    for (int i = 0; i < size; i++)
    {
        if (s[i] == '(' || s[i] == ')')
        {
            // ans += s[i];
            continue;
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}
int main()
{
    string s = "vi(ik)kq";
    cout << parenthesesReversal(s);
}