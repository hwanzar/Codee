#include <bits/stdc++.h>
using namespace std;
#define outtext freopen("output.txt", "w", stdout)
#define _io                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);

    static void oddEvenSort(T *start, T *end);

    static void sortSegment(T *start, T *end, int segment_idx, int cur_segment_total);

    static void ShellSort(T *start, T *end, int *num_segment_list, int num_phases);
};

template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
    int size = end - start;
    T pivot = start[0];
    int left = 1;
    int right = size - 1;
    while (true)
    {
        while (left <= right && start[left] < pivot)
        {
            left++;
        }
        while (right >= left && pivot < start[right])
            right--;
        if (left >= right)
            break;
        swap(start[left], start[right]);
        left++;
        right--;
    }
    swap(start[0], start[right]);
    return start + right;
}
// template <class T>
// void Sorting<T>::printArray(T *start, T *end){
//     int size = end - start;
//     for (int i = 0; i < size; i++)
//         cout << start[i] << ", ";
//     cout << start[size];
//     cout << endl;
// }
// template <class T>
// void Sorting<T>::insertionSort(T *start, T *end)
// {
//     int size = end - start;
//     for (int i = 1; i < size; i++)
//     {
//         if (start[i] < start[i - 1])
//         {
//             T temp = start[i];
//             start[i] = start[i - 1];
//             start[i - 1] = temp;
//         }
//     }
// }
template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
    int len = end - start;
    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        T temp = start[i];
        while (j >= 0 && start[j] > temp)
        {
            start[j + 1] = start[j];
            j--;
        }
        start[j + 1] = temp;
    }
}
template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    int len = end - start;
    if (len < min_size)
    {
        cout << "Insertion sort: ";
        Sorting::printArray(start, end);
        insertionSort(start, end);
        return;
    }
    else
    {
        cout << "Quick sort: ";
        Sorting::printArray(start, end);
        T *pivot = Partition(start, end);
        if (pivot != start)
        {
            hybridQuickSort(start, pivot, min_size);
        }
        if (pivot != end - 1)
        {
            hybridQuickSort(pivot + 1, end, min_size);
        }
    }
}
template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    bool isSorted = false;
    int size = end - start;

    while (!isSorted)
    {
        isSorted = true;

        // even index elements
        for (int i = 0; i <= size - 2; i += 2)
        {
            if (start[i] > start[i + 1])
            {
                swap(start[i], start[i + 1]);
                isSorted = false;
            }
        }
        for (int i = 1; i <= size - 2; i += 2)
        {
            if (start[i] > start[i + 1])
            {
                swap(start[i], start[i + 1]); // swap bubble sort;
                isSorted = false;
            }
        }
        // print phase
        printArray(start, end);
    }
}
template <class T>
void Sorting<T>::sortSegment(T *start, T *end, int segment_idx, int cur_segment_total)
{
    int size = end - start;

    for (int i = segment_idx; i < size; i += cur_segment_total)
    {
        T temp = start[i];
        int j;
        for (j = i; j >= cur_segment_total && start[j - cur_segment_total] > temp; j -= cur_segment_total)
            start[j] = start[j - cur_segment_total];
        start[j] = temp;
    }
}

template <class T>
void Sorting<T>::ShellSort(T *start, T *end, int *num_segment_list, int num_phases)
{
    for (int i = num_phases - 1; i >= 0; i--)
    {
        int cur_segment_total = num_segment_list[i];
        cout << cur_segment_total << " segments: ";
        for (int a = 0; a < cur_segment_total; a++)
        {
            sortSegment(start, end, a, cur_segment_total);
        }
        printArray(start, end);
    }
}

int main()
{
    outtext;
    _io;
    // int array[] = {1, 2, 6, 4, 7, 8, 5, 3};
    // int min_size = 4;
    // Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
    int num_segment_list[] = {1, 3, 5};
    int num_phases = 3;
    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
}