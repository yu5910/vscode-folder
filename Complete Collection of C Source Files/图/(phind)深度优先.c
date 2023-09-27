void DFS(struct Graph *graph, int v, int *visited)
{
    visited[v] = 1;
    printf("%c ", graph->labels[v]);

    struct AdjListNode *pCrawl = graph->array[v].head;
    while (pCrawl)
    {
        int dest = pCrawl->dest;
        if (!visited[dest])
        {
            DFS(graph, dest, visited);
        }
        pCrawl = pCrawl->next;
    }
}

void depthFirstSearch(struct Graph *graph)
{
    int *visited = calloc(graph->V, sizeof(int));

    printf("Depth First Traversal: ");
    for (int v = 0; v < graph->V; ++v)
    {
        if (!visited[v])
        {
            DFS(graph, v, visited);
        }
    }
    printf("\n");

    free(visited);
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

    depthFirstSearch(graph);

    return 0;
}
