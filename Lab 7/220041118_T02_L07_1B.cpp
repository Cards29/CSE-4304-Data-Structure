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
    bool ifBalance;
    int imbalanceNode;
    string s;
    string s1;
public:
    BST():tree_root(nullptr),ifBalance(true),imbalanceNode(-1),s(""),s1("") {}
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
            dfs_inorder(tree_root);
            return;
        }
        node* temp=tree_root;
        node* target;
        while(temp!=nullptr){
            target=temp;
            if(new_node->data<temp->data) temp=temp->left;
            else if(new_node->data>temp->data) temp=temp->right;
            else{ // no duplicates
                dfs_inorder(tree_root);
                return;
            }
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
        // print the before
        dfs_inorder(tree_root);
        // balance the tree
        check_balance(new_node);
    }
    void left_rotate(node* z){
        node* y=z->right;
        node* y_left=y->left;
        // set tree_root
        if(z==tree_root) tree_root=y;
        // setting lefts rights
        y->left=z;
        z->right=y_left;
        if(z->parent!=nullptr){
            if(z==z->parent->left) z->parent->left=y;
            else z->parent->right=y;
        }
        // setting the parents
        y->parent=z->parent;
        z->parent=y;
        if(y_left!=nullptr)y_left->parent=z;
        update_height(z);
        update_balanceFactor(z);
        update_height(y);
        update_balanceFactor(y);
    }
    void right_rotate(node* z){
        node* y=z->left;
        node* y_right=y->right;
        // set tree_root
        if(z==tree_root) tree_root=y;
        // setting lefts rights
        y->right=z;
        z->left=y_right;
        if(z->parent!=nullptr){
            if(z==z->parent->left) z->parent->left=y;
            else z->parent->right=y;
        }
        // setting the parents
        y->parent=z->parent;
        z->parent=y;
        if(y_right!=nullptr)y_right->parent=z;
        update_height(z);
        update_balanceFactor(z);
        update_height(y);
        update_balanceFactor(y);
    }
    void check_balance(node* _node){
        int count=0;
        while(_node!=nullptr){
            update_height(_node);
            update_balanceFactor(_node);
            // left imbalance
            if(_node->balanceFactor>1){
                count++;
                if(count==1) imbalanceNode=_node->data;
                // LL case
                if(_node->left->balanceFactor>=0) {
                    right_rotate(_node);
                    s="LL case";
                    int n=_node->data;
                    string str = to_string(n);
                    s1="right_rotate(";
                    s1+=str;
                    s1+=")";
                }
                // LR case
                else{
                    s="LR case";
                    int n=_node->left->data;
                    string str = to_string(n);
                    s1="left_rotate(";
                    s1+=str;
                    s1+="), right_rotate(";
                    n=_node->data;
                    str=to_string(n);
                    s1+=str;
                    s1+=")";
                    left_rotate(_node->left);
                    right_rotate(_node);
                }
            }
            // right imbalance
            else if(_node->balanceFactor<-1){
                count++;
                if(count==1) imbalanceNode=_node->data;
                // RR case
                if(_node->right->balanceFactor<=0) {
                    left_rotate(_node);
                    s="RR case";
                    int n=_node->data;
                    string str = to_string(n);
                    s1="left_rotate(";
                    s1+=str;
                    s1+=")";
                }
                // Rl case
                else{
                    s="RL case";
                    int n=_node->right->data;
                    string str = to_string(n);
                    s1="right_rotate(";
                    s1+=str;
                    s1+="), left_rotate(";
                    n=_node->data;
                    str=to_string(n);
                    s1+=str;
                    s1+=")";
                    right_rotate(_node->right);
                    left_rotate(_node);
                }
            }
            _node=_node->parent;
        }
        if(count) ifBalance=false;
        else ifBalance=true;
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
    void print_avl(node* _node){
        if(ifBalance){
            cout<<"Balanced"<<endl
            <<"Root="<<tree_root->data;
        }else {
            cout<<"Imbalance at node: "<<imbalanceNode<<endl
                <<s<<endl<<s1<<endl;
            cout<<"Status: ";
            dfs_inorder(tree_root);
            cout<<endl<<"Root="<<tree_root->data;
        }
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
        cout<<endl;
        bst.print_avl(bst.getRoot());
        cout<<endl;
    }
    cout<<"Status: ";
    bst.dfs_inorder(bst.getRoot());

    return 0;
}