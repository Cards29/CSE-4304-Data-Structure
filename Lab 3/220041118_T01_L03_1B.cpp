#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void heapify(int i, int sz, vector<int>& v) {
    // cout << "heapify called" << endl;
    int l = 2 * i, r = 2 * i + 1, largest;
    // if (l > sz && r > sz) return;

    if (l <= sz && v[l] > v[i]) largest = l;
    else largest = i;

    if (r <= sz && v[r] > v[largest]) largest = r;
    // cout << i << ' ' << v[i] << ' ' << largest << ' ' << v[largest] << endl;
    if (largest != i) {
        int temp = v[i];
        v[i] = v[largest];
        v[largest] = temp;
        heapify(largest, sz, v);
    }

}

void build_max_heap(int sz, vector<int>& v) {
    // cout << "build called " << sz << endl;
    for (int i = sz / 2;i >= 1;i--)
        heapify(i, sz, v);
}

void heap_sort(int& sz, vector<int>& v) {
    build_max_heap(sz, v);
    cout << "Max Heap: ";
    for (int i = 1;i <= sz;i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
    int t = sz;
    for (;sz >= 2;) {
        int temp = v[1];
        v[1] = v[sz];
        v[sz] = temp;
        sz--;
        heapify(1, sz, v);
    }
    sz = t;
}

int main() {
    int t, sz;
    vector<int> v;
    v.push_back(0);
    while (cin >> t) {
        if (t == -1) break;
        v.push_back(t);
    }

    sz = v.size() - 1;
    // build_max_heap(v.size() - 1, v);
    heap_sort(sz, v);
    cout << "Sorted: ";
    for (int i = sz;i >= 1;i--) {
        cout << v[i] << ' ';
    }
    cout << endl;


    return 0;
}