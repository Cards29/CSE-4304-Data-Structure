#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

struct node {
    bool endmark;
    node* next[26];
    vector<string> suggestions;
    node(): endmark(false), next({nullptr}) {}
};

class Trie{
private:
    node* root;
public:
    Trie(): root(new node) {}

    void insert(const string& s){
        int n = s.size();
        node* current = root;
        for(int i=0;i<n;i++){
            int index = s[i] - 'a';
            if(current->next[index] == nullptr) current->next[index] = new node;
            current = current->next[index];
        }
        current->endmark = true;
        if(current->suggestions.size() < 3) {
            current->suggestions.push_back(s);
        }
    }

    vector<string> getSuggestions(const string& s) {
        node* current = root;
        for (char c : s) {
            int index = c - 'a';
            if (!current->next[index]) return {};
            current = current->next[index];
        }
        return current->suggestions;
    }

    bool search(const string& s) {
        int n = s.size();
        node* current = root;
        for(int i=0; i<n; i++){
            int index = s[i] - 'a';
            if(current->next[index] == nullptr) return false;
            current = current->next[index];
        }
        return current->endmark;
    }

    void display(node* current, string s = "") const {
        // if(current == nullptr) return;
        if(current->endmark){
            // s += '\0';
            cout << s << " ";
        }
        for(int i=0; i<26; i++) {
            if(current->next[i] != nullptr){
                s += (i + 'a');
                display(current->next[i], s);
                s.pop_back();
            }
        }
    }

    node* getroot() const {
        return root;
    }
};

void printSuggestions(const vector<vector<string>>& result) {
    for (auto group : result) {
        if (group.empty()) {
            cout << "Null" << endl;
        } else {
            for (auto suggestion : group) {
                cout << suggestion << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    Trie t1;
    string s, s1, word, prefix;
    vector<string> vstr;
    vector<vector<string>> result;
    getline(cin, s);
    stringstream ss(s);

    while(ss >> word) {
        vstr.push_back(word);
    }

    cin >> s1;

    sort(vstr.begin(), vstr.end());

    for(auto i:vstr) t1.insert(i);

    for(auto c:s1) {
        prefix += c;
        result.push_back(t1.getSuggestions(prefix));
    }

    printSuggestions(result);

    return 0;
}
