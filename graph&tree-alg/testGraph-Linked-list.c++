#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    struct Node {
        int dest;
        int weight;

        Node(int V, int W = 0) : dest(V), weight(W) {}
    };

    struct GraphUse {
        int vtex;
        bool direct;
        vector<list<Node>> adj;

        GraphUse(int V, bool B) : vtex(V), direct(B), adj(V) {}
    };
    GraphUse GU;

public:
    Graph(int V, bool B) : GU(V,B) {}

    void graph(int src, int dest, int weg) {
        if (src < 0 || dest < 0 || src >= GU.vtex || dest >= GU.vtex) {
            cout << "Invalid edge from " << src << " to " << dest << endl;
            return;
        }

        GU.adj[src].push_back(Node(dest, weg));
        if (!GU.direct) {
            GU.adj[dest].push_back(Node(src, weg));
        }
    }

    void printGraph() {
        for (int i=0; i < GU.vtex; i++) {
            cout << "Vertex " << i << ":";
            for (auto it : GU.adj[i]) {
                cout << " -> (Dest: " << it.dest << ", Weight: " << it.weight << ")";
            }
            cout << endl;
        }
    }

};

int main() {
    Graph G(6, false);
    G.graph(0, 1, 4);
    G.graph(0, 14, 0);
    G.graph(1, 1, 3);
    G.graph(2, 18, 0);
    G.graph(6, 2, 0);
    G.graph(9, 5, 9);
    G.graph(2, 3, 3);

    cout << "- Graph :" << endl;
    G.printGraph();
    cout << endl;
}
