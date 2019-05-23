#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct TreeNode {
    int key;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode Node;

#if 0
int findMinOfMax(struct TreeNode* root, int k) {
    int ret = 0;

    if(NULL == root) {
        return -1;
    }

    if(root->key > k) {
        int tmp = findMinOfMax(root->left, k);
        ret = (tmp == -1) ? root->key : tmp;
    } else {
        ret = findMinOfMax(root->right, k);
    }

    return ret;

}
#else
int findMinOfMax(struct TreeNode* root, int k) {
    int res = -1;

    if(NULL == root) {
        return -1;
    }

    struct TreeNode* cur = root;
    while(cur) {
        if(cur->key <= k) {
            cur = cur->right;
        } else {
            res = cur->key;
            cur = cur->left;
        }
    }

    return res;

}
#endif
void insertTree(struct TreeNode* root, struct TreeNode* z) {

    if(NULL == root) {
        root = z;
    }

    struct TreeNode* x = root;
    struct TreeNode* y = NULL;

    while(x) {
        y = x;
        if(x->key > z->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    if(y->key > z->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}

void printTree(struct TreeNode* root) {
    if(NULL == root) {
        return;
    }

    printTree(root->left);
    printf("%d ", root->key);
    printTree(root->right);


}


int main()
{
    struct TreeNode root = {20, NULL, NULL};
    struct TreeNode node1 = {16, NULL, NULL};
    struct TreeNode node2 = {28, NULL, NULL};
    struct TreeNode node3 = {15, NULL, NULL};
    struct TreeNode node4 = {18, NULL, NULL};
    struct TreeNode node5 = {24, NULL, NULL};
    struct TreeNode node6 = {30, NULL, NULL};
    struct TreeNode node7 = {22, NULL, NULL};
    struct TreeNode node8 = {26, NULL, NULL};

    //struct TreeNode *root = NULL;
    insertTree(&root, &node1);
    insertTree(&root, &node2);
    insertTree(&root, &node3);
    insertTree(&root, &node4);
    insertTree(&root, &node5);
    insertTree(&root, &node6);
    insertTree(&root, &node7);
    insertTree(&root, &node8);


    printTree(&root);
    printf("\n");

    int res =  findMinOfMax(&root, 20);

    printf("%d \n", res);
    return 0;

}
