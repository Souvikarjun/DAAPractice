#include<stdio.h>
#include<string.h>

int max(int a, int b){
    if (a>b)
    {
        return a;
    }
    else{
        return b;
    }
    
}


int main(){
    int size = 4;
    char string1[4] = {'A','B','D','A'};
    char string2[4] = {'A','C','B','A'};
    int graph[size+1][size+1];


    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < size+1; j++)
        {
            if (i==0 || j==0)
            {
                graph[i][j] = 0;
            }
            else if (string1[j-1] == string2[i-1])
            {
                graph[i][j] = max(graph[i-1][j], graph[i][j-1]);
            }
            else{
                graph[i][j] = max(graph[i-1][j], graph[i][j-1]);
            }
            
        }
        
    }
    for (int i = 0; i < size+1; i++)
    {
        for (int j = 0; j < size+1; j++)
        {
            printf("%d \t", graph[i][j]);
        }
        printf("\n");
        
    }
    
    
}