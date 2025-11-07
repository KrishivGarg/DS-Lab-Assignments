#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val1){
        val = val1;
        left = NULL;
        right = NULL;
    }
};

void preorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    preorder(root->left);
    cout << root->val << " ";
    preorder(root->right);
}

void postorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout << root->val << " ";
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    cout << "Preorder : " << endl;
    preorder(root) ;
    cout << endl;
    cout << "Inorder : " <<  endl;
    inorder(root);
    cout << endl;
    cout << "Postorder : " << endl;
    postorder(root);
    cout << endl;
    return 0;
}
