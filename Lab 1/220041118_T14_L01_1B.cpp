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
    string s;
    while (getline(cin, s)) {
        if (s == "0")
            break;
        stringstream ss(s);
        stack<int> st;
        vector<int> v;
        int n, max_area = 0, width, height;
        size_t sz;

        while (ss >> n)
            v.push_back(n);
        sz = v.size();

        if (sz == 1) {
            cout << v[0] << endl;
            continue;
        }

        st.push(v[0]);


        for (size_t i = 1;i < sz;i++) 
            st.push(v[i]);
        
        width = 1;
        height = st.top();
        while (!st.empty()) {
            height = min(st.top(), height);
            if (height == 0) {
                height = st.top();
                width = 1;
            }
            max_area = max(max_area, height * width);
            // cout << st.top() << ' ' << width << ' ' << height << ' ' << max_area << endl;
            width++;
            st.pop();
        }

        cout << max_area << endl;
        height = INT8_MAX;
        max_area = 0;
    }

    return 0;
}