#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// code for HEAP
#define SEPARATOR "#<ab@17943918#@>#"
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

    bool isEmpty()
    {
        return count == 0;
    }
    bool contains(T item)
    {
        if (count == 0)
            return false;
        for (int i = 0; i < count; i++)
        {
            if (elements[i] == item)
                return true;
        }
        return false;
    }
    T peek()
    {
        return elements[0];
    }
    bool pop()
    {
        // popo the last element in the array.
        if (isEmpty())
            return false;
        elements[0] = elements[--count];
        int index = 0;
        reheapDown(index); // reheap at head.
        return true;
    }
    int size()
    {
        return count;
    }

    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }

public:
    void ensureCapacity(int minCapacity)
    {
        if (minCapacity >= capacity)
        {
            int tmp_capacity = capacity;
            capacity = tmp_capacity + (tmp_capacity >> 2);
            try
            {
                T *new_elements = new T[capacity];
                memcpy(new_elements, elements, tmp_capacity * sizeof(T));
                delete[] elements;
                elements = new_elements;
            }
            catch (std::bad_alloc error)
            {
                error.what();
            }
        }
    }
    void reheapUp(int position)
    {
        if (position < 0)
            return;
        int parent = (position - 1) / 2;
        if (position > 0 && this->elements[position] >= this->elements[parent])
        {
            swap(this->elements[position], this->elements[parent]);

            reheapUp(parent);
        }
    }
    void reheapDown(int position)
    {
        int leftEle = 2 * position + 1;
        int rightEle = 2 * position + 2;
        int largest = position;

        if (leftEle < count && elements[leftEle] > elements[largest])
            largest = leftEle;
        if (rightEle < count && elements[rightEle] > elements[largest])
            largest = rightEle;
        if (largest != position)
        {
            swap(elements[largest], elements[position]);
            reheapDown(largest);
        }
    }
};

// Your code goes here
#define nnn cout << endl
int main()
{
    outtext;
    _io;
    Heap<int> maxHeap;
    for (int i = 0; i < 10; i++)
    {
        maxHeap.push(i);
    }
    cout << maxHeap.size() << endl;
    nnn;
    maxHeap.printHeap();
    nnn;

    return 0;
}