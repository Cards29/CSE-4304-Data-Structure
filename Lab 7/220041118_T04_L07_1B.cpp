#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class node{
public:
    char data;
    node* left;
    node* right;
    node():data('\0'),left(nullptr),right(nullptr) {}
    node(char value):data(value),left(nullptr),right(nullptr) {}
};

class BST{
private:
    node* tree_root;
public:
    BST():tree_root(nullptr){}
    node*& getRoot(){
        return tree_root;
    }
    void dfs_inorder(node* _node){
        if(_node==nullptr){
            cout<<"- ";
            return;
        }
        dfs_inorder(_node->left);
        cout<<_node->data<<' ';
        dfs_inorder(_node->right);
    }
    void dfs_postorder(node* _node){
        if(_node==nullptr){
            cout<<"- ";
            return;
        }
        dfs_postorder(_node->left);
        dfs_postorder(_node->right);
        cout<<_node->data<<' ';
    }
    void build_tree_preorder(node*& _node,const vector<char>& v, int& i){
        if(i>=v.size() || v[i]=='-'){
            i++;
            return;
        }
        _node = new node(v[i]);
        // cout<<"Hello world\n";
        i++;
        build_tree_preorder(_node->left,v,i);
        build_tree_preorder(_node->right,v,i);
    }
    ~BST(){
        queue<node*> q;
        q.push(tree_root);
        while(!q.empty()){
            node* current_node=q.front();
            q.pop();
            if(current_node->left!=nullptr) q.push(current_node->left);
            if(current_node->right!=nullptr) q.push(current_node->right);
            delete current_node;
        }
    }
};

int main(){
    BST bst;
    string s;
    vector<char> v;
    getline(cin,s);
    stringstream ss(s);
    char c;
    while(ss>>c){
        v.push_back(c);
    }
    int i=0;
    bst.build_tree_preorder(bst.getRoot(),v,i);
    cout<<"Inorder:\n";
    bst.dfs_inorder(bst.getRoot());
    cout<<"\nPostorder\n";
    bst.dfs_postorder(bst.getRoot());
    // cout<<s[0]<<s[2]<<s[4]<<s[6]<<s[8];
    return 0;
}