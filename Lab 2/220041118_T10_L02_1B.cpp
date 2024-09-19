#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 5;
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

void push_back(int queue[], int x) {
    if (count_element == n) {
        return;
    }
    queue[back_index] = x;
    back_index = (back_index + 1) % n;
    count_element++;
}

void push_front(int queue[], int x) {
    if (count_element == n) {
        return;
    }
    front_index--;
    if (front_index < 0) front_index += n;
    queue[front_index] = x;
    count_element++;
}

void pop_front() {
    if (count_element == 0) {
        return;
    }
    front_index = (front_index + 1) % n;
    count_element--;
}

void pop_back() {
    if (count_element == 0) {
        return;
    }
    back_index--;
    if (back_index < 0) back_index += n;
    count_element--;
}


int main() {
    int t, szy, x;
    int queue[n];

    while (cin >> t) {
        if (t == 6) {
            cout << "Exit" << endl;
            break;
        }
        switch (t)
        {
        case 1://push_front
            cin >> x;
            if (count_element == n) {
                cerr << "Overflow" << endl;
                break;
            }
            push_front(queue, x);
            // cout << front_index << endl;
            // cout << back_index << endl;
            // cout << "push_back: ";
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            cout << endl;
            break;
        case 2: // push_back
            cin >> x;
            if (count_element == n) {
                cerr << "Overflow" << endl;
                break;
            }
            push_back(queue, x);
            // cout << front_index << endl;
            // cout << back_index << endl;
            // cout << "push_back: ";
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            // cout << endl;
            // cout << front_index << ' ' << back_index;
            cout << endl;
            break;

        case 3:
            if (count_element == 0) {
                cerr << "Underflow" << endl;
                break;
            }
            pop_front();
            // cout << front_index << endl;
            // cout << back_index << endl;
            // cout << "DeQueue: ";
            if (isEmpty()) {
                cout << "queue is empty" << endl;
                break;
            }
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            cout << endl;
            break;


        case 4://pop_back
            if (count_element == 0) {
                cerr << "Underflow" << endl;
                break;
            }
            pop_back();
            // cout << front_index << endl;
            // cout << back_index << endl;
            // cout << "DeQueue: ";
            if (isEmpty()) {
                cout << "deque is empty" << endl;
                break;
            }
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            cout << endl;
            break;
        case 5:
            cout << "Size: " << size() << endl;
            break;
        }

    }



    return 0;
}