#include <iostream>

using namespace std;

class TreeNode {
public:
    struct Node {
        int data;
        Node *left;
        Node *right;

        Node(int V) : data(V), left(NULL), right(NULL) {}
    };

    Node* createNode(int ndata) {
        return new Node(ndata);
    }

    void insertTree(Node *&root, int data) {
        if (root == NULL) {
            root = createNode(data);
            return;
        }

        if (data < root->data) {
            insertTree(root->left, data);
        } else {
            insertTree(root->right, data);
        }
    }

    void travalTree(Node *root) {
        if (root != NULL) {
            travalTree(root->left);
            cout << root->data << " ";
            travalTree(root->right);
        }
    }

};

int main() {
    TreeNode T;
    TreeNode::Node *root = NULL;

    T.insertTree(root, 10);
    T.insertTree(root, 4);
    T.insertTree(root, 1);
    T.insertTree(root, 7);
    T.insertTree(root, 55);
    T.insertTree(root, 3);
    T.insertTree(root, 43);
    T.insertTree(root, 29);

    cout << "teavel : ";
    T.travalTree(root);
    cout << endl;

    return 0;

}
