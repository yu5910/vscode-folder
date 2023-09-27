#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
    int data;
    treenode*left;
    treenode*right;
}treenode;

//递归计算树的高度
//递归逻辑:height(树)=height(左子树)+1;//只有一个节点的话就是0+1
//临界:假设整个树只有一个节点,那它左子树的高度就是0;所以递归终止时传入的节点是否为空
int height(treenode*node){
    if(node==NULL)
    return 0;

    int leftheight=height(node->left);
    int rightheight=height(node->right);

    return(leftheight>rightheight)?(leftheight+1):(rightheight+1);
}

/*如何打印指定层(从上面数的第几层,root是第一层)的所有节点
以root为参照,printlevel(root,1)是打印第一层
print level(root,2)是打印以root为参照的第二层.相当于是把root的左右节点当作了第一层

//prinitlevel(root,3)是打印以root为参照的第三层,,相当于是先打印以root左节点为参照
的第二层,再打印以root->right为参照的第二层,而打印以root->left为参照的第二层就相当于
打印以root_>right->right为参照的第一层
所以临界条件:就是打印第一层即level=1时,开始打印

递归逻辑:printlevel(root,n)=printlevel(root->left,n-1)+printlevel(right,n-1)

*/

void printlevel(treenode*root,int level){
    if(level==1){
        printf("%d",root->data);
    }
    if(level>1){
        printlevel(root->left,level-1);
        printlevel(root->right,level-1)
    }
}

void levelordertraversal(treenode*root){
    int height=height(root);
    for(int i=0;i<=h;i++){
        printlevel(root,i);
    }
}