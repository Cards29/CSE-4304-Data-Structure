#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    size_t count = 0;
    cin >> n;
    queue<int> q;
    stack<int> st1, st;

    for (int i = 0;i < n;i++) {
        int k; cin >> k;
        q.push(k);
    }
    for (int i = 0;i < n;i++) {
        int k; cin >> k;
        st1.push(k);
    }
    while (!st1.empty()) {
        st.push(st1.top());
        st1.pop();
    }

    while (!q.empty()) {
        if(count==q.size())
            break;
        if (q.front() == st.top()) {
            st.pop();
            q.pop();
            count=0;
        }
        else {
            int t = q.front();
            q.pop();
            q.push(t);
            count++;
        }
    }

    cout<<count<<endl;

    return 0;
}
