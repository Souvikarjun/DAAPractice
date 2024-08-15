#include<stdio.h>

int main(){
    int size;
    printf("enter the size of array: ");
    scanf("%d", &size);

    int array[size][size];

    printf("input %d amount of numbers: ", size);

// inout
    for (int i = size-1; i >= 0; i--)
    {
        for (int j = size-1; j >= 0; j--)
        {
            if (i==j)
            {
                scanf("%d", &array[i][j]);
            }
            
        }
        
    }

// logic
    for (int i = size-1 ; i >= 0; i--)
    {
        for (int j = size-1; j >= 0; j--)
        {
            if (i<=j)
            {
                for (int m = i; m >= 0; m--)
                {
                    for (int n = j; n >= 0; n--)
                    {
                        if(m<=n){
                            array[m][n+1] = array[m+1][n+1] + array[m][n];
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
                array[i][j] = 0;
                printf("%d ", array[i][j]);
            }
            else{
                printf("%d ", array[i][j]);
            }
            
        }
        printf("\n");
        
    }
    
    
    return 0;
}