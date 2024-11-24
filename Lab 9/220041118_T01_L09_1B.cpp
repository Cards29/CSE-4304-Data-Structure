#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct node {
    bool endmark;
    node* next[26];
    node(): endmark(false) {
        for(int i=0;i<26;i++) next[i] = nullptr;
    }
};

class Trie{
private:
    node* root;
public:
    Trie(): root(new node) {}
    void insert(string s){
        int n = s.size();
        node* current = root;
        for(int i=0;i<n;i++){
            int index = s[i] - 'a';
            if(current->next[index] == nullptr) current->next[index] = new node;
            current = current->next[index];
        }
        current->endmark = true;
    }

    bool search(string s) {
        int n = s.size();
        node* current = root;
        for(int i=0;i<n;i++){
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

int main(){
    Trie t1;
    string s, s1, word;
    getline(cin, s);
    stringstream ss(s);

    while(ss >> word) {
        t1.insert(word);
    }

    t1.display(t1.getroot());
    cout << endl;
    
    getline(cin, s1);
    stringstream ss1(s1);

    while(ss1 >> word) {
        (t1.search(word)) ? cout << "T " : cout << "F ";
    }

    return 0;
}
