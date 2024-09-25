#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int sz;
void heapify(int i, int sz, int heap[]) {
    // cout << "heapify called" << endl;
    int l = 2 * i, r = 2 * i + 1, largest;
    // if (l > sz && r > sz) return;
    if (l <= sz && heap[l] < heap[i]) largest = l;
    else largest = i;
    if (r <= sz && heap[r] < heap[largest]) largest = r;
    // cout << i << ' ' << heap[i] << ' ' << largest << ' ' << heap[largest] << endl;
    if (largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        heapify(largest, sz, heap);
    }
}
void build_max_heap(int sz, int heap[]) {
    // cout << "build called " << sz << endl;
    for (int i = sz / 2;i >= 1;i--)
        heapify(i, sz, heap);
}
void heap_sort(int& sz, int heap[]) {
    cout << endl;
    int t = sz;
    for (;sz >= 2;) {
        int temp = heap[1];
        heap[1] = heap[sz];
        heap[sz] = temp;
        sz--;
        heapify(1, sz, heap);
    }
    sz = t;
}
void print_min_heap(int sz, int heap[]){
    for (int i = 1;i <= sz;i++) {
        cout << heap[i] << ' ';
    }
    cout<<endl;
}
int Heap_Minimum(int heap[]){
    return heap[1];
}
int Heap_extract_min(int heap[]){
    int min = heap[1];
    heap[1]=heap[sz];
    heap[sz]=min;
    sz--;
    heapify(1,sz,heap);

    return min;
}
void Min_heap_insert(int value, int heap[]){
    sz++;
    realloc(heap,sizeof(int)*(sz+1));
    heap[sz]=value;
    int i=sz;
    while(i>1 && heap[i/2]>heap[i]){
        int temp = heap[i];
        heap[i]=heap[i/2];
        heap[i/2]=temp;
        i/=2;
    }
}
void Heap_decrease_key(int i, int k, int heap[]){
    heap[i]-=k;
    while (i > 1 && heap[i / 2] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i /= 2;
    }
}
void Heap_increase_key(int i, int k, int heap[]){
    heap[i] += k;
    heapify(i, sz, heap);
}
int main() {
    int t;
    vector<int> v;
    v.push_back(0);
    while (cin >> t) {
        if (t == -1) break;
        v.push_back(t);
    }

    int n=v.size();
    int* heap=(int*)malloc(sizeof(int)*v.size());
    sz = n - 1;

    for(int i=0;i<n;i++) heap[i]=v[i];

    build_max_heap(sz, heap);
    cout << "Min Heap: ";
    print_min_heap(sz,heap);

    while(cin>>t){
        if(t==157)break;

        switch (t){
        case 1:
            cout<<Heap_Minimum(heap)<<endl;
            print_min_heap(sz,heap);
            break;
        case 2:
            if(sz<1){
                cout<<"Underflow!!"<<endl;
                break;
            }
            cout<<Heap_extract_min(heap)<<endl;
            print_min_heap(sz, heap);
            break;
        case 3:
            int x;
            cin>>x;
            Min_heap_insert(x,heap);
            print_min_heap(sz, heap);
            break;
        case 4:
            int i,k;
            cin>>i>>k;
            Heap_decrease_key(i,k,heap);
            print_min_heap(sz,heap);
            break;
        case 5:
            int i1, k1;
            cin >> i1 >> k1;
            Heap_increase_key(i1, k1, heap);
            print_min_heap(sz, heap);
            break;
        }
    }

    // heap_sort(sz, heap);
    // cout << "Sorted: ";
    // for (int i = 1;i <= sz;i++) {
    //     cout << heap[i] << ' ';
    // }
    // cout << endl;

    free(heap);
    return 0;
}