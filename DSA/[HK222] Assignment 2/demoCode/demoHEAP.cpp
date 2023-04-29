#include <bits/stdc++.h>
#include "../main.h"
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define ln cout << endl;
// MIN HEAP
#include <vector>
#include <stdexcept>

class MinHeap
{
public:
    std::vector<table> heapArray;
    int capacity;
    // int recentOrder;

public:
    MinHeap(int capacity)
    {
        this->capacity = capacity;
        // this->recentOrder = recentOrder;
    }

    // Insert an element into the heap
    void insert(table tb)
    {
        if (heapArray.size() == capacity)
        {
            return;
        }

        heapArray.push_back(tb);
        // ++recentOrder;
        int index = heapArray.size() - 1;
        reheapUp(index);
    }

    // Remove and return the smallest element from the heap
    int removeMin()
    {
        if (heapArray.empty())
        {
            throw std::runtime_error("Heap underflow");
        }

        int minElement = heapArray[0].dish;
        int lastIndex = heapArray.size() - 1;
        heapArray[0] = heapArray[lastIndex];
        heapArray.pop_back();
        reheapDown(0);
        return minElement;
    }
    void remove(int pos)
    {
        int size = heapArray.size();
        if (size == 0 || pos >= size || pos < 0)
        {
            return;
        }
        swap(heapArray[pos], heapArray[size - 1]);
        heapArray.pop_back();
        reheapDown(pos);
    }

    int findIndex(const string name)
    {
        for (int i = 0; i < heapArray.size(); i++)
        {
            if (heapArray[i].name == name)
            {
                return i;
            }
        }
        return -1;
    }
    // Get the number of elements in the heap
    int size()
    {
        return heapArray.size();
    }

public:
    // Reheap Up
    void reheapUp(int pos)
    {
        if (pos <= 0)
            return;
        int parent = (pos - 1) / 2;
        if ((pos > 0 && heapArray[pos].dish < heapArray[parent].dish) || (heapArray[pos].dish == heapArray[parent].dish && heapArray[pos].recentOrder < heapArray[parent].recentOrder))
        {
            swap(heapArray[pos], heapArray[parent]);
            reheapUp(parent);
        }
        else
            return;
    }

    // Reheap Down
    void reheapDown(int pos)
    {
        int leftPos = 2 * pos + 1;
        int rightPos = 2 * pos + 2;
        if (leftPos >= heapArray.size() || pos >= heapArray.size())
            return;

        if (leftPos >= heapArray.size())
            leftPos = -1;
        if (rightPos >= heapArray.size())
            rightPos = -1;

        int smallestPos = 0;
        if (rightPos == -1)
        {
            smallestPos = leftPos;
        }
        else
        {
            if (heapArray[leftPos].dish < heapArray[rightPos].dish)
            {
                smallestPos = leftPos;
            }
            else if (heapArray[leftPos].dish == heapArray[rightPos].dish)
            {
                if (heapArray[leftPos].recentOrder < heapArray[rightPos].recentOrder)
                {
                    smallestPos = leftPos;
                }
                else
                {
                    smallestPos = rightPos;
                }
            }
            else
            {
                smallestPos = rightPos;
            }
        }
        if (heapArray[smallestPos].dish < heapArray[pos].dish || (heapArray[smallestPos].dish == heapArray[pos].dish && heapArray[smallestPos].recentOrder < heapArray[pos].recentOrder))
        {
            swap(heapArray[pos], heapArray[smallestPos]);
            reheapDown(smallestPos);
        }
        else
            return;
    }
    void printPreOrderHelper(int index)
    {
        if (index >= heapArray.size())
        {
            return;
        }

        // cout << index << ": " << heapArray[index].id << "-" << heapArray[index].dish << "-" << heapArray[index].recentOrder << "\n";
        cout << heapArray[index].id << "-" << heapArray[index].dish << "\n";
        printPreOrderHelper(2 * index + 1);
        printPreOrderHelper(2 * index + 2);
    }
    void printPreOrder()
    {
        if (heapArray.empty())
        {
            std::cout << "Empty heap" << std::endl;
            return;
        }

        // std::cout << 0 << ": " << heapArray[0].id << "-" << heapArray[0].dish << "-" << heapArray[0].recentOrder << "\n";
        cout << heapArray[0].id << "-" << heapArray[0].dish << "\n";
        printPreOrderHelper(1);
        printPreOrderHelper(2);
        // std::cout << std::endl;
    }
};

// int main()
// {

//     int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
//     vector<int> a{7, 6, 8, 5, 4, 3, 2, 1};
//     MinHeap lfco = MinHeap(10);
//     table tb = table(27, "GIA", 20698, 1, 5, 0);

//     lfco.insert(tb);
//     table tb2 = table(23, "gia", 20698, 1, 1, 0);
//     lfco.insert(tb2);
//     // lfco.remove(0);
//     lfco.printPreOrder();

//     return 0;
// }