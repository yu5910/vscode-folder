#include <stdlib.h>
#include <stdio.h>

struct Graph
{
    int V;
    int E;
    int **AdjMatrix;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->AdjMatrix = malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        graph->AdjMatrix[i] = calloc(V, sizeof(int));//这一步把所有的AdjMatrix[i][j]初始化为0
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    graph->AdjMatrix[src][dest] = 1;
    graph->AdjMatrix[dest][src] = 1; // 如果是无向图
}

void printGraph(struct Graph *graph)
{
    printf("Graph:\n");
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            printf("%d ", graph->AdjMatrix[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    int V = 5;
    int E = 7;
    struct Graph *graph = createGraph(V, E);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    return 0;
}
