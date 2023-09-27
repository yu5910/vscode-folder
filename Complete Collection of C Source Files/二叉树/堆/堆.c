#include<stdio.h>

//交换数组中两个元素的值
void swap(int*a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

/*   大根堆
堆化,给定一个索引,从它开始向下调整,遇到比它大的,就把那个大的与它交换
*/
void heapify(int arr[],int n,int index){//n是进行操作的指定范围
  int largest=index;
  int left_child=2*index+1;
  int right_child=2*index+2;

  if(left_child<n&&arr[left_child]>arr[largest])
  largest=left_child;
  if(right_child<n&&arr[right_child]>arr[largest])
  largest=right_child;

  if(largest!=index){
    swap(&arr[index],&arr[largest]);
    //改变的只是指针指向元素的值,并没有改变指针指向的元素
    //往下递归堆化
   heapify(arr,n,largest);
  }
}

//建堆(在给定的破堆无序数组基础上)(堆排序的第一阶段)
void bulid_heap(int arr[],int n){
    //从最后一个节点的父节点开始逐渐向前堆化
    for (int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);//因为每次堆化后都只能调整一个
    }
}
//执行堆排序
void heap_sort(int arr[],int n){
    //建一个有序的堆
    bulid_heap(arr,n);
    //逐渐将堆顶的元素通过交换移动到最后一个,并且再次堆堆顶元素堆化
    for(int i=n-1;i>=0;i--){
        swap(&arr[0],&arr[i]);//
        //堆化
        heapify(arr,i,0);//这个额i极为巧妙,成功避开已经排序号的最后一个元素
    }
}

/ 打印数组元素 void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：\n");
    printArray(arr, n);

    heap_sort(arr, n);

    printf("堆排序后的数组：\n");
    printArray(arr, n);

    return 0;
}