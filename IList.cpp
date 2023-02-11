#include <bits/stdc++.h>
using namespace std;

template <typename E> class List{
    private:
        void operator =(const List&) {}
        List(const List&) {}
    public:
        List() {}
        virtual ~List() {} //Base Constructor
        //CLEAR contents from the list, to make it empty
        virtual void clear() = 0;

        //Insert element at the current location
        //item: the element to be inserted.
        //
        virtual void insert(const E& item) = 0;
        virtual void append(const E& item) = 0;
        
        //remove and return the current element
        // Return: the element that was removed.
        virtual E remove() = 0;
        
        // Set the current position to the start of the list
        
        virtual void moveToStart() = 0;

        // Set the current position to the end of the list
        //
        virtual void moveToEnd() = 0;
        
        // Move 

};
