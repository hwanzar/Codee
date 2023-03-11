#include <iostream>
#include <string>
#include <bits/stdc++.h>
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

string getName(string line)
{
    int pos;
    cout << line << endl;
    if (line.substr(0, 3) == "REG")
    {
        int id = getIDNumber(line);
        pos = line.find(" ");
        if (id < 0)
        {
            line = line.substr(pos + 1);
            cout << id << " " << line << endl;
            pos = line.find(" ");
            line = line.substr(0, pos);
        }
        else
        {
            line = line.substr(pos + 1);
            cout << line << endl;
            pos = line.find(" ");
            line = line.substr(pos + 1);
            pos = line.find(" ");
            line = line.substr(0, pos);
        }
    }

    return line;
}

// int getAge(string line)
// {
//     // Split the line into tokens
//     stringstream ss(line);
//     string token;
//     vector<string> tokens;
//     while (ss >> token)
//     {
//         tokens.push_back(token);
//     }

//     // Extract the last token as the age
//     int age = stoi(tokens.back());
//     return age;
// }
int getAge(string line)
{
    string ageString;
    int age = 0;
    bool foundAge = false;

    // Iterate over the characters in the line string
    for (char c : line)
    {
        if (isdigit(c))
        {
            // If the character is a digit, append it to the age string
            ageString += c;
            foundAge = true;
        }
        else if (foundAge)
        {
            // If we have already found the age and encounter a non-digit character, break the loop
            break;
        }
    }

    // Convert the age string to an integer
    if (!ageString.empty())
    {
        age = stoi(ageString);
    }

    return age;
}

// string getName(string line)
// {
//     // Find the position of the second space character
//     int pos = line.find(" ", line.find(" ") + 1);
//     // Extract the substring after the second space
//     string name = line.substr(pos + 1);
//     return name;
// }

template <class E>
class DLL
{
public:
    class Node
    {
    public:
        E data;
        Node *prev;
        Node *next;
        Node(const E &data = E{}, Node *next = nullptr, Node *prev = nullptr) : data(data), next(next), prev(prev) {}
    };

public:
    Node *head;
    Node *tail;
    int cnt;

    DLL() : head(NULL), tail(NULL), cnt(0) {}
    ~DLL()
    {
        clear();
    }

    void add(const E &value)
    {
        if (cnt == 0)
        {
            Node *node = new Node(value);
            head = node;
            tail = node;
            tail->next = nullptr;
            cnt++;
            return;
        }
        Node *node = new Node(value);
        node->prev = tail;
        tail->next = node;
        node->next = nullptr;
        tail = node;
        cnt++;
        return;
    }
    void add(int index, const E &e)
    {
        if (index < 0 || index > cnt)
        {
            throw out_of_range("Index out of range");
        }

        if (cnt == 0)
        {
            add(e);
            return;
        }
        if (index == 0)
        {
            Node *node = new Node(e);
            node->next = head;
            head->prev = node;
            head = node;
            cnt++;
            return;
        }
        if (index == cnt)
        {
            add(e);
            return;
        }
        Node *cur = head;
        for (int i = 0; i < index; i++)
        {
            cur = cur->next;
        }
        // add node
        Node *addNode = new Node(e, cur->prev, cur);
        cur->prev->next = addNode;
        cur->prev = addNode;
        cnt++;
    }
    int size() { return cnt; }
    bool empty()
    {
        return cnt == 0;
    }
    void clear()
    {
        Node *current = head;
        while (current != tail)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head->next = tail;
        tail->prev = head;
        cnt = 0;
    }
    E removeAt(int index)
    {
        if (cnt == 0 || index < 0 || index >= cnt)
        {
            throw std::out_of_range("Invalid index");
        }
        Node *cur = head;
        Node *prev = nullptr;

        for (int i = 0; i < index; i++)
        {
            prev = cur;
            cur = cur->next;
        }
        E res = cur->data;
        // now delete
        if (prev == nullptr)
        {
            head = head->next;
            head->previous = nullptr;
        }
        else if (cur->next == nullptr)
        {
            prev->next = nullptr;
            tail = prev;
        }
        else
        {
            prev->next = cur->next;
            (cur->next)->previous = prev;
        }
        delete cur;
        cnt--;
        return res;
    }
    void debug_DLL()
    {
        cout << "[";
        if (head != nullptr)
        {
            cout << head->data;
            Node *current = head->next;
            while (current != nullptr)
            {
                cout << "," << current->data;
                current = current->next;
            }
        }
        cout << "]" << endl;
    }
};

int main()
{
    string input1 = "REG 1 Gia 19";
    string input2 = "REG Gia 115";

    DLL<int> list;
    list.add(1);
    list.add(1, 3);
    list.debug_DLL();
    int id1 = getIDNumber(input1);
    int id2 = getIDNumber(input2);

    cout << "ID number for input1: " << id1 << endl;
    cout << "ID number for input2: " << id2 << endl;

    return 0;
}
// int main()
// {
//     // Example usage

//     string line = "REG 2 Nam 10";
//     string name = getName(line);
//     int age = getAge(line);
//     cout << name << endl; // Output: Nam
//     cout << age << endl;
//     return 0;
// }
