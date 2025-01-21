#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct node {
    bool endmark;
    int count;
    node* next[52];
    node() : endmark(false), count(0) {
        for (int i = 0;i < 52;i++) next[i] = nullptr;
    }
};

class Trie {
private:
    node* root;
public:
    Trie() : root(new node) {}
    void insert(string s) {
        if(search(s)) return;
        int n = s.size();
        node* current = root;
        for (int i = 0;i < n;i++) {
            int index = tolower(s[i]) - 'a';
            if (current->next[index] == nullptr) current->next[index] = new node;
            current = current->next[index];
            current->count++;
        }
        current->endmark = true;
    }
    bool search(string s) const {
        int n = s.size();
        node* current = root;
        for (int i = 0;i < n;i++) {
            int index = tolower(s[i]) - 'a';
            if (current->next[index] == nullptr) return false;
            current = current->next[index];
        }
        return current->endmark;
    }
    void display(node* current, string s = "") const {
        if (current->endmark) {
            cout << s << " ";
        }
        for (int i = 0; i < 52; i++) {
            if (current->next[i] != nullptr) {
                s += (i + 'a');
                display(current->next[i], s);
                s.pop_back();
            }
        }
    }
    int getCount(string s) const {
        int n = s.size();
        node* current = root;
        for (int i = 0;i < n;i++) {
            int index = tolower(s[i]) - 'a';
            if (current->next[index] == nullptr) return 0;
            current = current->next[index];
        }
        return current->count;
    }
    node* getroot() const {
        return root;
    }
};

int main() {
    Trie t1;
    int n, q;
    cin >> n >> q;
    while (n--) {
        string word;
        cin >> word;
        t1.insert(word);
    }
    while (q--) {
        string word;
        cin >> word;
        cout << t1.getCount(word) << endl;
    }

    return 0;
}