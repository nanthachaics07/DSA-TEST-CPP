#include <csignal>
#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

class Tree {
private:
    struct Node {
        int data;
        Node *left;
        Node *right;
        Node(int D) : data(D), left(NULL), right(NULL) {}
    };
    Node *root;

    Node *createTree(int data) {
        return new Node(data);
    }

    void insertNode(Node *&root, int data) {
        if (root == NULL) {
            root = createTree(data);
            return;
        }
        if (data < root->data) {
            insertNode(root->left, data);
        } else {
            insertNode(root->right, data);
        }
    }

    void printTree(Node *root) {
        if (root != NULL) {
            // cout << "Travel In Tree List : ";
            printTree(root->left);
            cout << " " << root->data;
            printTree(root->right);
        }
    }

    void deleleNode(Node *root) {
        if (root != NULL) {
            deleleNode(root->left);
            deleleNode(root->right);
            delete root;
        }
    }

public:
    Tree() : root(NULL) {}
    ~Tree() {
        deleleNode(root);
    }

    void insertTree(int data) {
        return insertNode(root, data);
    }

    void travelTree() {
        return printTree(root);
    }

};

void signalHandler(int signal) {
    cout << "Interrupt signal (" << signal << ") received.\n";
    exit(signal);
}

int main() {
    signal(SIGINT, signalHandler);

    Tree t;
    t.insertTree(3);
    t.insertTree(6);
    t.insertTree(2);
    t.insertTree(34);
    t.insertTree(83);
    t.insertTree(1);
    t.insertTree(38);
    cout << "Travel : ";
    t.travelTree();
    cout << endl;

    while(false) {
        cout << "Sleep......" << endl;
        sleep(1);
    }
    return 0;
}
