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
    vector<int> inDegrees;
    queue<int> q;
public:
    Graph(int k, int l) {
        vector<int> v(k, 0);
        const int p = k + 1;
        // while (k--) {
        //     adj_matrix.push_back(v);
        // }
        adj_list.resize(p);
        inDegrees.resize(p, 0);
    }
    void addMatrix(int i, int j) {
        adj_matrix[i - 1][j - 1] = 1;
        adj_matrix[j - 1][i - 1] = 1;
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
        for (int i = 0; i < a - 1; i++) {
            cout << i << ": ";
            for (auto j : adj_list[i]) cout << j << ' ';
            cout << endl;
        }
    }
    void calculateInDegree() {
        int a = adj_list.size();
        for (int i = 0; i < a - 1; i++) {
            for (auto j : adj_list[i]) inDegrees[j]++;
        }
    }

    void BFS() {
        vector<int> ans;
        for (int i = 0; i < inDegrees.size() - 1;i++) {
            // cout << inDegrees[i] << ' ';
            if (inDegrees[i] == 0) q.push(i);
        }
        // cout << endl;
        if (q.empty()) {
            cout << "[ ]\n";
            return;
        }
        while (!q.empty()) {
            int f = q.front();
            ans.push_back(f);
            q.pop();
            for (auto&& i : adj_list[f]) {
                inDegrees[i]--;
                if (inDegrees[i] == 0) q.push(i);
            }
        }
        if (ans.size() < adj_list.size() - 1) {
            cout << "[ ]\n";
            return;
        }
        for (auto i : ans) cout << i << ' ';
        cout << endl;
    }

};

int main() {
    int n, m;
    cin >> n >> m;
    Graph graph(n, m);

    while (m--) {
        int i, j;
        cin >> i >> j;
        graph.addList(i, j);
    }
    graph.calculateInDegree();
    graph.BFS();

    return 0;
}