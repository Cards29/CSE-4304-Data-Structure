#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct node {
    bool endmark;
    node* next[52];
    node(): endmark(false) {
        for(int i=0;i<52;i++) next[i] = nullptr;
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
            // if (s[i] < 'a') s[i] = s[i] + 32;
            int index = tolower(s[i]) - 'a';
            if(current->next[index] == nullptr) current->next[index] = new node;
            current = current->next[index];
        }
        current->endmark = true;
    }

    int search(string s) {
        int n = s.size();
        int prefixCount = 0;
        node* current = root;
        for(int i=0;i<n;i++){
            // if (s[i] < 'a') s[i] = s[i] + 32;
            int index = tolower(s[i]) - 'a';
            if(current->next[index] == nullptr) return 0;
            current = current->next[index];
        }
        for(int i=0; i<26; i++) 
            if(current->next[i] != nullptr) prefixCount++;
        return prefixCount + current->endmark;
    }

    void display(node* current, string s = "") const {
        // if(current == nullptr) return;
        if(current->endmark){
            // s += '\0';
            cout << s << " ";
        }
        for(int i=0; i<52; i++) {
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
    int n, q;
    cin >> n >> q;
    while(n--){
        string word;
        cin >> word;
        t1.insert(word);
    }
    while(q--){
        string word;
        cin >> word;
        cout << t1.search(word) << endl;
    }

    return 0;
}