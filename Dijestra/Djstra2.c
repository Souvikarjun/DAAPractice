#include<stdio.h>
#define v 6
int main() {
    int graph[v][v]={
        {0,3,2,5,0,0},{3,0,0,1,4,0},{2,0,0,2,0,1},{5,1,2,0,3,0},{0,4,0,3,0,2},{0,0,1,0,2,0}
    };
    int dijcomp[v][v];  
    int visited[v];
    int row;
    int col;
    char vertices[v]={'A','B','C','D','E','F'};
    char source;
    printf("Adjacency Matrix : \n");

    for(int i=0;i<v;i++){

        printf(" %c",vertices[i]);
    }

    printf("\n");

    for(int i=0;i<v;i++) {

        printf("%c ",vertices[i]);
        for (int j=0;j<v;j++) {

            printf("%3d",graph[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the source vertex: ");
    scanf(" %c",&source);
    
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < v-1; i++)
    {
        if (source == vertices[i])
        {
            dijcomp[0][i] = 0;
        }
        else{
            
            for (int j = 0; j < v; j++)
            {
                if (dijcomp[i][j] !=0)
                {
                    dijcomp[i][j] = __INT_MAX__;
                }
            }
        }
    }

    for (int i = 0; i < v-1; i++)
    {
        int min = __INT_MAX__;

        for (int m = 0; m < v; m++)
        {        
            if (visited[col] == 0)
            {  
                for (int c = 0; c < v; c++)
                {
                    if (min < dijcomp[i][m])
                    {
                        min = dijcomp[i][m];
                        col = c;
                    }
                }
            }
        }

        for (int j = 0; j < v; j++)
        {
            if (graph[i][j] != 0)
            {
                dijcomp[i+1][j] = min + graph[i][j];
            }
            
        }
        visited[col] = 1;

    }
    


    
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d", dijcomp[i][j]);
        }
        
    }
    


















    return 0;
}

