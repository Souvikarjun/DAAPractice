#include<stdio.h>

// void ExchangeGraph(int **graph, int *vertices, int index_source){
//     char temp = *vertices;
//     *vertices = *(vertices+index_source);
//     *(vertices + index_source) = temp;
// }

int main(){
    int num = 6;
    int graph[6][6] = {{0,4,2,0,0,0},{0,0,3,2,0,0},{2,1,0,4,5,0},{0,0,0,0,0,2},{0,0,0,-5,0,0},{0,0,0,0,5,0}};
    int bellman_comp[num+1][num];
    // int visited[6] = {0,0,0,0,0,0};
    char vertices[6] = {'A','B','C','D','E','F'};
    char source;
    int min;
    int index_min;
    printf("source : ");
    scanf("%c",&source);
    int index_Source = 0;

    for (int i = 0; i < num; i++)
    {
        if (source == vertices[i])
        {
            index_Source = i;
            break;
        }  
    }

    char temp_char = vertices[0];
    vertices[0] = vertices[index_Source];
    vertices[index_Source] = temp_char; 

    int temp;
    for (int i = 0; i < num; i++)
    {
        temp = graph[0][i];
        graph[0][i] = graph[index_Source][i];
        graph[index_Source][i] = temp;
    }
    
    for(int i = 0; i<num; i++){
        for (int j = 0; j < num; j++)
        {
            bellman_comp[i][j] = __INT_MAX__;
            // printf("%d ",dj_comp[i][j]);
        }
    }

    int Bell_Temp;
    // for (int i = 0; i < num; i++)
    // {
        for (int k = 0; k < num; k++)
        {
            for (int j = 0; j < num; j++)
            {
                bellman_comp[k+1][j] = bellman_comp[k][j];
                if (j==0)
                {
                    bellman_comp[k][j] = 0;
                    bellman_comp[k+1][j] = 0;
                }

                else if (graph[k][j] != 0)
                {
                    Bell_Temp = bellman_comp[k][k] + graph[k][j];
                    if (bellman_comp[k][j] > Bell_Temp)
                    {
                        bellman_comp[k+1][j] = Bell_Temp;
                    }
                }
            }
        }
    // }

    for (int i = 0; i < num+1; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf(" %d ", bellman_comp[i][j]);
        }
        printf("\n");
    }

return 0;

}
