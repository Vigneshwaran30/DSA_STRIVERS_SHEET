#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

node* preorder(node* root){
    if(root==NULL){
        return NULL;
    }
    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
    return root;
}

node* postorder(node* root){
    if(root==NULL){
        return NULL;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
    return root;
}

node* inorder(node* root){
    if(root==NULL){
        return NULL;
    }
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    return root;
}

vector<vector<int>> levelorder(node* root){
    vector<vector<int>>ans;
    queue<node*>q;
    
    if(root==NULL)
    return ans;

    q.push(root);
    while(!q.empty()){
        int size=q.size();
        vector<int>lev;
        for(int i=0;i<size;i++){
            node* front=q.front();
            q.pop();
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
            lev.push_back(front->data);
        }
        ans.push_back(lev);
    }
    return ans;
}

//Iterative
vector<int> preorderit(node* root){
    vector<int>ans;
    stack<node*>s;
    s.push(root);
    while(!s.empty()){
        node* top=s.top();
        s.pop();
        if(top->right!=NULL){
            s.push(top->right);
        }
        if(top->left!=NULL){
            s.push(top->left);
        }
        ans.push_back(top->data);
    }
    return ans;
}

vector<int> inorderit(node* root){
    vector<int>inorder;
    stack<node*>s;
    node* node=root;
    while (true)
    {
        if(node!=NULL){
            s.push(node);
            node=node->left;
        }
        else{
            if(s.empty()==true)
            break;
            node=s.top();
            s.pop();
            inorder.push_back(node->data);
            node=node->right;
        }
    }
    
    return inorder;
}

vector<int> postorderit(node* root){
    stack<node*>st1,st2;
    vector<int>postorder;
    st1.push(root);
    while(!st1.empty()){
        node* top=st1.top();
        st1.pop();
        st2.push(top);
        if(top->left!=NULL){
            st1.push(top->left);
        }
        if(top->right!=NULL){
            st1.push(top->right);
        }
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

int main(){
    node* root=NULL;
    root=buildTree(root);

    
    //---preorder---
    preorder(root);
    cout<<endl;
    vector<int>preorder;
    preorder=preorderit(root);
    for(int i=0;i<preorder.size();i++){
        cout<<preorder[i];
    }
    cout<<endl;


    //---postorder---
    postorder(root);
    cout<<endl;
    vector<int>postorder;
    postorder=postorderit(root);
    for(int i=0;i<postorder.size();i++){
        cout<<postorder[i];
    }
    cout<<endl;
    
    //---inorder---
    inorder(root);
    cout<<endl;
    vector<int>inorderiter;
    inorderiter=inorderit(root);
    for(int i=0;i<inorderiter.size();i++){
        cout<<inorderiter[i];
    }
    cout<<endl;
    

    //---level order---
    vector<vector<int>>ans;
    ans=levelorder(root);
    
    for (const auto row : ans) {
        for (auto value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}