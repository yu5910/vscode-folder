#include<stdlib.h>
#include<stdio.h>

struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};
struct AdjList
{
    struct AdjListNode *head;
};
struct Graph
{
    int V;
    struct AdjList *array;
    char *labels;
};
struct AdjListNode *createNode(int dest)
{
    struct AdjListNode *newNode = malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}
struct Graph *createGraph(int V, char *labels)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = malloc(V * sizeof(struct AdjList));
    graph->labels = malloc(V * sizeof(char));
    for (int i = 0; i < V; ++i)
    {
        graph->array[i].head = NULL;
        graph->labels[i] = labels[i];
    }
    return graph;
}
void addEdge(struct Graph *graph, int src, int dest)
{
    struct AdjListNode *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    // 如果是无向图，需要添加下面的代码
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->V; ++v)
    {
        struct AdjListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %c\n head ", graph->labels[v]);
        while (pCrawl)
        {
            printf("-> %c", graph->labels[pCrawl->dest]);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 5;
    char labels[] = {'A', 'B', 'C', 'D', 'E'};
    struct Graph *graph = createGraph(V, labels);
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
