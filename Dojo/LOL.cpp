#include <bits/stdc++.h>
using namespace std;

std::string disemvowel(const std::string &str)
{
    // return
    std::string new_str = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'u' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o')
        {
            continue;
        }
        else if (str[i] == 'A' || str[i] == 'O' || str[i] == 'U' || str[i] == 'I' || str[i] == 'E')
        {
            continue;
        }
        else
        {
            new_str += str[i];
        }
    }
    return new_str;
}

int main()
{
    string LOL = "This website is for losers, LOL!";
    string new_string = disemvowel(LOL);
    cout << "run" << endl;
    cout << new_string << " runned";
    return 0;
}