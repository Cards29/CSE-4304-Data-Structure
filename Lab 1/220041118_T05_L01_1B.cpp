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
    cin>>n;
    cin.ignore();
    while(n--){
        stack<char> st;
        string s;
        cin>>s;
        int sz=s.size();
        for (auto &&i : s)
            st.push(i);
        for(int i=0;i<sz;i++){
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
    }

    return 0;
}