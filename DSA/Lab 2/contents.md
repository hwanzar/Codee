# Lab 2: Stack - Queue - Sort
## 6
Given an array of integers.
Your task is to implement a function with following prototype:
int sumOfMinSubarray(vector<int>& nums);
The function returns the sum of the minimum value of every subarray of nums. The sum may be too large, so the result should mod 10000.

Note:
- The iostream, vector and stack libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.
For example:

|Test|	Result|
|------|------|
|vector<int> nums {1, 2, 4, 3};
cout << sumOfMinSubarray(nums);|20|


## 7
Given a string s containing just the characters '(', ')', '[', ']', '{', and '}'. Check if the input string is valid based on following rules:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
For example:

String "[]()" is a valid string, also "[()]".
String "[])" is not a valid string.
Your task is to implement the function
```cpp
bool isValidParentheses (string s){
    /*TODO*/
}
```


## 12
Implement method bubbleSort() in class SLinkedList to sort this list in ascending order. After each bubble, we will print out a list to check (using printList). 
```cpp
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList()
    {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };

    void bubbleSort();
};
```
For example:

|Test	|Result|
|--------------------------|--------------------|
|int arr[] = {9, 2, 8, 4, 1};SLinkedList<int> list;--for(int i = 0; i <int(sizeof(arr))/4;i++)list.add(arr[i]);list.bubbleSort();|[2,8,4,1,9][2,4,1,8,9][2,1,4,8,9][1,2,4,8,9]|


## 15
Implement static methods sortSegment and ShellSort in class Sorting to sort an array in ascending order. 

```cpp
#ifndef SORTING_H
#define SORTING_H

#include <sstream>
#include <iostream>
#include <type_traits>
using namespace std;

template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
    }

    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total) ;

public:
    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) ;
};

#endif /* SORTING_H */
```


Test
```cpp
int num_segment_list[] = {1, 3, 5};
int num_phases = 3;
int array[] = { 10, 9, 8 , 7 , 6, 5, 4, 3, 2, 1 };

Sorting<int>::ShellSort(&array[0], &array[10], &num_segment_list[0], num_phases);
```
Output:
```bash
5 segments: 5 4 3 2 1 10 9 8 7 6
3 segments: 2 1 3 5 4 7 6 8 10 9
1 segments: 1 2 3 4 5 6 7 8 9 10
```



