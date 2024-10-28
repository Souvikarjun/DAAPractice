#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
    int value;
    struct node *include, *exclude;
};

struct node *root = NULL;

struct node *create(int value)
{
    struct node *New = (struct node*)malloc(sizeof(struct node));
    New->value = value;
    New->include = NULL;
    New->exclude = NULL;
    return New;
}

struct node *insert(struct node *Root, int value, int target)
{       
        if (Root==NULL)
        {
            struct node *New = create(value);
            Root = New;
            // printf("%d", Root->value);
        }
        else{
            // printf("%d ", 2);
            if (Root->value < target || Root->value != target)
            {
                if(Root->include == NULL){
                    Root->include = insert(Root->include, value+Root->value, target);
                }
                else{
                    Root->include = insert(Root->include, value,target);
                }
                if(Root->exclude == NULL){
                    Root->exclude = insert(Root->exclude, Root->value,target);
                }
                else{
                    Root->exclude = insert(Root->exclude, value,target);
                }
            }
            // printf("1 ");
            // printf("2 ");
        }
        return Root;
}

void inorderTraverse(struct node *Root){
    if (Root != NULL){
        inorderTraverse(Root->include);
        printf("%d ", Root->value);
        inorderTraverse(Root->exclude);
    }
    else{
        return;
    }
}

struct node *searchTree(struct node *root, int target) {
    if (root == NULL) {
        printf("Node %d Not Found.\n\n", target);
        return NULL;
    } else if (root->value == target) {
        return root;
    } else if (root->value < target) {
        return searchTree
    (root->include, target);
    } else if (root->value > target) {
        return searchTree
    (root->exclude, target);
    }    
}

int main(){
    int v = 4;
    int Set[4] = {10,30,40,50};
    int Target = 80;

    for(int i=0; i<=v; i++){
        if (i==0)
        {   
            // printf("1");
            root = insert(root, 0, Target);
        }
        else{
                // if (root->value != Target || root->value < Target)
                // {
                    root = insert(root, Set[i-1], Target);
                    // printf("2");
                // } 
                
        }
        
    }

    // root = insert(root,20);
    // root = insert(root,40);

    inorderTraverse(root);

return 0;
    
}