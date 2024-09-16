#include <iostream>

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
        cerr << "Overflow";
        return;
    }
    top_index++;
    stack[top_index] = x;
}

void pop()
{
    if (isEmpty())
    {
        cerr << "Underflow";
        return;
    }
    top_index--;
}

int top(int stack[])
{
    if (isEmpty())
    {
        cerr << "Underflow";
        return -157;
    }

    return stack[top_index];
}

int main()
{
    cin >> n;
    int *stack = (int *)malloc(n * sizeof(int));

    int t;
    while (cin >> t)
    {
        if (t == -1)
            break;
        switch (t)
        {
        case 1:
            int x;
            cin >> x;
            push(stack, x);
            for (int i = 0; i <= top_index; i++)
                cout << stack[i] << ' ';
            cout << endl;
            break;
        case 2:
            pop();
            for (int i = 0; i <= top_index; i++)
                cout << stack[i] << ' ';
            cout << endl;
            break;
        case 3:
            if (isEmpty())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;
        case 4:
            if (isFull())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;
        case 5:
            cout << size() << endl;
            break;
        case 6:
            cout << top(stack) << endl;
        }
    }

    free(stack);

    return 0;
}