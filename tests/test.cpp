#include <cassert>
#include "../src/mlib.h"
#include <string.h>
#include <stdio.h>

using namespace std;

mList<int> mylist;

void passTest(string test){
    cout << "[ " << test << " ]" << " Passed!" << endl;
}

void test_append_list(){
    assert(mylist.size() == 0);
    mylist.append(50);
    assert(mylist.size() == 1);
    assert(mylist[0] == 50);
    mylist[0] = 0;
    assert(mylist[0] == 0);
    mylist.clear();
    for (int x=0; x < 1000; x++){
        mylist.append(x);
    }
    for (int x=0; x < 1000; x++){
        assert(mylist[x] == x);
    }
    passTest("append Test");
}

void test_copy(){
    mList<int> copyList(mylist);
    for (int x=0; x < mylist.size(); x++){
        assert(mylist[x] == copyList[x]);
    }
    passTest("copy Test");
}

void test_pushback(){
    mylist.clear();
    assert(mylist.size() == 0);
    for (int x = 200; x >= 0; x--){
        mylist.pushback(x);
    }
    for (int x=0; x < mylist.size(); x++){
        assert(mylist[x] == x);
    }
    passTest("pushback Test");
}

void test_pop(){
    assert(mylist[0] == 0);
    
}


// Run tests
int main(){
    test_append_list();
    test_copy();
    test_pushback();
}