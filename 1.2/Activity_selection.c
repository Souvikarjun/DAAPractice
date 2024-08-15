#include<stdio.h>

int main(){
    int size;
    printf("enter the size of array: ");
    scanf("%d", &size);

    int array[size][size];

    printf("input %d amount of numbers: ", size);

// inout
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i==j)
            {
                scanf("%d", &array[i][j]);
            }
            
        }
        
    }

// logic
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i<=j)
            {
                for (int m = 0; m < size; m++)
                {
                    for (int n = 0; n < size; n++)
                    {
                        if(m<=n){
                            array[m-1][n] = array[m-1][n-1] + array[m][n];
                        }
                    }
                    
                }
            }
            
        }
        
    }

    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i>j)
            {
                printf("  ");
            }
            else{
                printf("%d ", array[i][j]);
            }
            
        }
        printf("\n");
        
    }
    
    
    return 0;
}