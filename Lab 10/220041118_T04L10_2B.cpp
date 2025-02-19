#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int N = 1e5 + 10;
int parent[N];
int _rank[N];
vector<int> rep1;
vector<int> rep2;

void make(int v) {
    parent[v] = v;
    _rank[v] = 0;
}

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    int ra = find(a);
    int rb = find(b);

    if (ra != rb) {
        if (_rank[ra] < _rank[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (_rank[ra] == _rank[rb]) _rank[ra]++;
    }else{
        rep1.push_back(a);
        rep2.push_back(b);
    }   
}

int main() {
    int n, t, k;
    cin >> n;
    for (int i = 1; i <= n; i++) make(i);
    t = n - 1;
    while (t--) {
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    vector<int> heads;
    int headIndex = 0;
    for (int i = 1; i <= n; i++) 
        if(i == find(i)) heads.push_back(i);
    
    cout << rep1.size() << endl;;

    k = rep1.size();
    for(int i=0;i<k;i++){
        cout<<rep1[i]<<' '<<rep2[i]<<"  "<<heads[headIndex] <<' ' << heads[++headIndex]<<endl;
        headIndex++;
    }
    



    return 0;
}