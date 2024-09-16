#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string s, a;
    stack<char> st;
    int n, flag = 0;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        getline(cin, s);
        for (auto&& i : s)
        {
            if (i == '(' || i == '{' || i == '[')
                st.push(i);
            else
            {
                if (st.empty() && (i == ')' || i == '}' || i == ']')){
                    flag=1;
                    break;
                }
                if(!st.empty() && i==')'){
                    if (st.top() == '(')
                        st.pop();
                    else {
                        flag=1;
                        break;
                    }
                }
                else if (!st.empty() && i == '}') {
                    if (st.top() == '{')
                        st.pop();
                    else {
                        flag = 1;
                        break;
                    }
                }
                else if (!st.empty() && i == ']') {
                    if (st.top() == '[')
                        st.pop();
                    else {
                        flag = 1;
                        break;
                    }
                }
            }
        }

        if (flag || !st.empty())
            cout << "No" << endl;
        else if (st.empty())
            cout << "Yes" << endl;
        flag = 0;
        while(!st.empty())
            st.pop();
    }

    

    return 0;
}
