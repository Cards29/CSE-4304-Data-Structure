#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

string processText(const string& text) {
    string brokenText = "";
    int cursorPos = 0;

    for (char c : text) {
        if (c == '[') {  
            cursorPos = 0;
        }
        else if (c == ']') {  
            cursorPos = brokenText.length();
        }
        else {  
            brokenText.insert(cursorPos, 1, c);
            cursorPos++;
        }
    }

    return brokenText;
}

int main() {
    string s, ans = "";
    while (getline(cin, s)) {
        cout<<processText(s)<<endl;
    }

    return 0;
}