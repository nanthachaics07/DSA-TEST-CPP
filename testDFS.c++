#include <iostream>
#include <stack>

using namespace std;

class DFSTree {
public:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int V) : data(V), left(NULL), right(NULL) {}
    };

    Node* createNode(int data) {
        return new Node(data);
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

    void DFS(Node *root) {
        stack<Node*> s;
        s.push(root);

        while (!s.empty()) {
            Node *temp = s.top();
            s.pop();
            cout<< "vist " << temp->data << " ";

            if (temp->left != NULL) {
                // cout<< " L " << temp->left->data << " ";
                s.push(temp->left);
            }
            if (temp->right != NULL) {
                // cout<< " R " << temp->right->data << " ";
                s.push(temp->right);
            }
            cout << endl;
        }
    }
};

int main() {
    DFSTree D;
    DFSTree::Node *root = NULL;

    D.insertTree(root, 20);
    D.insertTree(root, 30);
    D.insertTree(root, 10);
    D.insertTree(root, 34);
    D.insertTree(root, 2);
    D.insertTree(root, 12);
    D.insertTree(root, 2);
    D.insertTree(root, 6);

    cout << " DFS : " << endl;
    D.DFS(root);
    cout << endl;

    return 0;
}
