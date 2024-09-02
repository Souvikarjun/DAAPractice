#include<stdio.h>
#include <stdbool.h>

typedef struct Matrix
{
    int Row, Column;
}Matrix;

void InputMatrices(Matrix Matrices[], int number_of_matrices){
    for (int i = 0; i < number_of_matrices; i++)
    {
        printf("Input Row: ");
        scanf("%d", &Matrices[i].Row);
        printf("Input Column: ");
        scanf("%d", &Matrices[i].Column);
    }

}
    
void FindCost(Matrix Matrices[], int number_of_matrices, int **Cost, int **K){

    for (int i = 0; i < number_of_matrices; i++)
    {
        for (int j = i; j < number_of_matrices; j++)
        {
            if (i==j)
            {
                Cost[i][j] = 0;
            }
            else if (i<j)
            {
                int SortingArray[j][2];
                for (int m = i; m < j; m++)
                {
                    SortingArray[m][0] = Cost[i][m] + Cost[m+1][j] + (Matrices[i].Row * Matrices[m].Column * Matrices[j].Column);
                    SortingArray[m][1] = m;
                    if (m=j-1)
                    {
                        int temp=0;
                        for (int n = i; n < j; n++)
                        {
                            if (temp > SortingArray[n][0])
                            {
                                temp = SortingArray[n][0];
                                Cost[i][j] = temp;
                                K[i][j] = SortingArray[n][1];
                            }
                            
                        }
                        
                    }
                    
                }
                
            }

        }
        
    }
}
    
void putBrackets(int **K, int i, int j){   
    if (i==j)
    {
        printf("matrix%d", i);
    }
    else{
        printf("(");
        putBrackets(K, i, K[i][j]);
        putBrackets(K, K[i][j]+1, j);
        printf(")");
    }
}

bool check(Matrix matrices[], int number_of_matrices){

    bool val;
    for (int i = 0; i < number_of_matrices-1; i++)
    {
        if (matrices[i].Column == matrices[i+1].Row)
        {
            val = true;
            continue;
        }
        else{
            val = false;
        }
    }
    return val;     
}


int main(){
    int number_of_matrices;
    printf("How many Matrices to calculate: ");
    scanf("%d", &number_of_matrices);

    Matrix Matrices[number_of_matrices];

    int cost[number_of_matrices][number_of_matrices];
    int k[number_of_matrices][number_of_matrices];
    
    int *cosT;
    cosT = cost;
    int *ptrk;
    ptrk = k;
    int **Cost;
    Cost = &cosT;
    int **K;
    K = &ptrk;

    InputMatrices(Matrices, number_of_matrices);

    if (check(Matrices,number_of_matrices))
    {
        FindCost(Matrices, number_of_matrices, Cost, K);
        putBrackets(K, 0, number_of_matrices-1);
    }
    

return 0;
}
    
    
    