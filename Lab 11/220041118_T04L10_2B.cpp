#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>

using namespace std;

class Graph {
private:
    vector<vector<int>> adj_list;
    vector<vector<int>> adj_matrix;
public:
    Graph(int k, int l) {
        vector<int> v(k, 0);
        const int p = k + 1;
        // while (k--) {
        //     adj_matrix.push_back(v);
        // }
        adj_list.resize(p);
    }
    void addMatrix(int i, int j) {
        adj_matrix[i - 1][j - 1] = 1;
    }
    void addList(int i, int j) {
        adj_list[i].push_back(j);
    }
    void displayMatrix() const {
        cout << "Adjacency Matrix:\n";
        int a, b;
        a = adj_matrix.size();
        b = adj_matrix[0].size();
        for (int i = 0; i < a; i++) {
            for (int j = 0;j < b;j++)
                cout << adj_matrix[i][j] << ' ';
            cout << endl;
        }
    }
    void displayList() const {
        cout << "Adjacency List:\n";
        int a = adj_list.size();
        for (int i = 1; i < a; i++) {
            cout << i << ": ";
            for (auto j : adj_list[i]) cout << j << ' ';
            cout << endl;
        }
    }
    int degree(int i) {
        return adj_list[i].size();
    }
    bool checkRegular() {
        int d = degree(1);
        int a = adj_list.size();
        for(int i=2; i<a;i++) {
            if(degree(i) != d) return false;
        }
        return true;
    }
    bool BFS(int start, int target){
        const int sz = adj_list.size();
        vector<bool> visited(sz, 0);
        queue<int> q;

        q.push(start);
        while(!q.empty()){
            int f = q.front();
            if(f == target) return true;
            q.pop();
            visited[f] = 1;
            for(auto i:adj_list[f]) 
                if(!visited[i])
                    q.push(i);
        }
        return false;
    }


};

int main() {
    int n, m, s, t;
    cin >> n >> m;
    Graph graph(n, m);

    while (m--) {
        int i, j;
        cin >> i >> j;
        graph.addList(i, j);
    }
    cin >> s >> t;
    (graph.BFS(s, t)) ? cout << "Yes" : cout << "No";

    return 0;
}