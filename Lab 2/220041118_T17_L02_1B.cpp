#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned n;
int front_index = 0;
int back_index = 0;
int count_element;

queue<int> q1, q2;
bool isEmpty() {
    return q1.empty();
}

bool isFull() {
    return q1.size() == n;
}

int main() {
    unsigned t;
    cin >> n;
    string s;

    while (cin >> s) {
        if (s == "-1") {
            break;
        }
        if (s == "push") {
            cin >> t;
            if(!isFull())
                q1.push(t);
            else
                cerr<<"Overflow!!"<<endl;

            while(!q1.empty()){
                cout << q1.front() << ' ';
                q2.push(q1.front());
                q1.pop();
            }

            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
            cout<<endl;
        }
        else{
            if (isEmpty()){
                cerr << "Underflow!!"<<endl;
                continue;
            }
            if(q1.size()==1){
                q1.pop();
                cout<<endl;
                continue;
            }
            while (!q1.empty()) {
                if(q1.size()==1){
                    q1.pop();
                    break;
                }
                q2.push(q1.front());
                q1.pop();
            }
            while (!q2.empty()) {
                cout << q2.front() << ' ';
                q1.push(q2.front());
                q2.pop();
            }
            cout << endl;
        }
    }
    return 0;
}