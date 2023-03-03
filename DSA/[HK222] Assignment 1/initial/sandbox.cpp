#include <iostream>
#include <string>
using namespace std;

int getIDNumber(string input)
{
    string command = input.substr(0, 3); // extract first 3 characters
    if (command == "REG" || command == "CLE")
    {                                     // check if command is "REG" or "CLE"
        int start = 4;                    // start index of ID number
        int end = input.find(' ', start); // find first space after start index
        if (end == string::npos)
        {                // check if space not found
            return -100; // no ID number found, return -100
        }
        string id_str = input.substr(start, end - start); // extract ID number as string
        // cout << id_str;
        return (id_str[0] <= '9' && id_str[0] >= '0') ? stoi(id_str) : -100; // convert ID number to integer and return
    }
    else
    {
        return -100; // not a valid command, return -100
    }
}

int main()
{
    string input1 = "REG 1 Gia 19";
    string input2 = "REG Gia 115";

    int id1 = getIDNumber(input1);
    int id2 = getIDNumber(input2);

    cout << "ID number for input1: " << id1 << endl;
    cout << "ID number for input2: " << id2 << endl;

    return 0;
}
