// C++ program to demonstrate the use
// of string::npos
#include <bits/stdc++.h>
using namespace std;

string getCommand(string input)
{
    size_t pos = input.find(" ");
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
string getNum(string inp)
{
    string tempInp = inp;
    size_t pos = tempInp.find_last_of(" ");
    if (pos != string::npos)
    {
        tempInp = tempInp.substr(pos + 1);
    }
    string result = "";
    try
    {
        result = to_string(stoi(tempInp));
    }
    catch (const std::invalid_argument &e)
    {
        // handle the exception here
        result = "invalid number";
    }
    return result;
}

int main()
{
    string line = "CLE -";

    string command = getCommand(line);
    if (command == "CLE")
    {
        cout << command << endl;
    }
    else
    {
        cout << "Sai";
    }
    string num = getNum(line);
    // if (num == "")
    // {
    //     cout << "empty";
    // }
    cout << num << endl;
}
