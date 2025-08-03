#include <stdio.h>
#include <iostream>

template <typename T> class mList{
    public:
        // Constructor
        mList();

        // Copy constructor
        mList(const mList&);

        // Delete function
        ~mList(); 

        // Overload of the [] indexing operator
        T& operator[](int index);

        const T& operator[](int index) const;

        // Append an item to the end of the list
        void append(T item); 

        // Add an item to the beginning of the list 
        void pushback(T item);

        // Remove the item from the beginning of the list and returns it
        T pop();

        // Remove the item form the end of the list and return it
        T popback();

        // Remove and return the item at a spesifed location
        T remove();

        // Insert an item into a spesifed index of the list
        void insert(int index, T item);

        // Return the size of the list
        int size();

        // Clears the contents of the list
        void clear();


    private:
        int arraySize = 100;
        int listSize;
        T* data;

        // Resize the data array for fitting more items in the list
        void resize();

        // Checks the size of the list and determins if th elist needs to be grown
        void checkSize();

};