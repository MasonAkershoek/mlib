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

template <typename T>
T& mList<T>::operator[](int index){
    if (index < 0 || index >= listSize){
        throw out_of_range("Index out of range!");
    }
    return 
}

template <typename T>
const T& mList<T>::operator[](int index) const{
    if (index < 0 || index >= listSize){
        throw out_of_range("Index out of range!");
    }
    return 
}

template <typename T>
void mList<T>::checkSize(){
    if (listSize+1 == arraySize){
        resize()
    }
}

template <typename T>
void mList<T>::append(T item){
    checkSize;
    listSize++;
    data[listSize-1] = item;
}

template <typename T>
void mList<T>::pushback(T item){
    
}

int main(){
    return 0;
}
