//对递归操作中的变量变化有新的理解
#include <stdio.h>
#include <stdlib.h>

//定义树节点,并创造新节点并初始化
typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;

Node*createNode(int data){
    Node*newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory error\n");
        return NULL;
    }
    newNode->data=data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/*
插入节点要实现的效果是:改变原树的结构,
插入节点的返回值是已经被改变的树的root,而插入节点的输入值是未改变树的root
插入节点的递归逻辑:往一个树插入节点=往它的左/右子树插入节点
递归临界:当子树的根节点为NULL时,将newnode赋值给这个null的位置
        所以插入的位置一定是底层的叶子节点
*/

// 爷终于理解了,中间的各种root再怎么变化,可是最终的效果却是一定的,就是实际的root树被改变了,而我们返回的时候肯定不能返回,整棵树,只能返回树的老根节点
Node*inseertNode(Node*root,int data){
    if(root==NULL){
        root=createNode(data);
        return root;
    }

    if(data<root->data)
    root->left=inseertNode(root->left,data);
    else
    root->right=inseertNode(root->right,data);

    return root;
}

//查找节点
//在每次搜查都会返回查到的结果,所以如果一层查不到,就返回第二层的结果
//递归逻辑:第n层返回的查找结果是第n-1层返回的查找结果(因为查找不涉及树的改变,,所以不返回root)
Node*searchNode(Node*root,int data){
    //临界:找到目标或找不到目标(null)就返回
    if(root==NULL||root->data==data){
        return root;
    }

    if(data>root->data)
    return searchNode(root->right,data);
    else
    return searchNode(root->left,data);
}

//中序遍历树
/*
它额效果是打印整棵树,最终按顺序输出整棵树
逻辑上就是先打印左子树,再打印root再打印右子树
*/
void in_order_traversal(Node*root){
    //终止条件
    if(root==NULL)
    return;

    in_order_traversal(root->left);
    printf("%d",root->data);
    in_order_traversal(root->right);
}

int main(){
    Node*root=NULL;

    //插入
    root=inseertNode(root,8);
    inseertNode(root,3);
    inseertNode(root, 1);
    inseertNode(root, 6);
    inseertNode(root, 7);
    inseertNode(root, 10);
    inseertNode(root, 14);
    inseertNode(root, 4);

    Node*temp=searchNode(root,7);
    if(temp!=NULL)
    printf("searched node=%d\n",temp->data);
    else
    printf("Data Not found in tree.\n");

    printf("Inorder traversal: ");
    in_order_traversal(root);
    printf("\n");
    return 0;
}


