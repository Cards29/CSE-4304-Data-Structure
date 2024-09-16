#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int t = 1;
    // char c;
    cin >> t;
    cin.ignore();

    stack<int> st;

    while (t--)
    {
        int temp1, temp2;
        string s;
        getline(cin, s);
        for (auto &&c : s)
        {
            if (c >= '0' && c <= '9')
                st.push(c - '0');
            else
            {
                switch (c)
                {
                case '+':
                    temp1 = st.top();
                    st.pop();
                    temp2 = st.top();
                    st.pop();
                    st.push(temp2 + temp1);
                    break;
                case '-':
                    temp1 = st.top();
                    st.pop();
                    temp2 = st.top();
                    st.pop();
                    st.push(temp2 - temp1);
                    break;
                case '*':
                    temp1 = st.top();
                    st.pop();
                    temp2 = st.top();
                    st.pop();
                    st.push(temp2 * temp1);
                    break;
                case '/':
                    temp1 = st.top();
                    st.pop();
                    temp2 = st.top();
                    st.pop();
                    st.push(temp2 / temp1);
                    break;

                default:
                    break;
                }
            }

            // cin.get(); // Consume the character from the stream
        }
        cout << st.top() << endl;
    }

    return 0;
}