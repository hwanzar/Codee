#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Heap class
template <typename E, typename Comp>
class heap
{
private:
    E *Heap;
    int maxsize;
    int n;

    void siftdown(int pos)
    {
        while (!isLeaf(pos))
        {
            int j = leftChild(pos);
            int rc = rightChild(pos);
            if ((rc < n) && Comp::prior(Heap[rc], Heap[j]))
                j = rc;
            if (Comp::prior(Heap[j], Heap[pos]))
            {
                swap(Heap[pos], Heap[j]);
                pos = j;
            }
            else
            {
                return;
            }
        }
    }

public:
    heap(E *h, int num, int max)
    {
        Heap = h;
        n = num;
        maxsize = max;
        buildHeap();
    }
    int size() const
    {
        return n;
    }
    bool isLeaf(int pos) const
    {
        return pos >= n / 2 && pos < n;
    }
    int leftChild(int pos) const
    {
        return 2 * pos + 1;
    }
    int rightChild(int pos) const
    {
        return 2 * pos + 2;
    }
    int parent(int pos) const
    {
        return (pos - 1) / 2;
    }
    void buildHeap()
    {
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            siftdown(i);
        }
    }

    // insert
    void insert(const E &it)
    {
        assert(n < maxsize && "Heap is full");
        int curr = n++;
        Heap[curr] = it;
        while (curr != 0 && Comp::prior(Heap[curr], Heap[parent(curr)]))
        {
            swap(Heap[curr], Heap[parent(curr)]);
            curr = parent(curr);
        }
    }
    E removefirst()
    {
        assert(n > 0 && "Heap is empty");
        swap(Heap[0], Heap[--n]);
        if (n != 0)
            siftdown(0);
        return Heap[n];
    }

    E remove(int pos)
    {
        assert(pos >= 0 && pos < n && "Bad position");
        if (pos == (n - 1))
            n--;
        else
        {
            swap(Heap[pos], Heap[--n]);
            while ((pos != 0) && (Comp::prior(Heap[pos], Heap[parent(pos)])))
            {
                swap(Heap[pos], Heap[parent(pos)]);
                pos = parent(pos);
            }
            if (n != 0)
                siftdown(pos);
        }
        return Heap[n];
    }
};

// Define a struct to use with the heap class
template <typename E>
class Comp
{
public:
    bool prior(const E &a, const E &b)
    {
        return a > b;
    }
};

// Define a comparison class for IntStruct elements

int main()
{
    outtext;
    _io;
    const int NUM_ELEMENTS = 7;
    int arr[NUM_ELEMENTS] = {5, 9, 3, 7, 1, 2, 8};
    heap<int, Comp> h(arr, NUM_ELEMENTS, NUM_ELEMENTS);

    cout << "Heap size: " << h.size() << endl;

    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        cout << h.removefirst()<< " ";
    }
    cout << endl;

    return 0;
}