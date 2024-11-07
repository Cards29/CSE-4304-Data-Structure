#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node* parent;
    int height;
    int balanceFactor;
    node():data(0),left(nullptr),right(nullptr),parent(nullptr),height(0),balanceFactor(0) {}
    node(int value):data(value),left(nullptr),right(nullptr),parent(nullptr),height(0),balanceFactor(0) {}
};

class BST{
private:
    node* tree_root;
public:
    BST():tree_root(nullptr) {}
    node* getRoot(){
        return tree_root;
    }
    int height(node* _node){
        return _node ? _node->height : -1;
    }
    void update_height(node* _node){
        _node->height = 1 + max(height(_node->left),height(_node->right));
    }
    int balance_factor(node* _node){
        return _node ? height(_node->left) - height(_node->right) : 0;
    }
    void update_balanceFactor(node* _node){
        _node->balanceFactor=balance_factor(_node);
    }
    void insert(int key){
        node* new_node=new node(key);
        if(tree_root==nullptr){
            tree_root=new_node;
            return;
        }
        node* temp=tree_root;
        node* target;
        while(temp!=nullptr){
            target=temp;
            if(new_node->data<temp->data) temp=temp->left;
            else if(new_node->data>temp->data) temp=temp->right;
            else return; // no duplicates
        }
        new_node->parent=target;
        if(new_node->data<target->data) target->left=new_node;
        else target->right=new_node;

        // to update the heights of the ancestors
        temp=new_node->parent;
        while(temp!=nullptr){
            update_height(temp);
            temp=temp->parent;
        }
        //  to update the balance factor of the ancestors
        temp=new_node->parent;
        while(temp!=nullptr){
            update_balanceFactor(temp);
            temp=temp->parent;
        }
        // balance this tree
        // balance_tree(new_node);
    }
    node* search(int key){
        node* target=tree_root;
        while(target!=nullptr && target->data!=key){
            if(key<target->data) target=target->left;
            else target=target->right;
        }
        return target;
    }
    void dfs_inorder(node* _node){
        if(_node==nullptr) return;
        dfs_inorder(_node->left);
        cout<<_node->data<<"("<<_node->balanceFactor<<") ";
        dfs_inorder(_node->right);
    }
    void bfs(){
        if(tree_root==nullptr) return;
        cout<<"Level order:"<<endl;
        queue<node*> q;
        int level=1;
        q.push(tree_root);
        while(!q.empty()){
            int level_size=q.size();
            cout<<"Level "<<level<<": ";
            while(level_size--){
                node* current_node=q.front();
                q.pop();
                if(current_node->left!=nullptr) q.push(current_node->left);
                if(current_node->right!=nullptr) q.push(current_node->right);
                cout<<current_node->data<<' ';
            }
            cout<<endl;
            level++;
        }
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
    int t;
    while(cin>>t && t!=-1){
        bst.insert(t);
        bst.dfs_inorder(bst.getRoot());
        cout<<endl;
    }
    return 0;
}