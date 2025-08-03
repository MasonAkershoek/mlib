#include <stdio.h>
#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class mList{
    public:
        // Constructor
        mList(){
            data = new T[arraySize];
            listSize = 0;
        }

        // Copy constructor
        mList(const mList& oldList){
            arraySize = oldList.arraySize;
            listSize = oldList.listSize;
            data = new T[arraySize];
            for (int i=0; i < oldList.size(); i++){
                data[i] = oldList[i];
            }
        }

        // Delete function
        ~mList(){
            delete[] data;
            data = nullptr;
        }

        // Overload of the [] indexing operator
        T& operator[](int index){
            if (index < 0 || index >= listSize){
                throw out_of_range("Index out of range!");
            }
            return data[index];
        }

        const T& operator[](int index) const{
            if (index < 0 || index >= listSize){
                throw out_of_range("Index out of range!");
            }
            return data[index];
        }

        // Append an item to the end of the list
        void append(T item){
            checkSize();
            listSize++;
            data[listSize-1] = item;
        }

        // Add an item to the beginning of the list 
        void pushback(T item){
            checkSize();
            listSize++;
            for (int i=listSize-1; i >= 0; i--){
                data[i+1] = data[i];
            }
            data[0] = item;
        }

        // Remove the item from the beginning of the list and returns it
        T pop(){
            T ret = data[0];
            listSize--;
            for (int i=0; i < listSize; i++){
                data[i] = data[i+1];
            }
            data[listSize+1] = NULL;
            return ret;
        }

        // Remove the item form the end of the list and return it
        T popback(){
            T ret = data[listSize-1];
            data[listSize-1] = NULL;
            listSize--;
            return ret;
        }

        // Remove and return the item at a spesifed location
        T remove();

        // Insert an item into a spesifed index of the list
        void insert(int index, T item);

        // Return the size of the list
        int size() const{
            return listSize;
        }

        // Clears the contents of the list
        void clear(){
            listSize = 0;
        }


    private:
        int arraySize = 100;
        int listSize;
        T* data;

        // Resize the data array for fitting more items in the list
        void resize(){
            arraySize=arraySize+100;
            T* tmp;
            tmp = new T[arraySize];
            for (int i=0; i < listSize; i++){
                tmp[i] = data[i];
            }
            delete[] data;
            data = tmp;
            tmp = nullptr;
        }

        // Checks the size of the list and determins if th elist needs to be grown
        void checkSize(){
            if (listSize+1 == arraySize){
            resize();
            }
        }

};