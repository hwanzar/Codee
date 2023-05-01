// C++ program to demonstrate the use
// of string::npos
#include <bits/stdc++.h>
using namespace std;

string getCommand(string input)
{
    int pos = input.find(" ");
    if (pos == string::npos)
        return "invalid command";
    string command = input.substr(0, pos);
    return command;
}

string getName(string input)
{

    // string command = getCommand(input);
    int pos = input.find(" ");
    if (pos == string::npos)
    {
        return "invalid name";
    }
    string name = input.substr(pos + 1);

    string ans = "";
    for (int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]))
        {
            return "invalid name";
        }
        ans += name[i];
    }
    return ans;
}

int main()
{
    string line = "REG88 GIA";
    string command = getCommand(line);
    cout << command << endl;
    string name = getName(line);
    cout << name << endl;
}
