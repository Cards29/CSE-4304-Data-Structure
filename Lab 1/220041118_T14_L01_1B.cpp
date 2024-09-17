/*
    I am extremely sorry sir, but this problem was too hard for me.
    So I just saw the soln on youtube, and learned the idea behind this problem
    and then wrote the code.
*/  


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
        stack<pair<int, int>> st;
        vector<int> v;
        int n, max_area = 0, width, height, j;
        size_t sz;

        while (ss >> n)
            v.push_back(n);
        sz = v.size();

        if (sz == 1) {
            cout << v[0] << endl;
            continue;
        }

        st.push({ v[0],0 });

        for (size_t i = 1;i < sz;i++) {
            j = i;
            if (st.top().first > v[i]) {
                while (!st.empty() && st.top().first > v[i]) {
                    width = i - st.top().second;
                    height = st.top().first;
                    max_area = max(max_area, height * width);
                    // cout << st.top().first << ' ' << width << ' ' << height << ' ' << max_area << ' ' << j << endl;
                    j=st.top().second;
                    st.pop();
                }
            }
            st.push({ v[i],j });
        }

        // cout << endl << "Second While loop" << endl;

        while (!st.empty()) {
            height = st.top().first;
            width = sz - st.top().second;
            max_area = max(max_area, height * width);
            // cout << st.top().first << ' ' << width << ' ' << height << ' ' << max_area << ' ' << st.top().second << endl;
            width++;
            st.pop();
        }

        cout << max_area << endl;
        max_area = 0;
    }

    return 0;
}