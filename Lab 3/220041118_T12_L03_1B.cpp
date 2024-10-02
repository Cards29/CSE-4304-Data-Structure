#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int t;
    while (cin >> t && t != -1) {
        pq.push(t);
    }
    int cost = 0;
    while (pq.size() > 1) {
        int num1, num2;
        num1 = pq.top(); pq.pop();
        num2 = pq.top(); pq.pop();
        cost += num1 + num2;
        pq.push(num1 + num2);
    }

    cout << cost << endl;
    return 0;
}
