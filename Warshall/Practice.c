#include<stdio.h>

int minimum(int a, int b){
    if (a<b)
    {
        return a;
    }
    else{
        return b;
    }  
}


int main(){
    int v = 4;

    // printf("input the number of vertices: ");
    // scanf("%d", &v);

    int initial_Graph[4][4] = {{0,3,__INT_MAX__,7},{8,0,2,__INT_MAX__},{5,__INT_MAX__,0,1,},{2,__INT_MAX__,__INT_MAX__,0}};
    int Walsall_Computation[v+1][v][v];

    // printf("Input the Graph: \n");
    // for (int i = 0; i < v; i++)
    // {
    //     printf("Row %d", i);
    //     for (int j = 0; j < v; j++)
    //     {
    //         scanf("%d", &initial_Graph[i][j]);
    //     }
    // }


    
    for (int i = 0; i <= v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                if (i==0)
                {
                    Walsall_Computation[i][j][k] = initial_Graph[j][k];
                }
                
                else if (j!=k && (j!=i-1 || k!=i-1))
                {
                    if (Walsall_Computation[i-1][j][i-1] != __INT_MAX__ && Walsall_Computation[i-1][i-1][k] != __INT_MAX__)
                    {
                        int temp = Walsall_Computation[i-1][j][i-1] + Walsall_Computation[i-1][i-1][k];
                        Walsall_Computation[i][j][k] = minimum(temp,Walsall_Computation[i-1][j][k]);
                    }
                    else{
                        Walsall_Computation[i][j][k] = Walsall_Computation[i-1][j][k];
                    }
                }
                else
                {
                    Walsall_Computation[i][j][k] = Walsall_Computation[i-1][j][k];
                }
                
                
            }
            
        }
        
    }

    for (int i = 0; i < v+1; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                printf("%d \t", Walsall_Computation[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
        
    }
    
    



}