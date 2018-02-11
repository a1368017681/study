#include <iostream>
#include <time.h>

using namespace std;
#define N 10

typedef struct TreeNode{
    int val;
    TreeNode* l;
    TreeNode* r;
}TreeNode;

TreeNode* root = NULL;

void printTree(TreeNode* root) {
    if (!root) return ;
    cout << root->val << " " << endl;
    if (root->l) {
        printTree(root->l);
    }
    if (root->r) {
        printTree(root->r);
    }
    return ;
}

TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        root = (TreeNode*)malloc(sizeof(TreeNode));
        root->l = NULL;
        root->r = NULL;
        root->val = value;
        return root;
    }
    if (root->l) {
        if (root->l->val < value) {
            root->l = insert(root->l, value);
        }
    } else {
        root->r = insert(root->r, value);
    }
    return root;
}

void initTree() {
    for (int i = N; i > N/2; i--) {
        root = insert(root, i);
    }
    for (int i = 1; i <= N/2; i++) {
        root = insert(root, i);
    }
}

int btree() {
    srand(time(NULL));
    initTree();
    printTree(root);
    //printLinkList(head);
}
