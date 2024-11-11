#include<stdio.h>

struct Knapsack
{
    int value;
    int weight;
    // float ValueByWeight;
};

struct node
{
    int value;
    int weight;
    int UB;
    struct node *include;
    struct node *exclude;
};
struct node *root = NULL;

struct node *create(int value)
{
    struct node *New = (struct node*)malloc(sizeof(struct node));
    New->value = value;
    New->exclude = NULL;
    New->include = NULL;
    return New;
}

void *searchTree(struct node *root, int *Arr) {
    if (root == NULL && root->value==0) {
        printf("Node %d Not Found.\n\n");
        return NULL;
    } else if (root == NULL && root->value!=0) {
        if (*Arr>*(Arr+1))
        {
            *Arr = root->UB;
        }
        return;
    } else{
        searchTree(root->include, Arr);
        searchTree(root->exclude, Arr);   
    }
    return Arr;
}


struct node *insert(struct node *Root, int value, int *Arr)
{       
        if (Root==NULL)
        {
            struct node *New = create(value);
            Root = New;
            // printf("%d", Root->value);
        }
        else{
            // printf("%d ", 2);
            if (Arr > Arr+1)
            {
                if(Root->include == NULL){
                    Root->include = insert(Root->include, value+Root->value, Arr);
                }
                else{
                    Root->include = insert(Root->include, value, Arr);
                }
                if(Root->exclude == NULL){
                    Root->exclude = insert(Root->exclude, Root->value, Arr);
                }
                else{
                    Root->exclude = insert(Root->exclude, value, Arr);
                }
            }
            // printf("1 ");
            // printf("2 ");
        }
        return Root;
}




int main(){

    int m, Total;
    printf("enter the size of the array: ");
    scanf("%d", &m);
    printf("enter the total size of knapsack: ");
    scanf("%d", &Total);
    int knapValue = 0;
    int knapWeight = 0;

    struct Knapsack Knap[5];

    for (int i = 0; i < m; i++)
    {
        printf("value: ");
        scanf("%d", &Knap[i].value);
        printf("weight: ");
        scanf("%d", &Knap[i].weight);
        // Knap[i].ValueByWeight = Knap[i].value/Knap[i].weight;
    }











    // int w = 0;
    // int elementArray[m];

    // for (int i = 0; i < m; i++)
    // {
    //     elementArray[i] = 0;
    // }
    

    // for (int i = 0; i < m; i++)
    // {
    //     knapWeight += Knap[i].weight;
    //     if (knapWeight < Total)
    //     {
    //         elementArray[i] = 1;
    //         knapValue += Knap[i].value;
    //     }
    //     else{
    //         knapWeight -= Knap[i].weight;
    //     }
    // }
    
    // for (int i = 0; i < m; i++)
    // {
    //     printf("%d   ", elementArray[i]);
    // }
    // printf("\nKnap value = %d   ", knapValue);
    
    
return 0;
}