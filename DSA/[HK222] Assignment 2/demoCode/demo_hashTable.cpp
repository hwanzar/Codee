#include <iostream>
#include <bits/stdc++.h>
#include "../main.h"
using namespace std;

class HashTable
{
public:
    map<int, table> hashTable;
    int tableCnt;
    HashTable()
    {
        for (int i = 0; i < MAXSIZE / 2; i++)
        {
            hashTable[i] = table(0, "", 0, 0);
        }
        tableCnt = 0;
    }
    int hashFx(int res)
    {
        return res % (MAXSIZE / 2);
    }

public:
    void insert(int key, table tb)
    {
        int newkey = hashFx(key);

        while (hashTable[newkey].name != "")
        {
            newkey = (newkey == MAXSIZE - 1) ? 0 : (newkey + 1) % (MAXSIZE / 2);
            // newkey = (newkey + 1) % (MAXSIZE / 2);
        }
        hashTable[newkey] = tb;
        tableCnt++;
    }
    void remove(int id)
    {
        int key = hashFx(id);

        while (hashTable[key].id != id && hashTable[key].name != "")
        {
            key = (key == MAXSIZE - 1) ? 0 : (key + 1) % (MAXSIZE / 2);
        }

        if (hashTable[key].id == id)
        {
            // Remove the table object from the hash table
            // delete hashTable[key];
            hashTable[key] = table(0, "", 0, 0);
            tableCnt--;
        }
    }

    void display()
    {
        cout << "==== AREA 1 - HASH TABLE ====\n";
        for (auto pair : hashTable)
        {
            cout << pair.first << " " << pair.second.id << ": " << pair.second.result << endl;
        }
        cout << "=============================\n";
    }
    bool isFull()
    {
        if (tableCnt == hashTable.size())
            return true;
        return false;
    }
    bool containsID(int ID)
    {
        if (ID == 0)
            return false;
        for (int key = 0; key < MAXSIZE / 2; key++)
        {

            if (hashTable[key].id == ID)
            {
                return true;
            }
        }
        return false;
    }
};

// int main()
// {

//     HashTable hashtb;
//     int i = 2;
//     table *tb = new table(i + 100, "GIA", 123, 2);
//     hashtb.insert(tb->id, tb);
//     table *tb2 = new table(i * 15 + 1, "gia", 123, 2);
//     hashtb.insert(tb2->id, tb2);
//     table *tb3 = new table(i * 15 + 1, "gia", 123, 2);
//     hashtb.insert(tb3->id, tb3);
//     hashtb.display();
//     return 0;
// }
