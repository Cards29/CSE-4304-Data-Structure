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
    node():data(0),left(nullptr),right(nullptr),parent(nullptr),height(0) {}
    node(int value):data(value),left(nullptr),right(nullptr),parent(nullptr),height(0) {}
};

class BST{
private:
    node* tree_root;
public:
    BST():tree_root(nullptr) {}

    void update_height(node* a_node){
        int _left=-1,_right=-1;
        if(a_node->left!=nullptr) _left=a_node->left->height;
        if(a_node->right!=nullptr) _right=a_node->right->height;
        a_node->height=max(_left,_right)+1;
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
            else temp=temp->right;
        }
        new_node->parent=target;
        if(new_node->data<target->data) target->left=new_node;
        else target->right=new_node;
        // to update the height of the ancestors
        temp=new_node->parent;
        while(temp!=nullptr){
            update_height(temp);
            temp=temp->parent;
        }
    }
    node* search(int key){
        node* target=tree_root;
        while(target->data!=key){
            if(key<target->data) target=target->left;
            else target=target->right;
        }
        return target;
    }
    void transplant(node* u, node* v){
        // make v the child of u.parent
        if(u->parent==nullptr) tree_root=v;
        else if(u->parent->left==u) u->parent->left=v;
        else u->parent->right=v;
        // make v.parent = u.parent
        if(v!=nullptr)v->parent=u->parent;
        delete u;
    }
    void delete_node(int key){
        node* z=search(key);
        if(z==nullptr){
            cout<<"node not present"<<endl;
            return;
        }
        if(z->left==nullptr){
            transplant(z,z->right);
        }else if(z->right==nullptr){
            transplant(z,z->left);
        }else{
            // if z has both left and right child, we find the successor
            node* successor=z->right;
            node* temp=z->right->left;
            while(temp!=nullptr){
                successor=temp;
                temp=temp->left;
            }
            int successor_data=successor->data;
            // delete the successor
            transplant(successor,successor->right);
            // just replace the data of the successor with the data of z
            // no need to delete the z node
            z->data=successor_data;
        }
    }
    // tree traversal
    void dfs_preorder(){
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
    void dfs_inorder(){
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
    void dfs_postorder(){
        if(tree_root==nullptr) return;
        cout<<"Postorder: // data(parent)"<<endl;
        stack<node*> st;
        stack<node*> result;
        st.push(tree_root);
        while(!st.empty()){
            node* current_node=st.top();
            st.pop();
            // result will have the all nodes in postorder
            result.push(current_node);
            if(current_node->left!=nullptr) st.push(current_node->left);
            if(current_node->right!=nullptr) st.push(current_node->right);
        }
        while(!result.empty()){
            string _parent;
            if(result.top()->parent==nullptr) _parent="null";
            else _parent=to_string(result.top()->parent->data);
            cout<<result.top()->data<<"("<<_parent<<")"<<' ';
            result.pop();
        }
        cout<<endl;
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
    cin>>t;
    while(t--){
        int key;
        cin>>key;
        bst.insert(key);
    }
    bst.bfs();
    // bst.dfs_preorder();
    // bst.dfs_inorder();
    // bst.dfs_postorder();

    int k;
    cin>>k;
    while(k--){
        int key;
        cin>>key;
        bst.delete_node(key);
        // bst.dfs_inorder();
        bst.bfs();
    }
    return 0;
}