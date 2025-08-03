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
    return data[index];
}

template <typename T>
const T& mList<T>::operator[](int index) const{
    if (index < 0 || index >= listSize){
        throw out_of_range("Index out of range!");
    }
    return data[index];
}

template <typename T>
void mList<T>::checkSize(){
    if (listSize+1 == arraySize){
        resize();
    }
}

template <typename T>
void mList<T>::append(T item){
    checkSize();
    listSize++;
    data[listSize-1] = item;
}

template <typename T>
void mList<T>::pushback(T item){
    checkSize();
    listSize++;
    T tmp;
    for (int i=listSize-1; i >= 0; i--){
        data[i+1] = data[i];
    }
    data[0] = item;
}

template <typename T>
T mList<T>::pop(){
    T ret = data[0];
    listSize--;
    for (int i=0; i < listSize; i++){
        data[i] = data[i+1];
    }
    data[listSize+1] = NULL;
    return ret;
}

template <typename T>
T mList<T>::popback(){
    T ret = data[listSize-1];
    data[listSize-1] = NULL;
    listSize--;
    return ret;
}

template <typename T>
int mList<T>::size(){
    return listSize;
}

template <typename T>
void mList<T>::clear(){
    listSize = 0;
}

template <typename T>
void mList<T>::resize(){
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

int main(){
    mList<int> mylist;

    mylist.append(59);
    cout << mylist[0] << endl;
    cout << mylist.pop() << endl;
    cout << mylist[0] << endl;
}
