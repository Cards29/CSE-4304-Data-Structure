#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

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
    }
    void dfs_inorder() {
        if(tree_root==nullptr) return;
        cout<<"Inorder: // data(parent)"<<endl;
        stack<node*> st;
        node* current_node=tree_root;
        while(current_node!=nullptr || !st.empty()){
            // first we go to the leftmost node of the left subtree
            while(current_node!=nullptr){
                st.push(current_node);
                current_node=current_node->left;
            }
            current_node=st.top();
            st.pop();
            // print the data
            string _parent;
            if(current_node->parent==nullptr) _parent="null";
            else _parent=to_string(current_node->parent->data);
            cout<<current_node->data<<"("<<_parent<<")"<<' ';
            // now we go to the right subtree
            current_node=current_node->right;
        }
        cout<<endl;
    }
    void dfs_preorder() {
        if(tree_root==nullptr) return;
        cout<<"Preorder: // data(parent)"<<endl;
        stack<node*> st;
        st.push(tree_root);
        while(!st.empty()){
            node* current_node=st.top();
            // we print the data
            string _parent;
            if(current_node->parent==nullptr) _parent="null";
            else _parent=to_string(current_node->parent->data);
            cout<<current_node->data<<"("<<_parent<<")"<<' ';
            st.pop();
            // the top of the stack will always be the left subtree,
            // so we print the left node first, then the right node
            if(current_node->right!=nullptr) st.push(current_node->right);
            if(current_node->left!=nullptr) st.push(current_node->left);
        }
        cout<<endl;
    }
    void dfs_postorder() {
        if(tree_root==nullptr) return;
        cout<<"Inorder: // data(parent)"<<endl;
        stack<node*> st;
        node* current_node=tree_root;
        while(current_node!=nullptr || !st.empty()){
            // first we go to the leftmost node of the left subtree
            while(current_node!=nullptr){
                st.push(current_node);
                current_node=current_node->left;
            }
            current_node=st.top();
            st.pop();
            // print the data
            string _parent;
            if(current_node->parent==nullptr) _parent="null";
            else _parent=to_string(current_node->parent->data);
            cout<<current_node->data<<"("<<_parent<<")"<<' ';
            // now we go to the right subtree
            current_node=current_node->right;
        }
        cout<<endl;
    }
    void bfs() {
        int x=1;
        if (tree_root != nullptr) {
            queue<node*> q;
            q.push(tree_root);
            while (!q.empty()) {
                int l_size=q.size();
                cout << "Level " << x << ": ";
                while(l_size--){
                    node* current = q.front();
                    q.pop();
                    cout << current->data << '(';
                    if (current->parent == nullptr) cout << "null";
                    else cout << current->parent->data;
                    cout << ") ";
                    if (current->left != nullptr) q.push(current->left);
                    if (current->right != nullptr) q.push(current->right);
                }
                x++;
                cout<<endl;
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
            bst.dfs_inorder();
            cout<<endl;
        break;
        case 2:
            cout << "Preorder:" << endl;
            bst.dfs_preorder();
            cout<<endl;
            break;
        case 3:
            cout << "Postorder:" << endl;
            bst.dfs_postorder();
            cout<<endl;
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