#include <stdio.h>
#include <stdlib.h>

#define CACHE_SIZE 5

struct Node{
    int data;
    struct Node*next;
};//创建了缓存链的单个节点类型（未命名

struct Cache{
struct Node*front;
struct Node*rear;
int count;
};//创建了缓存链子类型（仅仅是类型，未命名

struct Cache* initCache(){
  struct Cache*cache=(struct Cache*)malloc(sizeof(struct Cache));
  if(cache==NULL){
    printf("Failed to allocate memory for cache\n");
    exit(1);
  }
  cache->front=NULL;
  cache->rear=NULL;
  cache->count=0;
  return cache;
}

void accessCache(struct Cache*cache,int data){
  struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
  if(newNode==NULL){
    printf("Failed to allocate memory for new node\n");
    exit(1);
  }
  newNode->data=data;
  newNode->next=NULL;

  if(cache->count<CACHE_SIZE){
    if(cache->front==NULL){
      cache->front=newNode;
      cache->rear=newNode;
    }else{
      cache->rear->next=newNode;
      cache->rear=newNode;//老话，别忘更新了
    }
  cache->count++;//这个是真容易忘啊！
  }else{
    struct Node*temp=cache->front;
    cache->front=cache->front->next;//真就是一个节点（指针）就是一个结构体
    free(temp);

    cache->rear->next=newNode;
    cache->rear=newNode;//不要忘了更新缓存列表的最后一个节点
//return newNode
  }
}

void printCache(struct Cache*cache){
  struct Node*current=cache->front;
  printf("LRU Cache:");
  while(current!=NULL){
    printf("%d",current->data);
    current=current->next; 
  } printf("\n");
}

void freeCache(struct Cache*cache){
  struct Node*current=cache->front;
  while(current!=NULL){
    struct Node*temp=current;
    current=current->next;
    free(temp);
  }
}//这个释放内存是真没有数组方便，直接赋值为-1就行了

int main(){
  struct Cache*cache=initCache();
  accessCache(cache,1);//非常妙，正好输入的指针参数由初始化得到的指针来扮演
  accessCache(cache,2);
  accessCache(cache,3);
  printCache(cache);

  freeCache(cache);
  return 0;
}
//帮忙写一个链表的应用的算法
