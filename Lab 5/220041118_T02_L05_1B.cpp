#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class node {
public:
    int data;
    int depth;
    int height;
    node* right;
    node* left;
    node* parent;
    node(int value) :data(value), right(nullptr), left(nullptr), parent(nullptr), depth(0), height(0) {}
};

class BST {
private:
    node* tree_root;
public:
    BST() :tree_root(nullptr) {}
    node* get_root() {
        return tree_root;
    }
    void insert(int value) {
        node* new_node = new node(value);
        node* temp = tree_root;
        node* target;
        if (tree_root == nullptr) {
            tree_root = new_node;
            return;
        }
        while (temp != nullptr) {
            target = temp;
            if (temp->left == nullptr && temp->right == nullptr) temp->height++;
            if (temp != nullptr && new_node->data < temp->data) { temp = temp->left; }
            else if (temp != nullptr) { temp = temp->right; }
            if (temp != nullptr) temp->depth++;

        }
        new_node->parent = target;
        if (new_node->data < target->data)  target->left = new_node;
        else target->right = new_node;
    }
    void search(int key) {
        node* temp = tree_root;
        while (temp != nullptr && temp->data != key) {
            if (key < temp->data) temp = temp->left;
            else temp = temp->right;
        }
        if (temp == nullptr) {
            cerr << "Not Present" << endl;
            return;
        }
        cout << "Present" << endl << "Parent(";
        if (temp->parent != nullptr) cout << temp->parent->data;
        else cout << "null";
        cout << "), Left(";
        if (temp->left != nullptr) cout << temp->left->data;
        else cout << "null";
        cout << "), Right(";
        if (temp->right != nullptr) cout << temp->right->data;
        else cout << "null";
        cout << ")" << endl;
    }
    int calculate_height(int key) {
        node* temp = tree_root;
        while (temp != nullptr && temp->data != key) {
            if (key < temp->data) temp = temp->left;
            else temp = temp->right;
        }
        if (temp == nullptr) {
            cerr << "Not Present" << endl;
            return 0;
        }
        return temp->height;
    }
    void before_after(int key) {
        node* temp = tree_root;
        if (temp == nullptr) return;
        if (temp->data == key) {

        }
        dfs_inorder(temp->left);
        dfs_inorder(temp->right);
    }
    void dfs_inorder(node* temp) {
        if (temp == nullptr) return;
        dfs_inorder(temp->left);
        cout << temp->data << '(';
        if (temp->parent == nullptr) cout << "null";
        else cout << temp->parent->data;
        cout << ") ";
        dfs_inorder(temp->right);
    }
    void dfs_preorder(node* temp) {
        if (temp == nullptr) return;
        cout << temp->data << '(';
        if (temp->parent == nullptr) cout << "null";
        else cout << temp->parent->data;
        cout << ") ";
        dfs_preorder(temp->left);
        dfs_preorder(temp->right);
    }
    void dfs_postorder(node* temp) {
        if (temp == nullptr) return;
        dfs_postorder(temp->left);
        dfs_postorder(temp->right);
        cout << temp->data << '(';
        if(temp->parent==nullptr) cout<<"null";
        else cout<<temp->parent->data;
        cout<<") ";
    }
    void bfs() {
        if (tree_root != nullptr) {
            queue<node*> q;
            q.push(tree_root);
            while (!q.empty()) {
                int x=1;
                node* current = q.front();
                q.pop();
                cout << current->data << '(';
                if (current->parent == nullptr) cout << "null";
                else cout << current->parent->data;
                cout << ") "<<endl;
                x++;
                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);
            }
        }
    }
    ~BST() {
        if (tree_root != nullptr) {
            queue<node*> q;
            q.push(tree_root);
            while (!q.empty()) {
                node* current = q.front();
                q.pop();
                if (current->left != nullptr) q.push(current->left);
                if (current->right != nullptr) q.push(current->right);
                delete current;
            }
        }
    }
};

int main() {
    BST bst;
    int n, t;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        bst.insert(x);
    }
    // cout << endl;
    // bst.bfs(); cout << endl;
    // bst.dfs_inorder(bst.get_root());
    cout << endl;
    while (cin >> t && t != -1) {
        switch (t) {
        case 1:
            cout << "Inorder:" << endl;
            bst.dfs_inorder(bst.get_root());
        break;
        case 2:
            cout << "Preorder:" << endl;
            bst.dfs_preorder(bst.get_root());
            break;
        case 3:
            cout << "Postorder:" << endl;
            bst.dfs_postorder(bst.get_root());
            break;
        case 4:
            bst.bfs();
            break;
        default:
            break;
        }
    }
    return 0;
}