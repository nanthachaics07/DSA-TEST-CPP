#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Tree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int D) : data(D), left(NULL), right(NULL) {}
    };

public:
    Node *root;
    Tree() : root(NULL) {}

    Node* createTree(int data) {
        return new Node(data);
    }

    void insertTree(int data) {
        insertTree(root, data);
    }

    void insertTree(Node *&root, int data) {
        if (root == NULL) {
            root = createTree(data);
            return;
        }

        if (data < root->data) {
            insertTree(root->left, data);
        } else {
            insertTree(root->right, data);
        }
    }

    void BFSTree() {
        BFSTree(root);
    }

    void BFSTree(Node *root) {
        if (root == NULL) return;
        queue<Node *> q;
        q.push(root);
        cout << "Start: " << root->data << endl;

        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            cout << "Visited: " << temp->data << " Neighbors: ";
            if (temp->left != NULL) {
                cout << "L: " << temp->left->data << " ";
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                cout << "R: " << temp->right->data << " ";
                q.push(temp->right);
            }
            cout << endl;
        }
    }

    void DFSTree() {
        DFSTree(root);
    }

    void DFSTree(Node *root) {
        if (root == NULL) return;
        stack<Node *> s;
        s.push(root);
        cout << "Start: " << root->data << endl;

        while (!s.empty()) {
            Node *temp = s.top();
            s.pop();
            cout << "Visited: " << temp->data << endl;
            if (temp->right != NULL) {
                s.push(temp->right);
            }
            if (temp->left != NULL) {
                s.push(temp->left);
            }
        }
    }

    void printTree() {
        printTree(root);
    }

    void printTree(Node *root) {
        if (root != NULL) {
            printTree(root->left);
            cout << root->data << " ";
            printTree(root->right);
        }
    }

    void deleteTree() {
        deleteTree(root);
        root = NULL;
    }

    void deleteTree(Node* root) {
        if (root != NULL) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }
};

class Graph {
private:
    struct Node {
        int data;
        int weight;

        Node(int D, int W = 0) : data(D), weight(W) {}
    };

    struct GraphUse {
        int vtex;
        bool detec;
        vector<list<Node>> adj;

        GraphUse(int V, bool D) : vtex(V), detec(D), adj(V) {}
    };
    GraphUse GB;

public:
    Graph(int V, bool B) : GB(V, B) {}

    void createGraph(int src, int dest, int weight) {
        GB.adj[src].push_back(Node(dest, weight));
        if (!GB.detec) {
            GB.adj[dest].push_back(Node(src, weight));
        }
    }

    void BFSGraphUnit(int vertx, bool direct) {
        vector<bool> visited(GB.vtex, false);
        queue<int> q;
        visited[vertx] = direct;
        q.push(vertx);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (Node node : GB.adj[current]) {
                if (!visited[node.data]) {
                    visited[node.data] = true;
                    q.push(node.data);
                }
            }
        }
    }

    void DFSGraphUnit(int vertx, bool direct) {
        vector<bool> visited(GB.vtex, false);
        stack<int> s;
        s.push(vertx);

        while (!s.empty()) {
            int current = s.top();
            s.pop();
            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }

            for (Node node : GB.adj[current]) {
                if (!visited[node.data]) {
                    s.push(node.data);
                }
            }
        }
    }

    void printGraph() {
        for (int i = 0; i < GB.vtex; i++) {
            cout << "Vertex " << i << " -> ";
            for (auto it : GB.adj[i]) {
                cout << "(" << it.data << ", weight: " << it.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Tree t;
    t.insertTree(19);
    t.insertTree(54);
    t.insertTree(8);
    t.insertTree(3);
    t.insertTree(6);
    t.insertTree(49);
    t.insertTree(1);
    cout << "Tree: ";
    t.printTree();
    cout << "\n>>>> BFSTree " << endl;
    t.BFSTree();
    cout << "\n>>>> DFSTree " << endl;
    t.DFSTree();
    t.deleteTree();
    cout << "\n========================" << endl;

    Graph g(5, true);
    g.createGraph(0, 1, 10);
    g.createGraph(0, 4, 20);
    g.createGraph(1, 2, 30);
    g.createGraph(1, 3, 40);
    g.createGraph(1, 4, 50);
    g.createGraph(3, 2, 60);
    g.createGraph(3, 4, 70);
    cout << "Graph: " << endl;
    g.printGraph();
    cout << "BFSGraph: " << endl;
    g.BFSGraphUnit(0, true);
    cout << endl;
    cout << "DFSGraph: " << endl;
    g.DFSGraphUnit(0, true);
    cout << "\n========================" << endl;

    return 0;
}
