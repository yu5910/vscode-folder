// o求一个动态数据集的中间值
// 思路：随着动态数据集的尾端不断插入元素，如果元素值小于最大堆的顶点，那就插入最大堆，or vice versa，最大堆和最小堆也跟着变化，因为如果已知最大堆和最小堆的话，求中简直很简单了。比如：如果最终最大堆的元素个数和最小堆相同，那就取各自堆顶相加求平均值，如果最后大堆比小堆多1（这也是维持大小堆动态平衡的条件），就取大堆堆顶。
// 所以关键就是在向动态数据集末尾加元素时，立刻更新两个堆

// 创建一个动态数据集（实质是三个，还有大堆小堆

#include <stdio.h>
#define MAX_HEAP_SIZE 100
//定义动态数据集
typedef struct
{
    int data[MAX_HEAP_SIZE]; // 表示数组有100个容量,但大小堆只是这100个元素中被初始化的部分
    int size;  // 数组此时的长度
} dynamic_dataset;

//初始化动态数据结构体集合
init_dynamic_dataset(dynamic_dataset*set){
    set->size=0;
}

//交换
int swap(int*a,int*b){
    int*temp=a;
    *a=*b;
    *b=*temp;
}

//当向一个最大堆所对应的数据集的末尾添加一个值后，就需要自下而上堆化，毕竟新来的种在最下面，而不是经过交换一跃到堆的top
//从下往上维护
//递归维护最大堆
void maintain_maxheap(dynamic_dataset*maxheap,int current_index){//当前节点就是你所指定的作为堆的最后一个节点，当然，实际不一定是最后一个
    int parentindex=(current_index-1)/2;

    if(current_index>0&&maxheap->data[current_index]>maxheap->data[parentindex]){
        //交换当前和当前它爹
        swap(&(maxheap->data[current_index]),&(maxheap->data[parentindex]));
    }

    maintain_maxheap(maxheap,parentindex)
}
//递归维护最小堆
void maintain_minheap(dynamic_dataset*minheap,int currentindex){
    int parentindex = (current_index - 1) / 2;

    if (current_index > 0 && minheap->data[current_index] < minheap->data[parentindex])
    {
        // 交换当前和当前它爹
        swap(&(minheap->data[current_index]), &(minheap->data[parentindex]));
    }

    maintain_minheap(minheap, parentindex)
}

// 从上往下维护
//  递归维护最大堆结构，从上往下
void maintainMaxHeapDown(struct DynamicDataSet *maxHeap, int currentIndex)
{
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;
    int largestIndex = currentIndex;

    // 找到当前节点和其子节点中的最大值
    if (leftChildIndex < maxHeap->size && maxHeap->data[leftChildIndex] > maxHeap->data[largestIndex])
    {
        largestIndex = leftChildIndex;
    }
    if (rightChildIndex < maxHeap->size && maxHeap->data[rightChildIndex] > maxHeap->data[largestIndex])
    {
        largestIndex = rightChildIndex;
    }

    // 如果当前节点不是最大值，那么就需要进行调整
    if (largestIndex != currentIndex)
    {
        // 交换当前节点和最大值节点
        int temp = maxHeap->data[currentIndex];
        maxHeap->data[currentIndex] = maxHeap->data[largestIndex];
        maxHeap->data[largestIndex] = temp;

        // 递归地维护交换后的子树
        maintainMaxHeapDown(maxHeap, largestIndex);
    }
}

//向原始数据集开插新数据，但同时要保护好两个堆
void insert_data(dynamic_dataset*set,int value,dynamic_dataset*maxheap,dynamic_dataset*minheap){
    set->data[set->size]=value;
    set->size++

    //看看把这个新数插到哪个堆里
    if(value<maxheap->data[0]||maxheap->size==0){
       //那就插到本堆所对应数据集的末尾，但是如果一开始为空的话，就直接插进本堆
       maxheap->data[max->size]=value;
       maxheap->size++;
       //插到末尾后，别忘从下而上维护
       maintain_maxheap(maxheap,maxheap->size-1);
    }else{
        min->data[minheap->size]=value;//正因为一开始就为数据集数组定制了100个大小，后面才能随便操控
        minheap->size++;
        //维护
        maintain_minheap(minheap,minheap-size-1);
    }

    //假如插后小堆比大堆多或大堆比小堆多1个以上，那就要动态维护
    if(maxheap->size>minheap->size+1){
        int top=maxheap->data[0];
        maxheap->data[0]=maxheap->data[maxheap>size-1];//将低端的值给顶端
        maxheap->size--;

        //开始维护
        maintainMaxHeapDown(maxheap,0)
    }else if(minheap-L>size>maxheap->size){
        int top=minheap->data[0];
        minheap->data[0]=minheap->data[minheap->size-1];
        minheap->size--;
        //把top元素给maxheap，而且这次时确定要给maxheap了
      
    }
}


//计算中位数
double find_median(dynamic_dataset*maxheap,dynamic_dataset*minheap){
    if(maxheap->size==minheap->size){
        return (double)(maxheap->data[0]+minheap->data[0])/2//为什么非是2.0
    }else{
        return (double)maxheap->data[0];
    }
}

int main(){
    dynamic_dataset*dataset;
    init_dynamic_dataset(dataset);

    //分别初始化大小堆也为空
    dynamic_dataset* maxheap,minheap;
    init_dynamic_dataset(maxheap);
    init_dynamic_dataset(minheap);

    //开叉
    insert_data(dataset,5,maxheap,minheap);
    insert_data(dataset, 2, maxheap, minheap);
    insert_data(dataset, 10, maxheap, minheap);
    insert_data(dataset, 7, maxheap, minheap);

    //计算中位数
    double median=find_median(maxheap,minheap);

    printf("中位数：%f\n",median);

    return 0;
}

//中位数怎么打印，中位数如何计算2.0？