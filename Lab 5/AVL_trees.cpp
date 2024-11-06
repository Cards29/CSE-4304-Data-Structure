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
    int balance_factor;
    node():data(0),left(nullptr),right(nullptr),parent(nullptr),height(0),balance_factor(0) {}
    node(int value):data(value),left(nullptr),right(nullptr),parent(nullptr),height(0),balance_factor(0) {}
};

class BST{
private:
    node* tree_root;
public:
    BST():tree_root(nullptr) {}
    int height(node* _node){
        return _node ? _node->height : -1;
    }
    void update_height(node* _node){
        _node->height = 1 + max(height(_node->left),height(_node->right));
    }
    int balanceFactor(node* _node){
        return _node ? height(_node->left) - height(_node->right) : 0;
    }
    void update_balance_factor(node* _node){
        _node->balance_factor=balanceFactor(_node);
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
            update_balance_factor(temp);
            temp=temp->parent;
        }
        // balance this tree
        // balance_tree(new_node);
    }
    void left_rotate(node* z){
        node* y=z->right;
        node* y_left=y->left;
        // if z is the root, then update the tree_root
        if(z==tree_root) tree_root=y;
        // set parent of y
        y->parent=z->parent;
        // set left child of y, no change in right child of y
        y->left=z;
        // set the child of z' parent to be y
        if(z->parent!=nullptr){
            if(z==z->parent->left) z->parent->left=y;
            else z->parent->right=y;
        }
        // set the right child z to be y_left
        z->right=y_left;
        // set the parent of z to be y
        z->parent=y;
        // set the parent of y_left to be z
        if(y_left!=nullptr)y_left->parent=z;
        // to update the heights of the ancestors
        node* temp=z;
        while(temp!=nullptr){
            update_height(temp);
            temp=temp->parent;
        }
    }
    void right_rotate(node* z){
        node* y=z->left;
        node* y_right=y->right;
        // if z is the root, then update the tree_root
        if(z==tree_root) tree_root=y;
        // set parent of y
        y->parent=z->parent;
        // set right child of y, no change in right child of y
        y->right=z;
        // set the child of z' parent to be y
        if(z->parent!=nullptr){
            if(z==z->parent->left) z->parent->left=y;
            else z->parent->right=y;
        }
        // set the left child z to be y_right
        z->left=y_right;
        // set the parent of z to be y
        z->parent=y;
        // set the parent of y_right to be z
        if(y_right!=nullptr) y_right->parent=z;
        // to update the heights of the ancestors
        node* temp=z;
        while(temp!=nullptr){
            update_height(temp);
            temp=temp->parent;
        }
    }
    void balance_tree(node* new_node){
        bool l=0,r=0;
        if(new_node==new_node->parent->left) l=1;
        else r=1;
        // check if there's an unbalanced node
        node* temp=new_node->parent;
        while(temp!=nullptr && abs(temp->balance_factor)<=1) temp=temp->parent;
        if(temp==nullptr) return;
        // case: LL
        if(temp->balance_factor>1 && l) right_rotate(temp);
        // case: RR
        else if(temp->balance_factor<-1 && r) left_rotate(temp);
        // case: LR
        else if(temp->balance_factor>1 && r){
            left_rotate(temp->left);
            right_rotate(temp);
        }
        // case: RL
        else{
            right_rotate(temp->right);
            left_rotate(temp);
        }
        // node* temp = new_node->parent;
        // while (temp != nullptr) {
        //     update_height(temp);
        //     update_balance_factor(temp);
        //     // Check if this node is unbalanced
        //     if (abs(temp->balance_factor) > 1) {
        //         // Determine the type of rotation needed
        //         if (temp->balance_factor > 1) {
        //             if (temp->left->balance_factor >= 0) {
        //                 // LL case
        //                 right_rotate(temp);
        //             } else {
        //                 // LR case
        //                 left_rotate(temp->left);
        //                 right_rotate(temp);
        //             }
        //         } else {
        //             if (temp->right->balance_factor <= 0) {
        //                 // RR case
        //                 left_rotate(temp);
        //             } else {
        //                 // RL case
        //                 right_rotate(temp->right);
        //                 left_rotate(temp);
        //             }
        //         }
        //     }
        //     // Move to the parent and continue checking
        //     temp = temp->parent;
        // }
    }
    node* search(int key){
        node* target=tree_root;
        while(target!=nullptr && target->data!=key){
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
    bst.insert(130);
    bst.insert(100);
    bst.insert(50);
    bst.dfs_inorder();
    bst.bfs();
    // int t;
    // while(cin>>t && t!=-1){
    //     bst.insert(t);
    //     bst.dfs_inorder();
    //     bst.bfs();
    //     cout<<endl;
    // }
    

    return 0;
}