#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string s, a="";
    stack<char> st;
    int n, flag = 0, flag2=0;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        getline(cin, s);
        a+=s;
    }

    for (auto &&i : a)
    {
        if (i == '(' || i == '{' || i == '[')
            st.push(i);
        else
        {
            if (st.empty() && (i == ')' || i == '}' || i == ']')) {
                flag = 1;
                break;
            }
            if (!st.empty() && i == ')') {
                if (st.top() == '(')
                    st.pop();
                else {
                    flag2 = 1;
                    break;
                }
            }
            else if (!st.empty() && i == '}') {
                if (st.top() == '{')
                    st.pop();
                else {
                    flag2 = 1;
                    break;
                }
            }
            else if (!st.empty() && i == ']') {
                if (st.top() == '[')
                    st.pop();
                else {
                    flag2 = 1;
                    break;
                }
            }
        }
    }
    

    if (st.empty() && !flag)
        cout << "No error" << endl;
    else if (flag2)
        cout << "Improper parenthesis" << endl;
    else if(flag || !st.empty())
        cout << "Missing parentheses" << endl;
    

    return 0;
}
