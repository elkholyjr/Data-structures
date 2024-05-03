#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
class Node {
public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
private:
    Node<T>* root;
    Node<T>* insertRec(Node<T>* root, T key) {
        if (root == nullptr) {
            return new Node<T>(key);
        }
        if (key < root->data) {
            root->left = insertRec(root->left, key);
        } else if (key > root->data) {
            root->right = insertRec(root->right, key);
        }
        return root;
    }
    Node<T>* searchRec(Node<T>* root, T key) {
        if (root == nullptr || root->data == key) {
            return root;
        }
        if (key < root->data) {
            return searchRec(root->left, key);
        }
        return searchRec(root->right, key);
    }
    Node<T>* minValueNode(Node<T>* node) {
        Node<T>* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
    Node<T>* deleteRec(Node<T>* root, T key) {
        if (root == nullptr) {
            return root;
        }
        if (key < root->data) {
            root->left = deleteRec(root->left, key);
        } else if (key > root->data) {
            root->right = deleteRec(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node<T>* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node<T>* temp = root->left;
                delete root;
                return temp;
            }
            Node<T>* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteRec(root->right, temp->data);
        }
        return root;
    }
    void inorderRec(Node<T>* root) {
        if (root != nullptr) {
            inorderRec(root->left);
            cout << root->data << " ";
            inorderRec(root->right);
        }
    }
public:
    BST() : root(nullptr) {}
    void insert(T key) {
        root = insertRec(root, key);
    }
    Node<T>* search(T key) {
        return searchRec(root, key);
    }
    void remove(T key) {
        root = deleteRec(root, key);
    }
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
};
int main() {
    BST<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    cout << "Inorder traversal of the BST: ";
    bst.inorder();
    Node<int>* searchResult = bst.search(40);
    if (searchResult != nullptr) {
        cout << "Element 40 found in the BST" << endl;
    } else {
        cout << "Element 40 not found in the BST" << endl;
    }
    bst.remove(70);
    cout << "Inorder traversal after deleting 20: ";
    bst.inorder();

    return 0;
}
