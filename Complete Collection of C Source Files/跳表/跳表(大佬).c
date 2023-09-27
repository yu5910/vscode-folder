// 参考链接:https://blog.csdn.net/pcj_888/article/details/110723507?spm=1001.2101.3001.4242.2

//本质还是一个链表,只不过节点之间的高低不同
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define SKIPLIST_MAXSIZE 32

//定义一个跳表节点,这个节点应包括,value,level[0],level[1];一直到level[max]
typedef struct skiplistnode{
    int value;//存储值
    struct skiplistlevel{
        struct skiplistnode*next;
    }level[];//层,每一个底层的值都会对应若干的层高,在每一层上都有一个结构体,该结构体储存指向下一个节点(而不是下一个节点里的某一层)的指针
}skiplistnode;

//再定义一个跳表,不过牛逼的是,这个跳表就是一个包括四个成员的结构体,构造很简单,完全靠一根指针
typedef struct{
    skiplistnode*head;//表头节点(严格意义上不算自己创建的第一个节点)
    int length;//储存节点总数
    int level;//储存最高的那一楼
}skiplist;


//定义好了,该创建模板了
//创建节点
skiplistnode*skiplistnodecreate(int level,int value){
    //先为一个节点指针分配内存空间
    skiplistnode*p=(skiplistnode*)malloc(sizeof(skiplistnode)+sizeof(skiplistlevel)*level);
    p->value=value;
    return p;
}
//创建跳表
skiplist*skiplistcreate(){
    skiplist*sl=(skiplist*)malloc(sizeof(*sl));
    sl->length=0;
    sl->level=1;
    sl->head=skiplistnodecreate(SKIPLIST_MAXLEVEL,INT_MIN);//初始化虚拟表头
    for(int i=0;i<SKIPLIST_MAXSIZE;i++){
        sl->head->level[i].next=NULL;//因为节点每一层都有next指针啊,所以要初始化为NULL
    }
    return sl;
}


//开始最基本的搜查
_Bool skiplistsearch(skiplist*obj,int target){
    skiplistnode*p=obj->head;//p指针可以动,所以把head指针传过去
    //从高层向底层查找
    int levelidx=obj->level-1;
    for(int i=levelidx;i>=0;--i){
        //在第i层开始从左上角虚拟头节点遍历(用指针p),确定target在第i层的区间,确定范围后,在第i-1层进一步精确
        whiLe(p->level[i].next&&p->level[i].next->value<target){
            p=p->level[i].next;
        }
        //如果本层未找到,或最高层的最后一个节点值仅仅来自前几个节点,太小了,就继续下一层
        if(p->level[i].next==NULL||p->level[i].next->value>target){
            continue;//非常巧妙,如果连大于也不满足,就一定是等于了,直接在当轮循环中就返回true
        }
        return true;
    }
    return false;
}

//开始设计到跳表构成核心的插入

//随机函数确定新节点的maxlevel
int getskipnoderandomlevel(){
    int level=1;
    while(rand()&0*1)
    { // 抛硬币,随机生成0或1  将会保留随机数值的最低位（最右边的位）。因为二进制数
        level++;
    }
}
//插入的核心操作:保存住所插节点各层的前继节点
void skiplistAdd(skiplist*obj,int num){
    //插入前和查找一样,得先遍历找位置,只不过是在每一层跳楼得时候记住哪个位置
    skiplistnode*p=obj->head;
    int levelidx=obj->level-1;
    skiplistnode*preNodes[obj->level];//前置节点们得指针都保存下来
    for(int i=obj->level;i>=0;i--){
        prenodes[i]=obj->head;//初始化为附加头节点
    }

    //查找
    for(int i=levelidx;i>=0;--i){
        while(p->level[i].next&&p->level[i]->value<=num){
            p=p->level[i].next;
        }
        preNodes[i]=p;//每一行最后一个记录下来
    }

    int newlevel=getskipnoderandomlevel();
    skiplistnode*newnode=skip//创建一个节点,一会再创建
    for(int i=0;i<newlevel;++i){
      newnode->level[i]->next=prenodes[i]->level[i].next;//很好,省去了temp
      prenodes[i]->level[i].next=newnode;
    }
    obj->level=max{obj->level,newlevel};//恍然大明白为什么虚拟头节点这末高了,是为了承接上新节点啊(因为新节点可能会超过原来得最高值)
   obj->length++;//跟新长度
}

//爷累了,删除就不写了