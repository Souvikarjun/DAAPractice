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

void preorder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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


    printf("preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}