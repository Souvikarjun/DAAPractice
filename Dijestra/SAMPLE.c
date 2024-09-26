#include<stdio.h>
int main(){
    int num = 6;
    int graph[6][6] = {{0,3,2,5,0,0},{3,0,0,1,4,0},{2,0,0,2,0,1},{5,1,2,0,3,0},{0,4,0,3,0,2},{0,0,1,0,2,0}};
    int dj_comp[num][num];
    int visited[6] = {0,0,0,0,0,0};
    char vertices[6] = {'A','B','C','D','E','F'};
    char source;
    int min;
    int index_min;
    scanf("%c ",&source);

    for(int i = 0; i<num; i++){
        for (int j = 0; j < num; j++)
        {
            if (i==0 && source==vertices[j])
            {
                dj_comp[i][j] = 0;
            }
            else{
                dj_comp[i][j] =__INT_MAX__;
            }
            // printf("%d ",dj_comp[i][j]);
        }
        // printf("\n");
        
    }

    for (int i = 0; i < num; i++)
    {
        
        min = __INT_MAX__;
        for (int j = 0; j < num; j++)
        {
            if (visited[j]==0)
            {
                if (min>dj_comp[i][j])
                {
                    min = dj_comp[i][j];
                    index_min=j;
                }
    
            }
        }
        // printf("%d \n",index_min);
        visited[index_min] = 1;

        
        for (int k = 0; k < num; k++)
        {
            if (visited[k]==0)
            {
                if (graph[index_min][k]!=0 && (dj_comp[i][index_min]+graph[index_min][k])<dj_comp[i][k])
                {
                    dj_comp[i+1][k] = (dj_comp[i][index_min]+graph[index_min][k]);
                }
                else{
                    dj_comp[i+1][k] = dj_comp[i][k];
                }
            }
            // else
            // {
            //     dj_comp[i+1][k] = dj_comp[i][k];
            // }
            
        }
        for (int l = 0; l < num; l++)
        {
            printf("%d  ",dj_comp[i][l]);
        }
        printf("\n");
        
    }
    for (int i = 0; i < num; i++)
    {
        for (int m = 0; m < num; m++)
        {
            printf("%d  ",graph[i][m]);
        }
        printf("\n");
    }

    return 0;
}