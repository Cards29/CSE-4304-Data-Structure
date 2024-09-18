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

bool isEmpty() {
    return count_element == 0;
}

bool isFull() {
    return count_element == n;
}

int size() {
    return count_element;
}

int front(int queue[]) {
    return queue[front_index];
}

void EnQueue(int queue[], int x) {
    if (count_element == n) {
        return;
    }
    queue[back_index] = x;
    back_index = (back_index + 1) % n;
    count_element++;
}

void DeQueue() {
    if (count_element == 0) {
        return;
    }
    front_index = (front_index + 1) % n;
    count_element--;
}

int main() {
    int t,szy;
    cin >> n;
    int queue[n];

    while (cin >> t) {
        if (t == -1) {
            cout << "Exit" << endl;
            break;
        }
        switch (t)
        {
        case 1:
            int x;
            cin >> x;
            if (count_element == n) {
                cerr << "EnQueue: Overflow" << endl;
                break;
            }
            EnQueue(queue, x);
            cout << "EnQueue: ";
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            // cout << endl;
            // cout << front_index << ' ' << back_index;
            cout << endl;
            break;

        case 2:
            if (count_element == 0) {
                cerr << "DeQueue: Underflow" << endl;
                break;
            }
            DeQueue();
            cout << "DeQueue: ";
            if(isEmpty()){
                cout<<"queue is empty"<<endl;
                break;
            }
            szy= count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            cout << endl;
            break;

        case 3:
            if (isEmpty()) cout << "isEmpty: True" << endl;
            else cout << "isEmpty: False" << endl;
            break;
        case 4:
            if (isFull()) cout << "isFull: True" << endl;
            else cout << "isFull: False" << endl;
            break;
        case 5:
            cout << "Size: " << size() << endl;
            break;
        case 6:
            cout << "Front: " << front(queue) << endl;
            break;
        }

    }



    return 0;
}