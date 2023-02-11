#include <bits/stdc++.h>
using namespace std;


template<class T> class XArrayList {
protected:
    T* data;
    int capacity;
    int count;
    bool (*itemEqual)(T* lhs, T& rhs); //function pointer
    void (*deleteUserData)(XArrayList<T>*);
public:
    
};
