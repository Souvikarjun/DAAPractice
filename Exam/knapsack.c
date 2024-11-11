#include<stdio.h>

struct Knapsack
{
    int value;
    int weight;
    // float ValueByWeight;
};


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

    int w = 0;
    int elementArray[m];

    for (int i = 0; i < m; i++)
    {
        elementArray[i] = 0;
    }
    

    for (int i = 0; i < m; i++)
    {
        knapWeight += Knap[i].weight;
        if (knapWeight < Total)
        {
            elementArray[i] = 1;
            knapValue += Knap[i].value;
        }
        else{
            knapWeight -= Knap[i].weight;
        }
    }
    
    for (int i = 0; i < m; i++)
    {
        printf("%d   ", elementArray[i]);
    }
    printf("\nKnap value = %d   ", knapValue);
    
    
return 0;
}
