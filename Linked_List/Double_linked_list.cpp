#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(T value):data(value),next(nullptr),prev(nullptr){}
};

template<typename T>
class doubleLinkedList{
private:
    int size;
    Node<T>* head;
    Node<T>* tail;
public:
    doubleLinkedList():size(0),head(nullptr),tail(nullptr){}

    void insertAtHead(T element){
        Node<T>* newNode=new Node<T>(element);
        if(head == nullptr){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        size++;
    }
    void insertAtTail(T element){
        Node<T>* newNode=new Node<T>(element);
        if(head== nullptr){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
        size++;
    }
    void insertAt(T element,int index){
        if(index<0||index>size){
            throw invalid_argument("Error");
        }else if(index==0){
            insertAtHead(element);
        }else if(index==size){
            insertAtTail(element);
        }else{
            Node<T>* newNode=new Node<T>(element);
            Node<T>* temp=head;
            for(int i=0;i<index-1;i++){
                temp=temp->next;
            }
            newNode->next=temp->next;
            newNode->prev=temp;
            temp->next->prev=newNode;
            temp->next=newNode;
            size++;
        }
    }
    void removeAtHead(){
        if(head== nullptr){
            throw invalid_argument("Error");
        }else{
            Node<T>* temp=head;
            head=head->next;
            if(head!= nullptr){
                head->prev= nullptr;
            }else{
                tail= nullptr;
            }
            delete temp;
            size--;
        }
    }
    void removeAtTail() {
        if (head == nullptr) {
            throw invalid_argument("Error");
        }
        if (head->next == nullptr) {
            delete head;
            head = tail = nullptr;
        } else {
            Node<T> *temp = tail;
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    }   
    void removeAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return;
        }
        if (index == 0) {
            removeAtHead();
        } else if (index == size - 1) {
            removeAtTail();
        } else {
            Node<T>* temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            size--;
        }
    }
    T retrieveAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return T();
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    void replaceAt(T newElement, int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->data = newElement;
    }
    bool isExist(T element) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == element) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    bool isItemAtEqual(T element, int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds\n";
            return false;
        }
        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data == element;
    }
    void swap(int firstItemIdx, int secondItemIdx) {
        if (firstItemIdx < 0 || firstItemIdx >= size || secondItemIdx < 0 || secondItemIdx >= size) {
            cout << "Invalid indices\n";
            return;
        }
        if (firstItemIdx == secondItemIdx) {
            return;
        }
        Node<T>* first = head;
        for (int i = 0; i < firstItemIdx; i++) {
            first = first->next;
        }
        Node<T>* second = head;
        for (int i = 0; i < secondItemIdx; i++) {
            second = second->next;
        }
        T temp = first->data;
        first->data = second->data;
        second->data = temp;
    }
    bool isEmpty() {
        return size == 0;
    }
    int linkedListSize() {
        return size;
    }
    void clear() {
        while (head != nullptr) {
            removeAtHead();
        }
    }
    void print() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};


int main() {
        doubleLinkedList<int>d;
        d.insertAtHead(1);
        d.insertAtHead(2);
        d.insertAtTail(3);
        d.print();
    return 0;
}
