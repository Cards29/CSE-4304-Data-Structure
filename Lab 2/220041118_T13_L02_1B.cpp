#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void stoneGame(int n) {
    queue<int> q;
    int count = 0;

    if (n == 1) {
        cout << "Discarded cards: " << endl;
        cout << "Remaining card: " << 1 << endl;
        return;
    }

    for (int i = 1;i <= n;i++)
        q.push(i);
    cout << "Discarded cards: ";
    while (!q.empty()) {
        if (q.size() == 1) break;
        if ((n - count) != 2)
            cout << q.front() << ", ";
        else
            cout << q.front();
        count++;
        q.pop();
        if (q.size() == 1)break;
        q.push(q.front());
        q.pop();
    }
    cout << endl << "Remaining card: " << q.front() << endl;

    return;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        stoneGame(n);
    }

    return 0;
}