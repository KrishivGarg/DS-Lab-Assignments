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

TreeNode* insertNode(TreeNode* root, int key){
    TreeNode* newNode = new TreeNode(key);
    if(root == NULL){
        return newNode;
    }
    if(key < root->val){
        root->left = insertNode(root->left, key); 
    }
    else{
        root->right = insertNode(root->right, key);
    }
    return root;
}

TreeNode* searchRecursive(TreeNode* root, int key){
    if(root == NULL || root->val == key){
        return root;
    }
    if(key < root->val){
        return searchRecursive(root->left, key);
    }
    else{
        return searchRecursive(root->right, key);
    }
}

TreeNode* searchNonRecursive(TreeNode* root, int key){
    while(root != NULL){
        if(key == root->val){
            return root;
        }
        else if(key < root->val){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

TreeNode* findMax(TreeNode* root){
    if(root == NULL){
        return root;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

TreeNode* findMin(TreeNode* root){
    if(root == NULL){
        return root;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* target){
    if(target->right != NULL){
        return findMin(target->right);
    }
    TreeNode* succ = NULL;
    while(root != NULL){
        if(target->val < root->val){
            succ = root;
            root = root->left;
        }
        else if(target->val > root->val){
            root = root->right;
        }
        else{
            break;
        }
    }
    return succ;
}

TreeNode* inorderPredecessor(TreeNode* root, TreeNode* target){
    if(target->left != NULL){
        return findMax(target->left);
    }
    TreeNode* pred = NULL;
    while(root != NULL){
        if(target->val > root->val){
            pred = root;
            root = root->right;
        }
        else if(target->val < root->val){
            root = root->left;
        }
        else{
            break;
        }
    }
    return pred;
}

void inorder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    int n;
    cout << "Enter number of nodes : ";
    cin >> n;
    int arr[n];
    cout << "Enter node values : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++){
        root = insertNode(root, arr[i]);
    }
    cout << "Enter node value to search : ";
    int key;
    cin >> key;
    cout << "Recursive search : " << endl;
    cout << (searchRecursive(root, key) ? "Found" : "Not Found") << endl;
    cout << "Non Recursive search : " << endl;
    cout << (searchNonRecursive(root, key) ? "Found" : "Not Found");
    return 0;
}
