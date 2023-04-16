#include <iostream>

using namespace std;

const int SIZE = 3;

class HashTable
{
private:
    int *keys;
    int *values;
    int *status; // 0: empty, 1: filled, 2: deleted
    int size;
    int hashFunc(int key)
    {
        return key % SIZE;
    }

public:
    HashTable()
    {
        size = SIZE;
        keys = new int[size];
        values = new int[size];
        status = new int[size];
        for (int i = 0; i < size; i++)
        {
            status[i] = 0;
        }
    }

    void insert(int key, int value)
    {
        int index = hashFunc(key);
        int count = 0;
        while (status[index] == 1 && keys[index] != key)
        {
            index = (index + 1) % size;
            count++;
            if (count == size)
            {
                cout << "Hash table is full" << endl;
                return;
            }
        }
        keys[index] = key;
        values[index] = value;
        status[index] = 1;
    }

    int search(int key)
    {
        int index = hashFunc(key);
        int count = 0;
        while (status[index] != 0)
        {
            if (status[index] == 1 && keys[index] == key)
            {
                return values[index];
            }
            index = (index + 1) % size;
            count++;
            if (count == size)
            {
                break;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        int index = hashFunc(key);
        int count = 0;
        while (status[index] != 0)
        {
            if (status[index] == 1 && keys[index] == key)
            {
                status[index] = 2;
                return;
            }
            index = (index + 1) % size;
            count++;
            if (count == size)
            {
                break;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            if (status[i] == 1)
            {
                cout << keys[i] << ": " << values[i] << endl;
            }
        }
    }
};

int main()
{
    HashTable ht;
    ht.insert(2, 20);
    ht.insert(3, 30);
    ht.insert(5, 50);
    ht.insert(7, 70);
    ht.display();
    cout << "Search for key 3: " << ht.search(3) << endl;
    cout << "Removing key 3..." << endl;
    ht.remove(3);
    ht.display();
    cout << "Search for key 3: " << ht.search(3) << endl;
    return 0;
}
