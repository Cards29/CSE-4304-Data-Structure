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
    cin >> n;
    int queue[n];
    string s;
    while (cin >> s) {
        if (s.size() == 4)
            t = s[0] + s[1] + s[2] + s[3];
        else if (s.size() > 1)
            t = s[0] + s[1];
        else
            t = s[0];
        if (t == 69) {
            break;
        }
        switch (t)
        {
        case 150://push_front
            cin >> x;
            if (count_element == n) {
                cerr << "Overflow" << endl;
                break;
            }
            push_front(queue, x);
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            cout << endl;
            break;
        case 146: // push_back
            cin >> x;
            if (count_element == n) {
                cerr << "Overflow" << endl;
                break;
            }
            push_back(queue, x);
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            cout << endl;
            break;

        case 138://pop_front
            if (count_element == 0) {
                cerr << "Underflow" << endl;
                break;
            }
            pop_front();
            if (isEmpty()) {
                break;
            }
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            cout << endl;
            break;

        case 134://pop_back
            if (count_element == 0) {
                cerr << "Underflow" << endl;
                break;
            }
            pop_back();
            if (isEmpty()) {
                break;
            }
            szy = count_element;
            for (int i = front_index;szy--;i = (i + 1) % n) {
                cout << queue[i] << ' ';
            }
            cout << endl;
            break;
        case 83://size
            cout << size() << endl;
            break;
        case 70://front_index
            cout << front_index << endl;
            break;
        case 82://rear_index
            cout << back_index << endl;
            break;
        case 316://stat
            if (isFull())
                cout << "Full" << endl;
            else if (isEmpty())
                cout << "Empty" << endl;
            else
                cout << "Not full neither empty" << endl;
            break;
        }
    }
    return 0;
}