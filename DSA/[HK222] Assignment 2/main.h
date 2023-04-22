#ifndef MAIN_H
#define MAIN_H
#include <bits/stdc++.h>
#include <string>

using namespace std;
#define MAXSIZE 32

class table
{
    // node for table in the restaurant;
    // store the id, name, result, decimal name, dish

public:
    int id;
    string name;
    int result;
    int dish;
    table(int id, string name, int result, int dish)
    {
        this->id = id;
        this->name = name;
        this->result = result;
        this->dish = dish;
    }
};
#endif