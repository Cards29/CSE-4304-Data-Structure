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
        adj_matrix[j - 1][i - 1] = 1;
    }
    void addList(int i, int j) {
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
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
    (graph.checkRegular()) ? cout << "Yes" : cout << "No";

    return 0;
}