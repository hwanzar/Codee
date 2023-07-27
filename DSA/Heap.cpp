#include <bits/stdc++.h>
using namespace std;

template <class T>
class Heap
{
protected:
    T *elements;
    int capacity;
    int count;

public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[] elements;
    }
    void push(T item)
    {
        ensureCapacity(count + 1);
        elements[count] = item;
        count++;
        reheapUp(count - 1);
    }
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }

private:
    void ensureCapacity(int minCapacity)
    {
        if (capacity >= minCapacity)
            return;
        T *newElements = new T[minCapacity];
        for (int i = 0; i < count; i++)
        {
            newElements[i] = elements[i];
        }
        delete elements;
        elements = newElements;
    }
    void reheapUp(int position)
    {
        int parent = (position - 1) / 2;
        if (position > 0 && elements[parent] <= elements[position])
        {
            swap(elements[position], elements[parent]);
            reheapUp(parent);
        }
    }
    void reheapDown(int position)
    {
        int leftChild = 2 * position + 1;
        int rightChild = 2 * position + 2;
        int largest = position;
        if (leftChild < count && elements[leftChild] > elements[largest])
        {
            largest = leftChild;
        }
        if (rightChild < count && elements[rightChild] > elements[largest])
        {
            largest = rightChild;
        }
        if (largest != position)
        {
            swap(elements[largest], elements[position]);
            reheapDown(largest);
        }
    }
};

int main()
{
    Heap<int> maxHeap;
    for (int i = 0; i < 5; i++)
    {
        maxHeap.push(i);
    }
    maxHeap.printHeap();
}
