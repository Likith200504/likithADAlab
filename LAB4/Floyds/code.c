#include<stdio.h>
#define MAX 5

void Floyds(int graph[][MAX], int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void main()
{
    int graph[MAX][MAX], n;
    printf("Enter the number of Vertices\n");
    scanf("%d", &n);
    printf("Enter the Cost Adjacency Matrix\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    Floyds(graph, n);
    printf("Shortest Path Matrix\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}
