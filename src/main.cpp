#include <iostream>
#include "mlib.h"

using namespace std;

template <typename T> 
mList<T>::mList(){
    data = new T[arraySize];
    listSize = 0;
}

template <typename T> 
mList<T>::mList(const mList& oldList){
    arraySize = oldList.arraySize;
    listSize = oldList.listSize;
    data = new T[arraySize];
    for (int i=0; i < oldList.size(); i++){
        data[i] = oldList[i];
    }
}

template <typename T> 
mList<T>::~mList(){
    delete[] data;
    data = nullptr;
}
