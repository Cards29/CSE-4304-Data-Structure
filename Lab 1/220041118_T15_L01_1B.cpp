#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int top_index = -1;
int n;

bool isEmpty()
{
    // cout << "true" << endl;
    return (top_index == -1);
}

bool isFull()
{
    // cout << "true" << endl;
    return (top_index == n - 1);
}

int size()
{
    return top_index + 1;
}

void push(int stack[], int x)
{
    if (isFull())
    {
        cerr << "Overflow !!!" << endl;
        return;
    }
    top_index++;
    stack[top_index] = x;
}

void pop()
{
    if (isEmpty())
    {
        cerr << "Underflow !!!" << endl;
        return;
    }
    top_index--;
}

int top(int stack[])
{
    if (isEmpty())
    {
        // cerr << "Underflow !!!";
        return 0;
    }

    return stack[top_index];
}

int main()
{
    cin >> n;
    int* stack = (int*)malloc(n * sizeof(int));
    string str;
    while (getline(cin, str))
    {
        if (str == "/")
            break;
        char c;
        int val;
        stringstream ss(str);

        if (str.size() > 1) {
            ss >> c >> val;
        }
        else
            ss >> c;

        switch (c)
        {
        case '+':
            push(stack, val);
            cout << "Size : " << size() << endl
                << "Stack elements : ";
            for (int i = 0; i <= top_index; i++)
                cout << stack[i] << ' ';
            cout << endl
                << "Top element : " << top(stack) << endl
                << "isFull : ";
            (isFull()) ? cout << "True" << endl : cout << "False" << endl;
            cout << "isEmpty : ";
            (isEmpty()) ? cout << "True" << endl : cout << "False" << endl;
            break;
        case '-':
            pop();
            cout << "Size : " << size() << endl
                << "Stack elements : ";
            for (int i = 0; i <= top_index; i++)
                cout << stack[i] << ' ';
            cout << endl
                << "Top element : " << top(stack) << endl
                << "isFull : ";
            (isFull()) ? cout << "True" << endl : cout << "False" << endl;
            cout << "isEmpty : ";
            (isEmpty()) ? cout << "True" << endl : cout << "False" << endl;
            break;
        }
    }

    free(stack);

    return 0;
}