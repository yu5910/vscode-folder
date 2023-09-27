//好吧，尽管运行错误了，但我不纠正了
#include<stdio.h>
#include<stdlib.h>

//构造邻接链表的一个节点
typedef Adjlistnode{
    int dest;//储存labels的索引,也就是当前label[]的目标节点之一
    struct adjlistnode*next;
}Adjlistnode;

//构造一个邻接链表,实际很短也就只有一个head指针,但是这个指针可以向后延伸
typedef Adjlist{
    struct adjlistnode*head;
}Adjlist;

//定义一个图
typedef struct Graph{
    int Adjlist*array;//邻接链表数组
    char*labels;//对应的存放顶点的值的数组
    int V;//顶点的个数
}

//创建并初始化一个邻接链表节点
Adjlistnode* createnode(int dest){
    Adjlistnode*newnode=malloc(sizeof(Adjlistnode));
    newnode->dest=dest;
    newnode->next=NULL;
    return newnode;
}

//创建并初始化一个图
Graph* creategraph(int V,char*labels){
    Graph*graph=malloc(sizeof(Graph));
    graph->=V;
    graph->array=malloc(V*sizeof(Adjlist));//像这种array即可指向单个元素又可指向整个数组,所以就要在分配内存时指定
    graph->labels=malloc(V*sizeof(char));//数组也要再次分配内存啊?
    for(int i=0;i<V;++i){
        graph->labels[i]=labels[i];//卧槽,我想起来了,创造的数组的labels数组只是一个局部变量,它也可以时shuzu[],所以要为他分配内存,而已经在main里分配好的只会作为参数
        graph->array[i].head=NULL;
    }
    return graph;
}

//开始为众顶点增加关系
void addEdge(Graph*graph,int src,int dest){
    Adjlistnode*newnode=createnode(dest);
    newnode->next=graph->array[src].head;
    graph->arry[src].head=newnode;
    //现在只形成了单项关注,还要回关
    newnode=createnode(src);
    newnode->graph->array[dest].head;
    graph->array[dest].head=newnode;
}

void printgraph(Graph*graph){
    for(int v=0;f<graph->V;++v){
 //需要一个指向一个链表头节点的指针,因为头节点不可以移动,所以许哟啊一个current指针
   Adjlistnode*currentnode=graph[v].head;
   printf("\n Adjacency list of vertex %c\n head",graph->labels[v]);
   while(currentnode){
    printf("->%c",graph->labels[currentnode->dest]);
    currentnode=currentnode->next;
   }
   printf("\0");
    }

}

int main(){
    int V=5;
    char labels=['a','b','C','d'];
    Graph*graph=creategraph(V,labels);
    addEdge(graph,0,1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    printgraph(graph);
    
    return 0;
}