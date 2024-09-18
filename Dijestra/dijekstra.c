#include<stdio.h>

void initializeVertices(int *vertices, int NumOfElement){
    for (int i = 0; i < NumOfElement; i++)
    {
        printf("enter the character: ");
        scanf(" %c", vertices+i);

    }
}

void inputGraph(int *graph, int NumOfElement){
    for (int i = 0; i < NumOfElement; i++)
    {
        for (int j = 0; j < NumOfElement; j++)
        {
            printf("for %d\'th element input edge %d: ", i, j);
            scanf("%d", ((graph + (i*NumOfElement))+j));
        }
        
    }

}

void dijComp(int *djGraph, int *vertices, int *graph, int NumOfElement, char source){    
    int visited[NumOfElement];
    for (int i = 0; i < NumOfElement; i++)
    {
        for (int j = 0; j < NumOfElement; j++)
        {
            if (source == vertices[j])
            {
                *(djGraph+j) = 0;
            }
            else{
                *((djGraph + i*NumOfElement)+j) = __INT_MAX__;
            }
        }
        
    }

    int SequenceJ[NumOfElement];

    for (int i = 0; i < NumOfElement; i++)
    {
        int temp = __INT_MAX__;
        int tempJ=0;
        for (int j = 0; j < NumOfElement; j++)
        {
            if (*((graph+i*NumOfElement)+j) < temp)
            {
                SequenceJ[j] = i;
            }
            for (int k = 0; k < NumOfElement; k++)
            {
                if (SequenceJ[j] == i)
                {
                    *((djGraph+(i+1)*NumOfElement)+k) = *((djGraph+SequenceJ[j]*NumOfElement)+j) + *((graph+i*NumOfElement)+SequenceJ[j]);
                }
                
            }
  
        }
        
    }

}


int main(){
    int NumOfElement;
    printf("Number of elements: ");
    scanf("%d", &NumOfElement);
    int vertices[NumOfElement];
    int graph[NumOfElement][NumOfElement];
    int dijGraph[NumOfElement][NumOfElement];
    char source;
    // int **graph2 = &graph;
    initializeVertices((int *)vertices, NumOfElement);
    inputGraph((int *)graph, NumOfElement);
    printf("source: ");
    scanf(" %c",&source);
    dijComp((int *)dijGraph, (int *)vertices, (int *)graph, NumOfElement, source);

    for (int i = 0; i < NumOfElement; i++)
    {
        printf("%c ",vertices[i]);
        for (int j = 0; j < NumOfElement; j++)
        {
            printf("%d ", dijGraph[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}