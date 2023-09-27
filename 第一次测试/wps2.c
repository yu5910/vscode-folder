#include<stdio.h>

int sumofcells(int n,int w){
 
 if(n=1){
    return 1;
 }
 
 int result=sumofcells(n-1,w)*2+w;
 return result;
}

int main(){
    int n,w;
    scanf("%d %d",&n,&w);//有没有办法合并
    while(n>24||n<3||w<=0||w>10){
        printf("Error!\n")
         scanf("%d %d", &n, &w);
    }
    int result=sumofcells(n,w);
    printf("%d",result);

    return 0;
}