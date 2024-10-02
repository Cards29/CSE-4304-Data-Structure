#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    vector<int> ans(n, -1);
    priority_queue<int>pq;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        v.push_back(k);
    }

    for (int i = 0; i < n; ++i) {
        pq.push(v[i]);
        if (pq.size() >= 3) {
            int temp1, temp2;
            temp1 = pq.top(); pq.pop();
            temp2 = pq.top(); pq.pop();

            ans[i] = temp1 * temp2 * pq.top();
            pq.push(temp1);
            pq.push(temp2);
        }
    }

    for (int i : ans) cout << i << endl;


    return 0;
}