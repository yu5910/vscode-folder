#include<stdio.h>

int main(){

int y=18;
int x=y/2;
int z=y/3;

int n;
scanf("%d",&n);
int price=x*80+50*y+36*z;
while(price>n&&price<2000&&z>=5){
    printf("%d,%d,%d\n",z,x,y);
    y+=6;
    price = x * 80 + 50 * y + 36 * z;
}
return 0;
}