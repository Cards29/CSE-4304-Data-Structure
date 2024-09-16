#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    string s;
    stack<char> st;
    deque<char>d;
    cin >> s;

    n = s.size();

    for (int i = 0;i < n;i++)
    {
        if (st.empty()) {
            st.push(s[i]);
            continue;
        }
        if (st.top() == s[i]) {
            st.pop();
            continue;
        }
        st.push(s[i]);
    }

    if(st.empty()){
        cout<<"NULL"<<endl;
        return 0;
    }
    
    while(!st.empty()){
        d.push_front(st.top());
        st.pop();
    }

    for (auto &&i : d)
        cout<<i;
        
    cout<<endl;

    return 0;
}
