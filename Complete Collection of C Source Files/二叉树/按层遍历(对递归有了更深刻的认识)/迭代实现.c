#include <stdio.h>
#include <stdlib.h>

//定义二叉树节点
//定义队列节点
//创造并初始化队节点
//定义队列
//创造并初始化队列
typedef struct treenode{
    int data;
    treenode*left;
    struct treenode*right;
}treenode;

typedef struct queuenode{
  treenode*node;//每个队列节点对应一个树节点,并保存该树节点的指针
  queuenode*next;//指向下一个树节点
}queuenode;

typedef struct createqueuenode(treenode*node){
    queuenode*newnode=(queuenode*)malloc(sizeof(queuenode));
    newnode->node=node;
    newnode->next=NULL;
}

typedef struct Queue{
    queuenode*front;
    queuenode*rear;
}Queue;

Queue*creatqueue(){
    Queue*queue=(Queue*)malloc(sizeof(Queue));
    queue->front=queue->rear=NULL;
    return queue;
}

//入队
void enqueue(Queue*queue,treenode*node){
  queuenode*newnode=createqueuenode(node);

  if(queue->rear==NULL){
    queue->front=queue->rear=newnode;
    return;
  }
  queue->rear->next=newnode;
  queue->rear=newnode;
}
//出队
treenode* dequeue(Queue*queue){
    if(queue->front==NULL)
       return NULL;
    
    queuenode*temp=queue->front;
    treenode*node=temp->node;//及时储存下来,一会就要销毁这个临时节点
    queue->front=queue->front->next;

    if(queue->front==NULL)
        queue->rear=NULL;
    free(temp);
    return node;
}

// 按层遍历二叉树,终于进入正题了
// 思想://把当前树节点弹出了输出后,依次再把它的左右节点加入队列,直到左右节点为NULL
void levelordertraversal(treenode*root){
    Queue*queue=createqueuenode();
    enquue(queue,root);

    while(queue->front!=NULL){
        treenode*currentnode=dequeue(queue);
        printf("%d",currentnode->data);
        
        if(currentnode->left)
        enqueue(queue,current->left);
        if(currentnode->right)
        enqueue(queue,currentnode->right);
    }
    free(queue);
}