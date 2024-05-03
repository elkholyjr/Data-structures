#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class CircularLinkedList {
private:
    Node<T> *head;
    int size;
public:
    CircularLinkedList() : head(nullptr), size(0) {}
    void insertAtHead(T element) {
        Node<T>* newNode = new Node<T>(element);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
        } else {
            Node<T>* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void insertAtTail(T element){
        Node<T>* newNode=new Node<T>(element);
        if(head== nullptr){
            head=newNode;
            newNode->next=head;
        }else{
            Node<T>* temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=head;
        }
        size++;
    }
    void insertAt(T element, int index) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds\n";
            return;
        }
        if (index == 0) {
            insertAtHead(element);
        } else if (index == size) {
            insertAtTail(element);
        } else {
            Node<T>* newNode = new Node<T>(element);
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }
    void removeAtHead() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node<T>* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            head = head->next;
        }
        delete temp;
        size--;
    }
    void removeAtTail() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node<T>* temp = head;
            Node<T>* prev = nullptr;
            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = head;
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
            if (temp == head) {
                break;
            }
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
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        Node<T>* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main() {
    CircularLinkedList<int> cll;
    cll.insertAtHead(1);
    cll.insertAtTail(3);
    cll.insertAt(2, 1);
    cll.print();
    return 0;
}
