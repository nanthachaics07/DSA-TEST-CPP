#include <csignal>
#include <cstdlib>
#include <iostream>
// #include <iterator>
#include <signal.h>
#include <stdexcept>
#include <unistd.h>
#include <queue>
#include <stack>
#include <vector>
#include <list>

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

    void BFSTree(Node *root) {
        if (root == NULL) return;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            if (temp->left != NULL) {
                BFSTree(temp->left);
            }
            if (temp->right != NULL) {
                BFSTree(temp->right);
            }
        }
    }

    void DFSTree(Node *root) {
        if (root == NULL) return;
        stack<Node *> s;
        s.push(root);
        while (!s.empty()) {
            Node *temp = s.top();
            s.pop();
            if (temp->left != NULL) {
                DFSTree(temp->left);
            }
            if (temp->right != NULL) {
                DFSTree(temp->right);
            }
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


class Graph {
public:
    struct Node {
        int desc;
        int weight;
        Node(int D, int W = 0) : desc(D), weight(W) {}
    };

    struct GContainer {
        int vertex;
        bool directed;
        vector<list<Node>> adj;
        GContainer(int N, bool B) : vertex(N), directed(B), adj(N) {}
    };
    GContainer GC;
    Graph(int N, bool B) : GC(N, B) {}

    void insertGraph(int vertex, int dest, int weight) {
        if (vertex < 0 || dest < 0 || weight < 0) {
            throw runtime_error("Please insert numbers greater than or equal to 0");
        }
        GC.adj[vertex].push_back(Node(dest, weight));
        if (!GC.directed) {
            GC.adj[dest].push_back(Node(vertex, weight));
        }
    }

// public:

    void BFSGraph(int vertex) {
        // if (vertex < 0 || vertex >= GC.vertex) {
        //     throw out_of_range("Vertex out of range");
        // }
        vector<bool> visited(GC.vertex, false);
        queue<int> q;
        visited[vertex] = true;
        q.push(vertex);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << "Current : " << current << " ";
            for (Node node : GC.adj[current]) {
                if (!visited[node.desc]) {
                    visited[node.desc] = true;
                    q.push(node.desc);
                }
            }
        }
    }

    void DFSGraph(int vertex) {
        // if (vertex < 0 || vertex >= GC.vertex) {
        //     throw out_of_range("Vertex out of range");
        // }
        vector<bool> visited(GC.vertex, false);
        stack<int> s;
        s.push(vertex);
        while (!s.empty()) {
            int current = s.top();
            s.pop();
            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }
            for (Node node : GC.adj[current]) {
                if (!visited[node.desc]) {
                    s.push(node.desc);
                }
            }
        }
    }

    void addEdge(int vertex, int dest, int weight) {
        insertGraph(vertex, dest, weight);
    }

    void printGraph() {
        for (int i = 0; i < GC.vertex; i++) {
            cout << "From vertex " << i << ":" << endl;
            for (auto const& node : GC.adj[i]) {
                cout << "  To: " << node.desc << " Weight: " << node.weight << endl;
            }
        }
    }

};


void signalHandler(int signal) {
    cout << "Interrupt signal (" << signal << ") received.\n";
    exit(signal);
}

int main() {
    signal(SIGINT, signalHandler);

    // Tree t;
    // t.insertTree(3);
    // t.insertTree(6);
    // t.insertTree(2);
    // t.insertTree(34);
    // t.insertTree(83);
    // t.insertTree(1);
    // t.insertTree(38);
    // cout << "Travel : ";
    // t.travelTree();
    // cout << endl;

    Graph g(5, true); // 5 vertices, directed graph

    g.addEdge(0, 1, 10);
    g.addEdge(2, 3, 20);
    g.addEdge(0, 2, 30);
    g.addEdge(0, 3, 40);
    g.addEdge(0, 4, 50);
    g.addEdge(1, 2, 60);
    g.addEdge(2, 3, 70);

    cout << "Graph:" << endl;
    g.printGraph();
    cout << endl;

    cout << "BFS starting from vertex 0:" << endl;
    g.BFSGraph(2);
    cout << endl;

    cout << "DFS starting from vertex 0:" << endl;
    g.DFSGraph(2);
    cout << endl;


    while(false) {
        cout << "Sleep......" << endl;
        sleep(1);
    }
    return 0;
}
