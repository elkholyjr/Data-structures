#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class AVL {
  private:
    struct Node {
        T data;
        Node *left;
        Node *right;
        int height;

        Node(T value) : data(value), left(nullptr), right(nullptr), height(0) {}
    };
    Node *root;

    int NodeHeight(Node *curr) {
        if (curr == nullptr)
            return 0;
        return curr->height;
    }

    Node *rightRotate(Node *root) {
        Node *y = root->left;
        root->left = y->right;
        y->right = root;

        root->height = max(NodeHeight(root->left), NodeHeight(root->right)) + 1;
        y->height = max(NodeHeight(y->left), NodeHeight(y->right)) + 1;

        return y;
    }

    Node *leftRotate(Node *root) {
        Node *y = root->right;
        root->right = y->left;
        y->left = root;

        root->height = max(NodeHeight(root->left), NodeHeight(root->right)) + 1;
        y->height = max(NodeHeight(y->left), NodeHeight(y->right)) + 1;

        return y;
    }

    int getBalance(Node *root) {
        if (root == nullptr)
            return 0;
        return NodeHeight(root->left) - NodeHeight(root->right);
    }

    Node *insertRec(Node *root, T key) {
        if (root == nullptr) {
            root = new Node(key);
        } else if (key < root->data) {
            root->left = insertRec(root->left, key);
        } else if (key > root->data) {
            root->right = insertRec(root->right, key);
        }
        root->height = max(NodeHeight(root->left), NodeHeight(root->right)) + 1;

        int balance = getBalance(root);

        if (balance > 1 && key < root->left->data) {
            return rightRotate(root);
        }
        if (balance < -1 && key > root->right->data) {
            return leftRotate(root);
        }
        if (balance > 1 && key > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && key < root->right->data) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    Node *searchRec(Node *root, T key) {
        if (root == nullptr || root->data == key) {
            return root;
        }
        if (key < root->data) {
            return searchRec(root->left, key);
        }
        return searchRec(root->right, key);
    }
    Node *minValueNode(Node *node) {
        Node *current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }
Node *deleteRec(Node *root, Node *nodeToDelete) {
    if (root == nullptr || nodeToDelete == nullptr) {
        return root;
    }
    
    if (nodeToDelete->data < root->data) {
        root->left = deleteRec(root->left, nodeToDelete);
    } else if (nodeToDelete->data > root->data) {
        root->right = deleteRec(root->right, nodeToDelete);
    } else {
        if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteRec(root->right, temp);
    }

    // Update height
    root->height = 1 + max(NodeHeight(root->left), NodeHeight(root->right));

    // Rebalance the tree
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
    void inorderRec(Node *root, vector<T> &arr) {
        if (root != nullptr) {
            inorderRec(root->left, arr);
            arr.push_back(root->data);
            cout << root->data << ':' << root->height << ' ';
            inorderRec(root->right, arr);
        }
    }

  public:
    AVL() : root(nullptr) {}
    void insert(T key) {
        root = insertRec(root, key);
    }
    Node *search(T key) {
        return searchRec(root, key);
    }
    void remove(T key) {
        root = deleteRec(root, key);
    }
    vector<T> inorder() {
        vector<T> ans;
        inorderRec(root, ans);
        return ans;
    }
};

int main() {
    AVL<int> TT;
    TT.insert(20);
    TT.insert(30);
    TT.insert(40);
    TT.insert(50);
    TT.insert(60);
    TT.insert(70);
    TT.insert(80);
    TT.inorder();
}
