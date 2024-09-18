#include <iostream>
#include <stack>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    char c;
    int x, n;
    deque<int> a;
    vector<string> v;
    string s1 = "Push", s2 = "Pop";
    while (true) {
        c = cin.peek(); // Peek at the next character

        if (c == '\n')
        {
            // Exit loop when Enter is pressed
            break;
        }
        cin >> x;
        // cin.get(); // Consume the character from the stream
        a.push_back(x);
    }

    cin >> n;
    a.pop_back();

    // for (auto &&i : a)
    // {
    //     cout << i << endl;
    // }
    // cout << endl;

    for (int i = 1; i <= n; i++){
        if (i != a.front())
        {
            v.push_back(s1);
            v.push_back(s2);
        }
        else
        {
            v.push_back(s1);
            a.pop_front();
        }

    }

    for (auto&& i : v){
        cout << i << ' ';
    }


    return 0;
}