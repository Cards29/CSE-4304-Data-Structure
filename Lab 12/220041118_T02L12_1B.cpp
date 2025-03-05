#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <tuple>
#include <utility>

using namespace std;

class Graph {
private:
    vector<vector<int>> adj_list;
    vector<vector<int>> adj_matrix;
    vector<int> order;
    vector<pair<int, int>> distance;
    vector<int> color;
    vector<int> parent;
    vector<pair<int, int>> edges;
    int time;
public:
    Graph(int v, int e) {
        adj_list.resize(v + 1);
        distance.resize(v + 1);
        color.resize(v + 1, 0);
        parent.resize(v + 1, 0);
    }

    void addList(int i, int j) {
        adj_list[i].push_back(j);
    }

    void displayList() const {
        cout << "\n\nAdjacency List:\n";
        int a = adj_list.size();
        for (int i = 1; i < a; i++) {
            cout << i << ": ";
            for (auto j : adj_list[i]) cout << j << ' ';
            cout << endl;
        }
        cout << endl;
    }

    void DFS(int start) {
        time = 0;
        for(int u=1; u < adj_list.size(); u++)
            if(color[u] == 0)
                DFS_VISIT(u);
    }

    void DFS_VISIT(int u) {
        time++;
        distance[u].first = time;
        color[u] = 1;
        order.push_back(u);

        for(auto v:adj_list[u]) 
            if(color[v] == 0){
                parent[v] = u;
                DFS_VISIT(v);
            }
        
        color[u] = 2;
        time++;
        distance[u].second = time;
    }

    void displayOrder() const {
        cout << "DFS order: ";
        for (auto i : order)
            cout << i << ' ';
        cout << endl << endl;
    }

    void displayDistance() const {
        cout << "Timestamps of Vertex(discovery/finishing):\n";
        for (int i = 1; i < adj_list.size(); i++)
            cout << i << "(" << distance[i].first << "/" << distance[i].second << ")\n";
        cout << endl;
        cout << endl;
    }

    vector<int> path(int vertex, int start) {
        vector<int> v;
        v.push_back(vertex);
        while (vertex != start) {
            vertex = parent[vertex];
            v.push_back(vertex);
        }
        return v;
    }

    void displayPath(int start) {
        cout << "Paths from source:\n";
        for (int i = 1; i < adj_list.size(); i++) {
            vector<int> v = path(i, start);
            cout << i << ": ";
            for (int j = v.size() - 1; j >= 0; j--) {
                if (j != 0)
                    cout << v[j] << "->";
                else
                    cout << v[j];
            }
            cout << endl;
        }
        cout << endl;
    }

    void displayEdges() {
        cout << "Edges of BFS tree: \n";
        for (auto i : edges) {
            cout << i.first << ' ' << i.second << endl;
        }
    }
};

int main() {
    int v, e, s, t;
    cin >> v >> e;
    Graph graph(v, e);

    while (e--) {
        int i, j;
        cin >> i >> j;
        graph.addList(i, j);
    }

    graph.displayList();
    cout << endl;

    graph.DFS(1);
    graph.displayOrder();
    graph.displayDistance();
    // graph.displayPath(s);
    // graph.displayEdges();

    return 0;
}