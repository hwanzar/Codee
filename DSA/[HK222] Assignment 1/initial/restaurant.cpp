#include "main.h"
string filtCommand(string filename)
{
    string command;
    int idx = 0;
    while (idx < filename.size() && isspace(filename[idx]))
    {
        idx++;
    }
    while (idx < filename.size() && isspace(filename[idx]) == 0)
    {
        command += filename[idx];
        idx++;
    }
    return command;
}

int getID(string input)
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

void reg(string command)
{
    int id = getID(command);
    cout << id << endl;
    if(id != -100) 
    return;
}

void simulate(string filename, restaurant *r)
{
    ifstream file(filename);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << filtCommand(line) << endl;
            // function reg
            // function reg,....
            if (filtCommand(line) == "REG")
            {
                reg(line);
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}
