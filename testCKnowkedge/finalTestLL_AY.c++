// #include <cmath>
#include <iostream>
// #include <vector>

using namespace std;

class Linked {
private:
    struct Node {
        int data;
        Node *next;
        Node *prev;
        Node(int D) : data(D), next(NULL), prev(NULL) {}
    };
    Node *root;

    Node *createNode(int data) {
        return new Node(data);
    }

    Node *insertSingle(Node *root, int data) {
        if (root == NULL) {
            return createNode(data);
        }
        root->next = insertSingle(root->next, data);
        return root;
    }

    Node *insertDouble(Node *root, int data) {
        if (root == NULL) {
            return createNode(data);
        }
        if (root->next == NULL) {
            Node *newnode = new Node(data);
            root->next = newnode;
            newnode->prev = root;
        } else {
            root->next = insertDouble(root->next, data);
            root->next->prev = root;
        }
        return root;
    }

    Node *deleteNode(Node *current, int target) {
        if (current == NULL) return NULL;
        if (current->data == target) {
            Node *temp = current->next;
            if (temp != NULL) {
                temp->prev = current->prev;
            }
            if (current->prev != NULL) {
                current->prev->next = temp;
            } else {
                this->root = temp;
            }
            delete current;
            return temp;
        } else {
            current->next = deleteNode(current->next, target);
        }
        return current;
    }

    void printList(Node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            printList(root->next);
        }
    }

    void clearNode(Node *root) {
        if (root != NULL) {
            clearNode(root->next);
            delete  root;
        }
    }

public:
    Linked() : root(NULL) {}
    ~Linked() {clearNode(root);}

    void printList() {
        return  printList(root);
    }

    void insertSingle(int data) {
        root = insertSingle(root, data);
    }

    void insertDouble(int data) {
        root = insertDouble(root, data);
    }



};

int main() {
    Linked l;
    // l.insertSingle(8);
    // l.insertSingle(2);
    // l.insertSingle(7);
    // l.insertSingle(5);
    // l.insertSingle(9);
    // l.insertSingle(0);
    // l.insertSingle(2);
    // l.insertSingle(23);
    l.insertDouble(5);
    l.insertDouble(6);
    l.insertDouble(2);
    l.insertDouble(1);
    l.insertDouble(8);
    l.insertDouble(9);
    l.insertDouble(6);
    cout << "Link  : " << endl;
    l.printList();
    cout << endl;


    return 0;
}
