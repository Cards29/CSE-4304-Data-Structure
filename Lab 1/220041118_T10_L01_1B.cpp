#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int n, jeitajabe = 1, flag = 0;
    cin >> n;
    vector<int> v(n);
    stack<int> st, st2;
    for (int i = 0;i < n;i++) cin >> v[i];

    for (int i = 0;i < n;i++) {
        cout << jeitajabe << endl;
        while(!st.empty() && st.top() == jeitajabe) {
            st.pop();
            jeitajabe++;
        }
        if (v[i] != jeitajabe) {
            st.push(v[i]);
        }
        else
            jeitajabe++;
    }

    cout << jeitajabe << endl;

    while (!st.empty()) {
        cout << jeitajabe << endl;

        if (st.top() != jeitajabe) {
            flag = 1;
            break;
        }
        st.pop();
        jeitajabe++;
    }

    if (!flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}