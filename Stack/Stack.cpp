//
// Created by Ahmed on 10/12/2023.
//
#include "iostream"
using namespace std;
#include "Stack.h"

Stack::Stack() {
    top=0; //empty
}

void Stack::push(int x) {
    if (!Isfull()) {
        arr[top] = x;
        top++;
        cout<<"you have just pushed x\n";
    }else {
        cout << "Error";
    }
}

int Stack::pop() {
    if(!isEmpty()){
        top--;
        cout<<arr[top]<<" has just been popped\n";
        return arr[top];
    }
    cout<<"Error";
    return 404;
}

bool Stack::isEmpty() {
    if(top==0)
        return true;
    return false;
}

bool Stack::Isfull() {
    if(top==Capacity)
        return true;
    return false;
}

int Stack::Top() {
    if(!isEmpty()){
        return arr[top-1];
    }
    cout<<"Error";
    return 404;
}
