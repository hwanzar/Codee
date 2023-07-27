#include <bits/stdc++.h>
using namespace std;

bool isValidParentheses(string s)
{
    stack<char> bracket;
    for (char c : s)
    {
        if (c == '{' || c == '(' || c == '[')
        {
            bracket.push(c);
        }
        else if (c == '}')
        {
            if (bracket.empty() || bracket.top() != '{')
                return false;
            bracket.pop();
        }
        else if (c == ']')
        {
            if (bracket.empty() || bracket.top() != '[')
                return false;
            bracket.pop();
        }
        else
        {
            if (bracket.empty() || bracket.top() != '(')
                return false;
            bracket.pop();
        }
    }
    return bracket.empty();
}

string reverse(string s, int &start, int &end){
    string sub = s.substr(start, end - start + 1);
    sub = string(sub.rbegin(), sub.rend());
    return sub;
}
string parenthesesReversal(string s){
    stack<int> stk;
    int size = s.length();
    for(int i = 0; i < size; i++){
        if(s[i] == '('){
            stk.push(i);
        }
        if(s[i] == ')'){
            int start = stk.top() + 1;
            int end = i - 1;
            stk.pop();
            string rev = reverse(s, start, end);
            s.replace(start, end - start + 1, rev);
        }
    }
    string ans = "";
    for(int i = 0; i < size; i++){
        if(s[i] == '(' || s[i] == ')'){
            continue;
        }
        else{
            ans += s[i];
        }
    }
    return ans;
}


int main()
{
}