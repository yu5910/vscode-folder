#include<stdio.h>

int main(){
    int n;
    printf("Input an integer:\n");
    scanf("%d",&n);
    if(n==0){
        return 0;
    }//加不加分号
    int sum=0;
    int current=n;
    int k,j;
    while(current>0){
        k=current-(current%10)*10;
        if(k%2==0){
            j++;
        }
        current=current%10;
    }
    printf("The number of even digits is %d\n",j);
    
    return 0;
}