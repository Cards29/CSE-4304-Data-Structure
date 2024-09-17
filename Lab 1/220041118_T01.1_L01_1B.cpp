#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    size_t sz;
    int t;
    cin >> sz;
    stack<int> st, st2;
    vector<int> v;

    while (cin >> t) {
        if (t == -1)break;

        switch (t)
        {
        case 1:
            int x;
            cin >> x;
            if (st.size() == sz) {
                cout << "Overflow" << endl;
                break;
            }
            st.push(x);
            v.push_back(x);
            for (auto&& i : v) {
                cout << i << ' ';
            }
            cout << endl;
            break;

        case 2:
            if (st.size() == 0) {
                cout << "Underflow" << endl;
                break;
            }
            st.pop();
            v.pop_back();
            for (auto&& i : v) {
                cout << i << ' ';
            }
            cout << endl;
            break;

        case 3:
            if (st.empty())
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;
        case 4:
            if (st.size() == sz)
                cout << "True" << endl;
            else
                cout << "False" << endl;
            break;

        case 5:
            cout << st.size() << endl;
            break;

        case 6:
            cout << st.top() << endl;
            break;
        }
    }

    return 0;
}