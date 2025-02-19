#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int N = 1e5 + 10;
int parent[N];
int _rank[N];

void make(int v) {
    parent[v] = v;
}

int find(int v) {
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if(ra != rb) {
        if(_rank[ra] > _rank[rb]) swap(ra,rb);
        parent[ra] = rb;
        if(_rank[ra] == _rank[rb]) _rank[rb]++;
    }
}

int main() {
    int n, t, task;
    cin >> n;

    while(cin >> t) {
        switch (t) {
        case 1:
            for(int i = 0; i < n; i++) make(i);
            for(int i = 0; i < n; i++) cout << parent[i] << "(" << _rank[i] << ") ";
            cout << endl;
            break;
        case 2:
            int x;
            cin >> x;
            cout << find(x) << endl;
            break;
        case 3:
            int u, v;
            cin >> u >> v;
            Union(u,v);
            for(int i = 0; i < n; i++) cout << parent[i] << "(" << _rank[i] << ") ";
            cout << endl;
            break;
        case 4:
            for(int i = 0; i < n; i++) cout << parent[i] << "(" << _rank[i] << ") ";
            cout << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}