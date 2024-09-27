#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void move1(queue<int>& q) {
    q.push(q.front());
    q.pop();
}

void move2(queue<int>& q) {
    q.pop();
}

void stoneGame(queue<int>& q) {
    string s1 = "Daiyan", s2 = "Ishraq";
    int turn = 1;

    if (q.size() == 1) {
        cout << s2 << ' ' << q.front() << endl;
        return;
    }

    while (q.size() > 1) {
        if (turn % 2) {
            move1(q);
            move2(q);
        }
        else {
            move1(q);
            move1(q);
            move2(q);
        }
        turn++;
    }
    turn--;
    cout << ((turn % 2) ? s1 : s2) << ' ' << q.front() << endl;

}

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0;i < n;i++) {
        int k;
        cin >> k;
        q.push(k);
    }
    stoneGame(q);


    return 0;
}