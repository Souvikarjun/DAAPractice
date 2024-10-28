#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *create(int data)
{
    struct node *New = (struct node*)malloc(sizeof(struct node));
    New->data = data;
    New->right = NULL;
    New->left = NULL;
    return New;
}

struct node *insert(struct node *Root, int data)
{       
        if (Root==NULL)
        {
            struct node *New = create(data);
            Root = New;
            // printf("%d", Root->data);
        }
        else if (Root->data > data){
            Root->left = insert(Root->left, data);
            // printf("%d ", 2);
        }
        else if (Root->data < data){
            Root->right = insert(Root->right, data);

        }
        return Root;
}

void inorderTraverse(struct node *Root){
    if (Root != NULL){
        inorderTraverse(Root->left);
        printf("%d ", Root->data);
        inorderTraverse(Root->right);
    }
    else{
        return;
    }
}

// struct node *deletion(struct node *Root, int data)
// {
//     struct node *new = Root;
//     if (new->data == data)
//     {
//         if (new->data != NULL)
//         {
            
//         }
        
//     }
    
// }


int main(){
    root = insert(root, 100);
    root = insert(root, 70);
    root = insert(root, 90);
    root = insert(root, 120);
    root = insert(root, 110);
    root = insert(root, 60);
    inorderTraverse(root);
}
