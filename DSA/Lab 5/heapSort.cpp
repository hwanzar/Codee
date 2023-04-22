#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

template <class T>
class Sorting
{
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    // Helping functions go here
    static void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    static void heapify(int arr[], int N, int i)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < N && arr[left] > arr[largest])
            largest = left;
        if (right < N && arr[right] > arr[largest])
        {
            largest = right;
        }
        // min heap
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, N, largest);
        }
    }

    static void heapSort(T *start, T *end)
    {
        // TODO
        int N = end - start;
        for (int i = N / 2 - 1; i >= 0; i--)
        {

            Sorting<T>::heapify(start, N, i);
        }
        for (int i = N - 1; i >= 0; i--)
        {
            Sorting<T>::swap(&start[0], &start[i]);
            Sorting<T>::heapify(start, i, 0);
        }
        Sorting<T>::printArray(start, end);
    }
};

int main()
{
    outtext;
    _io;
    int arr[4] = {4, 2, 9, 1};
    Sorting<int>::heapSort(&arr[0], &arr[4]);
    return 0;
}