#include <bits/stdc++.h>
using namespace std;


template<class T>
class IDeck{
    public:
        virtual ~IDeck() {};
        virtual void push(T item)=0;
        virtual T pop()=0;
        virtual T& peek()=0;
        virtual bool empty()=0;
        virtual int size()=0;
        virtual void clear()=0;
        virtual bool remove(T item)=0;
        virtual bool contains(T item)=0;
        virtual string toString(string (*item2str)(T&)=0)=0;
};
