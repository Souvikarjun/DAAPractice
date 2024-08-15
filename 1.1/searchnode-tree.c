#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

Node *createNode(int val) {
    Node *new = (Node*)malloc(sizeof(Node));
    if (new) {
        new->data = val;
        new->left = new->right = NULL;
    }
    return new;
}

Node *insert(Node *root, int val) {
    if (root == NULL) {
        return createNode(val);
    } else if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

Node *searchTree(Node *root, int target) {
    if (root == NULL) {
        printf("Node %d Not Found.\n\n", target);
        return NULL;
    } else if (root->data == target) {
        return root;
    } else if (root->data < target) {
        return searchTree
    (root->right, target);
    } else if (root->data > target) {
        return searchTree
    (root->left, target);
    }    
}

int main() {
    Node *root = NULL;

    root = insert(root, 23);
    root = insert(root, 56);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 67);
    root = insert(root, 21);
    root = insert(root, 18);
    root = insert(root, 34);
    root = insert(root, 10);

    int target = 67;
    if(searchTree
(root, target)) {
        printf("Node %d Found.\n\n", target);
    }

    return 0;
}