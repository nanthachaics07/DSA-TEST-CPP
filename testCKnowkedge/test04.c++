// #include <cinttypes>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
    Node *createNode(int data) {
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

    void BFSTree(Node *root) {
        if (root == NULL) return;
        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            cout << " Visted : " << temp->data << " Neuber -> ";
            if (temp->left != NULL) {
                cout << temp->left->data << " ";
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                cout << temp->right->data << " ";
                q.push(temp->right);
            }
        }
    }

    void DFSTree(Node *root) {
        if (root != NULL) {
            stack<Node *> s;
            s.push(root);

            while (!s.empty()) {
                Node *temp = s.top();
                s.pop();
                cout << " Visted : " << temp->data;
                if (temp->left != NULL) {
                    s.push(temp->left);
                }
                if (temp->right != NULL) {
                    s.push(temp->right);
                }
            }
        }
    }

    void printTree(Node *root) {
        if (root != NULL) {
            printTree(root->left);
            cout << root->data << " ";
            printTree(root->right);
        }
    }

    void deleteTree(Node *root) {
        if (root != NULL) {
            deleteTree(root->left);
            deleteTree(root->right);
            delete root;
        }
    }


public:
    Tree() : root(NULL) {}
    ~Tree() {
        deleteTree(root);
    }

    void insertTree(int data) {
        return insertTree(root, data);
    }

    void printTree() {
        return printTree(root);
    }

    void BFSTree() {
        return BFSTree(root);
    }

};


class Graph {
private:
    struct Node {
        int dist;
        int weght;
        Node(int D, int W=0) : dist(D), weght(W) {}
    };

    struct GNode {
        int vertex;
        bool direct;
        vector<list<Node>> adj;
        GNode(int A, bool B) : vertex(A), direct(B), adj(A) {}
    };
    GNode GN;

public:
    void insertGraph(int src, int dest, int weght) {
        GN.adj[src].push_back(Node(dest, weght));
        if (!GN.direct) {
            GN.adj[dest].push_back(Node(src, weght));
        }
    }

    void BFSGraph(int vertex) {
        vector<bool> visted(GN.vertex, false);
        queue<int> q;
        visted[vertex] = true; // decare true if wanna search
        q.push(vertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << "Visted : " << current << " ";
            for (Node const& it : GN.adj[current]) {
                if (!visted[it.dist]) {
                    visted[it.dist] = true;
                    q.push(it.dist);
                }
            }
        }
    }

    void DFSGraph(int vertex) {
        vector<bool> visted(GN.vertex, false);
        stack<int> s;
        s.push(vertex);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visted[current]) {
                cout << "Visted" << current << " ";
                visted[current] = true;
            }

            for (Node const& node : GN.adj[current]) {
                if (!visted[node.dist]) {
                    s.push(node.dist);
                }
            }
        }
    }

    void printGraph() {
        int len = GN.adj.size();
        for (int i=0; i<len-1; i++) {
            for (auto node : GN.adj[i]) {
                cout << node.dist << " ";
            }
        }
    }

};

class Linklist {
private:
    struct Node {
        int data;
        Node *next;
        Node *prev;
        Node(int D) : data(D), next(NULL), prev(NULL) {}
    };
    Node *current;

    Node *createNode(int data) {
        return new Node(data);
    }

    Node *insertDubbleList(Node *current, int data) {
        if (current == NULL) {
            return createNode(data);
        }
        if (current->next == NULL) {
            Node *newnode = createNode(data);
            current->next = newnode;
            newnode->prev = current;
        } else {
            current->next = insertDubbleList(current->next, data);
            current->next->prev = current;
        }
        return current;
    }

    Node *insertSingleList(Node *current, int data) {
        if (current == NULL) {
            return createNode(data);
        }
        current->next = insertSingleList(current->next, data);
        return current;
    }

    void printNode(Node *node) {
        if (node != NULL) {
            cout << node->data << " ";
            printNode(node->next);
        }
        // cout << endl;
    }

    Node *deleteNode(Node *current, int key) {
        if (current == NULL) return NULL;
        if (current->data == key) {
            Node *temp = current->next;
            if (temp != NULL) {
                temp->prev = current->prev;
            }
            if (current->prev != NULL) {
                current->prev->next = temp;
            }  else {
                this->current = temp;
            }
            delete current;
            return temp;
        } else {
            current->next = deleteNode(current->next, key);
        }
        return current;
    }

    void clearNode(Node *root) {
        if (root != NULL) {
            clearNode(root->next);
            delete root;
        }
    }

public:
    Linklist() : current(NULL) {}
    ~Linklist() {
        clearNode(current);
    }

    void insertDubbleList(int data) {
        current = insertDubbleList(current, data);
    }

    void insertSingleList(int data) {
        current = insertSingleList(current, data);
    }

    void deleteNode(int key) {
        current = deleteNode(current, key);
    }

    void printNode() {
        printNode(current);
    }

};


int main() {
    // Tree t;
    // t.insertTree(4);
    // t.insertTree(5);
    // t.insertTree(45);
    // t.insertTree(9);
    // t.insertTree(34);
    // t.insertTree(41);
    // t.insertTree(14);
    // t.insertTree(21);
    // t.insertTree(33);

    // cout << " Tree is : ";
    // t.printTree();
    // cout << endl;

    Linklist list;
    // list.insertDubbleList(10);
    // list.insertDubbleList(5);
    // list.insertDubbleList(20);
    // list.insertDubbleList(15);

    list.insertSingleList(10);
    list.insertSingleList(3);
    list.insertSingleList(23);
    list.insertSingleList(30);
    list.insertSingleList(54);

    list.printNode(); // Output: 5 10 15 20
    cout << endl;

    list.deleteNode(10);

    list.printNode(); // Output: 5 15 20
    cout << endl;

    return 0;
}
