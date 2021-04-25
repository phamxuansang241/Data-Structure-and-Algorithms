#include<bits/stdc++.h>

using namespace std;

struct BinaryTreeNode{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

BinaryTreeNode* createNewNode(int data){
    BinaryTreeNode* node = new BinaryTreeNode();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void postOrder(struct BinaryTreeNode* root){
     if (root == NULL) // or if (!root)
          return;

     postOrder(root->left);
     postOrder(root->right);
     printf("%d ", root->data);
}

int testPostOrder(){
    /* Sample binary tree is
            9
          /   \
        19      1
         \    /
          3  6
    */
    struct BinaryTreeNode* root = createNewNode(9);
    root->left        = createNewNode(19);
    root->right       = createNewNode(1);
    struct BinaryTreeNode* temp = root->left;
    temp->right  = createNewNode(3);
    temp = root->right;
    temp->left = createNewNode(6);
    postOrder(root);
    return 0;
}

int main() {
    testPostOrder();
}

