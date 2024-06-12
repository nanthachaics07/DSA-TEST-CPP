#include <iostream>
// #include <algorithm>
#include <sys/signal.h>
#include <vector>
#include <stack>
#include <queue>
#include <list>

using namespace std;

class SortAlg {
private:
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
};

class Tree {
public:
    struct Node {
      int data;
      Node *left;
      Node *right;

      Node(int D) : data(D), left(NULL), right(NULL) {}
    };
    Node *root;
    Tree() : root(NULL) {}

    Node *createTreeNode(int data) {
        return new Node(data);
    }

    void insertData(int data) {
        return insertData(root, data);
    }

    void insertData(Node *&root, int data) {
        if (root == NULL) {
            root = createTreeNode(data);
            return;
        }

        if (data < root->data) {
            insertData(root->left, data);
        } else {
            insertData(root->right, data);
        }
    }

    void BFSTree() {
        return BFSTree(root);
    }

    void BFSTree(Node *root) {
        if (root == NULL) return;
        queue<Node *> q;
        q.push(root);
        // cout << "Visted : " << root->data << endl;
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            cout << "Visted : " << temp->data << " Neab.. = ";
            if (temp->left != NULL) {
                cout << "L " << temp->left->data << " ";
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                cout << "R " << temp->right->data << " ";
                q.push(temp->right);
            }
            cout << endl;
        }
    }

    void DFSTree() {
        return DFSTree(root);
    }

    void DFSTree(Node *root) {
        if (root == NULL) return;
        stack<Node *> s;
        s.push(root);

        while (!s.empty()) {
            Node *temp = s.top();
            s.pop();
            cout << "Visted : " << temp->data << " ";
            if (temp->left != NULL) {
                s.push(temp->left);
            }
            if (temp->right != NULL) {
                s.push(temp->right);
            }
        }
    }

    void printTree() {
        return printTree(root);
    }

    void printTree(Node *root) {
        if (root != NULL) {
            printTree(root->left);
            cout << root->data << " ";
            printTree(root->right);
        }
    }

};

class Graph {
public:
    struct Node {
        int Dest;
        int Weight;

      Node(int D, int W = 0) : Dest(D), Weight(W) {}
    };

    struct GraphList {
        int Vertex;
        bool Check;
        vector<list<Node>> adj;

        GraphList(int V, bool B) : Vertex(V), Check(B), adj(V) {}
    };
    GraphList GB;
    Graph(int V, bool B) : GB(V,B) {}

    void createGraph(int src, int dest, int weight) {
        GB.adj[src].push_back(Node(dest, weight));
        if (!GB.Check) {
            GB.adj[dest].push_back(Node(src, weight));
        }
    }

    void BFSGraph(int vertex, bool direct) {
        vector<bool> visted(GB.Vertex, false);
        queue<int> q;
        visted[vertex] = direct;
        q.push(vertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << " Current : " << current << " ";
            for (Node it : GB.adj[current]) {
                if (!visted[it.Dest]) {
                    visted[it.Dest] = true;
                    q.push(it.Dest);
                }
            }
        }
    }

    void DFSGraph(int vertex) {
        vector<bool> visted(GB.Vertex, false);
        stack<int> s;
        s.push(vertex);

        while (!s.empty()) {
            int current = s.top();
            s.pop();
            if (!visted[current]) {
                cout << current << " ";
                visted[current] = true;
            }

            for (Node it : GB.adj[current]) {
                if (!visted[it.Dest]) {
                    s.push(it.Dest);
                }
            }
        }
    }

    void printGraph() {
        for (int i=0; i<GB.Vertex; i++) {
            cout << "Vertex" << i << " -> ";
            for (auto it : GB.adj[i]) {
                cout << "(" << it.Dest << " W= " << it.Weight << ") ";
            }
            cout << endl;
        }
    }

};

int main() {
    // Tree T;
    // T.insertData(8);
    // T.insertData(2);
    // T.insertData(9);
    // T.insertData(23);
    // T.insertData(85);
    // T.insertData(85);
    // T.insertData(5);
    // T.insertData(32);

    // T.printTree();
    // cout << endl;
    // // T.BFSTree();
    // T.DFSTree();
    // cout << endl;


    Graph G(8, true);
    G.createGraph(1, 2, 19);
    G.createGraph(2, 4, 1);
    G.createGraph(6, 2, 11);
    G.createGraph(3, 2, 3);
    G.createGraph(5, 2, 7);
    G.createGraph(4, 7, 8);
    G.createGraph(7, 1, 19);
    G.createGraph(7, 4, 2);

    G.printGraph();
    cout << endl;
    G.BFSGraph(4, true);
    cout << endl;

    return 0;
}
