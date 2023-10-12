//
// Created by Ahmed on 10/12/2023.
//
#include "iostream"
using namespace std;
#ifndef CLION_STACK_H
#define CLION_STACK_H
const int Capacity = 30;
class Stack {
private:
    int top;
    int arr[Capacity];
public:
    Stack();
    void push(int x);
    int pop();
    bool isEmpty();
    bool Isfull();
    int Top();
};


#endif //CLION_STACK_H
