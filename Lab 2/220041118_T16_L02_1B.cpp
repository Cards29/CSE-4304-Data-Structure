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

int back(int queue[]) {
    if (back_index >= 1)
        return queue[back_index - 1];
    else
        return queue[n - 1];

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

void print_queue(int queue[]) {
    cout << "Current Size : " << size() << endl
        << "Full? : " << ((isFull()) ? "Yes" : "No") << endl
        << "Empty? : " << ((isEmpty()) ? "Yes" : "No") << endl
        << "Front Element : ";
    if (!isEmpty())
        cout << front(queue) << endl;
    else
        cout << "-" << endl;
    cout << "Front Index : " << front_index << endl
        << "Rear Index : " << back_index << endl
        << "Rear Element : ";
    if (!isEmpty())
        cout << back(queue) << endl;
    else
        cout << "-" << endl;
    cout << "Queue Elements : ";
    int szy = count_element;
    if (szy == 0)
        cout << '-';
    else
        for (int i = front_index;szy--;i = (i + 1) % n)
            cout << queue[i] << ' ';
    cout << endl;
}

int main() {
    int t;
    string s;
    cin >> n;
    int queue[n];

    while (cin >> s) {
        if (s == "-1")
            break;

        if (s == "E") {
            cin >> t;
            if (isFull())
                cout << "Overflow!!" << endl;
            else
                EnQueue(queue, t);
            print_queue(queue);
        }

        else {
            if (isEmpty())
                cout << "Underflow!!" << endl;
            else
                DeQueue();
            print_queue(queue);
        }

    }

    return 0;
}