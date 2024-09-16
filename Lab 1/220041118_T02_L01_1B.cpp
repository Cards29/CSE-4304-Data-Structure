#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int error_line=0;
    string s, a;
    stack<string> st;
    int n, t, flag = 0, slash=0, b=0;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        getline(cin, s);
        if(!b)error_line++;
        for (auto &&i : s)
        {
            if (i == '<')
                flag = 1;
            else if (i == '>')
            {
                a += i;
                // cout << a << endl;

                if (st.empty())
                {
                    st.push(a);
                    slash=0;
                }
                else if (a != st.top())
                {
                    if(slash)
                    {
                        b=1;
                        break;
                    }
                    st.push(a);
                    slash=0;
                }
                else if (!st.empty() && a == st.top()){
                    st.pop();
                    slash=0;
                }
                a.clear();
                flag = 0;
            }
            if (flag && i!='/')
                a += i;
            else if(flag && i=='/')
            {
                slash=1;
            }
        }

        // if (!st.empty() && a != st.top())
        //     st.push(a);
        // else if (!st.empty() && a == st.top())
        //     st.pop();
    }
    cin >> t;

    // while (!st.empty())
    // {
    //     cout << st.top() << endl;
    //     st.pop();
    // }

    if (st.empty())
        cout << "No error" << endl;
    else
        cout << "Error at line "<<error_line << endl;

    return 0;
}
