#include<stdio.h>
#define v 6
int main() {
    int graph[v][v]={
        {0,3,2,5,0,0},{3,0,0,1,4,0},{2,0,0,2,0,1},{5,1,2,0,3,0},{0,4,0,3,0,2},{0,0,1,0,2,0}
    };
    int dijcomp[v];  
    int visited[v]={0};
    int row;
    int i,j,count;
    char vertices[v]={'A','B','C','D','E','F'};
    char source;
    printf("Adjacency Matrix : \n");
    for(i=0;i<v;i++){
        printf(" %c",vertices[i]);
    }
    printf("\n");
    for(i=0;i<v;i++) {
        printf("%c ",vertices[i]);
        for (j=0;j<v;j++) {
            printf("%3d",graph[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the source vertex: ");
    scanf(" %c",&source);
    for(i=0;i<v;i++) {
        if(vertices[i]==source) {  
            row=i;
            break;
        }
    }
    for(i=0;i<v;i++) {
        dijcomp[i]=graph[row][i];
    }
    
    dijcomp[row]=0;
    visited[row]=1; 

    for(count=0;count<v-1; count++) {
        int min=999999,col=-1;
        for(i=0;i<v;i++) {
            if (!visited[i] && dijcomp[i] < min) {
                min = dijcomp[i];
                col = i;
            }
        }

        visited[col] = 1;

        for (j = 0; j < v; j++) {
            if (!visited[j] && graph[col][j] != 0) {
                if (dijcomp[col] + graph[col][j] < dijcomp[j]) {
                    dijcomp[j] = dijcomp[col] + graph[col][j];
                }
            }
        }


        // printf("\nDijcomp matrix after iteration %d:\n", count + 1);
        for (i = 0; i < v; i++) {
            printf("%d ", dijcomp[i]);
        }
        printf("\n");
    }
    // printf("\nFinal Dijcomp matrix (Shortest distances from Source %c):\n", source);
    for (i = 0; i < v; i++) {
        printf("%d ", dijcomp[i]);
    }
    printf("\n");
    return 0;
}