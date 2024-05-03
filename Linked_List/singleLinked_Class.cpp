#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
class Node{
public:
    Node<T> * next;
    T value;
    Node(T data): value(data),next(nullptr){}
};

template <typename T>
class singleLinkedList{
private:
    Node<T>* head;
    int size;
public:
    singleLinkedList():head(nullptr),size(0){}
    void insertAtHead(T element){
        Node<T> *newNode=new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }
    void insertAtTail(T element){
        Node<T>* newNode= new Node<T>(element);
        if(head==nullptr){
            head=newNode;
        }else {
            Node<T>* temp= head;
            while (temp->next != nullptr){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        size++;
    }
    void insertAt(T element,int index){
        if(index>size||index<0){
            throw invalid_argument("Error");
        }else{
            if(index==0){
                insertAtHead(element);
            }else if(index==size){
                insertAtTail(element);
            }else{
                Node<T> *newNode=new Node<T>(element);
                Node<T>*temp=head;
                for(int i=0;i<index-1;i++){
                    temp=temp->next;
                }
                newNode->next=temp->next;
                temp->next=newNode;
                size++;
            }
        }
    }
    void removeAtHead(){
        if(head== nullptr){
            throw invalid_argument("Error");
        }else{
            Node<T> *temp=head;
            head=head->next;
            delete temp;
            size--;
        }
    }
    void removeAtTail(){
        if(head== nullptr){
            throw invalid_argument("Error");
        }else{
            Node<T> *temp=head;
            while(temp->next!= nullptr){
                temp=temp->next;
            }
            delete temp;
            temp->next= nullptr;
            size--;
        }
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
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            Node<T>* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
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
        return temp->value;
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
        temp->value = newElement;
    }
    bool isExist(T element) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->value == element) {
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
        Node<T>* prevFirst = nullptr;
        Node<T>* first = head;
        for (int i = 0; i < firstItemIdx; i++) {
            prevFirst = first;
            first = first->next;
        }
        Node<T>* prevSecond = nullptr;
        Node<T>* second = head;
        for (int i = 0; i < secondItemIdx; i++) {
            prevSecond = second;
            second = second->next;
        }
        if (prevFirst != nullptr) {
            prevFirst->next = second;
        } else {
            head = second;
        }
        if (prevSecond != nullptr) {
            prevSecond->next = first;
        } else {
            head = first;
        }
        Node<T>* temp = first->next;
        first->next = second->next;
        second->next = temp;
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
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    singleLinkedList<int> s;
    s.insertAtHead(1);
    s.insertAtHead(2);
    s.insertAtTail(3);
    s.print();

    return 0;
}
