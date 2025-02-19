#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
const int N = 1e5 + 10;
int parent[N];
// int _rank[N];
int _size[N];
multiset<int> sizes;

void make(int v) {
    parent[v] = v;
    _size[v] = 1;
    sizes.insert(1);
}

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int a, int b) {
    sizes.erase(sizes.find(_size[a]));
    sizes.erase(sizes.find(_size[b]));
    sizes.insert(_size[a] + _size[b]);
}

void Union(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra != rb) {
        if (_size[ra] < _size[rb]) swap(ra, rb);
        parent[rb] = ra;
        merge(ra, rb);
        _size[ra] += _size[rb];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) make(i);
    while (m--) {
        int u, v, ct = 0;
        cin >> u >> v;
        Union(u, v);
        for (int i = 1; i <= n; i++) if(find(i) == i) ct++;
        cout << ct << " " << *(--sizes.end()) << endl;
    }
    


    return 0;
}