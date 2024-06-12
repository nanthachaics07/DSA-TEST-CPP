#include <iostream>
#include <queue>
#include <random>

using namespace std;

class BFSTree {
public:
    struct Node {
        int data;
        Node *left;
        Node *right;

        Node(int V) : data(V), left(NULL), right(NULL) {}
    };

    Node* createNode(int data) {
        return new Node(data);
    }

    void bubbleSort(vector<int> data) {
        int len = data.size();
        bool check;
        for (int i=0; i<len-1; i++) {
            check = false;
            for (int j=0; j<len-i-1; j++) {
                check = true;
                if (data[i] > data[i-1]) {
                    swap(data[i], data[i-i]);
                }
            }
        }
        return;
    }

    void insertionSort(vector<int> data) {
        int n = data.size();
        for (int i=0; i<=n-1; i++) {
            int key = data[i];
            int j = i-1;
            while (j>=0 && data[j] > key) {
                data[j+1] = data[j];
                j--;
            }
            data[j+1] = key;
        }
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

    void bfs(Node *root) {
        if (root == NULL) return;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            cout << "Visted " << temp->data << " Nabul : ";

            if (temp->left != NULL) {
                cout << " L " << temp->left->data << " ";
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                cout << " R " << temp->right->data << " ";
                q.push(temp->right);
            }
            cout << endl;
        }
    }

};

int main() {
    BFSTree B;
    BFSTree::Node *root = NULL;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis_int(1, 100);

    B.insertTree(root, dis_int(gen));
    B.insertTree(root, dis_int(gen));
    B.insertTree(root, dis_int(gen));
    B.insertTree(root, dis_int(gen));
    B.insertTree(root, dis_int(gen));
    B.insertTree(root, dis_int(gen));

    B.bfs(root);

    return 0;
}
