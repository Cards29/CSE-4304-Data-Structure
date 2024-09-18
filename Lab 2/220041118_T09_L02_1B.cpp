#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int front_index = 0;
int back_index = 0;
int count_element;

int main() {
    unsigned n, q;
    cin >> n >> q;
    stack<int> st1, st2;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;    
            st1.push(x);
            cout << "Size:" << ((st1.size()<=n)?st1.size():st1.size()-1) << ' ';
            cout << "Elements: ";
            if (st1.size() > n) {
                st1.pop();
                cout << "Overflow!" << endl;
                continue;
            }
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            while (!st2.empty()) {
                cout << st2.top() << ' ';
                st1.push(st2.top());
                st2.pop();
            }
            cout << endl;
            continue;
        }

        if (t == 2) {
            cout << "Size:" << ((st1.size() != 0) ? st1.size() - 1 : 0) << ' ';
            cout << "Elements: ";
            if (st1.size() - 1 == 0) {
                cout << "Null";
            }
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
            st2.pop();
            while (!st2.empty()) {
                cout << st2.top() << ' ';
                st1.push(st2.top());
                st2.pop();
            }
            cout << endl;
            continue;
        }

    }





    return 0;
}