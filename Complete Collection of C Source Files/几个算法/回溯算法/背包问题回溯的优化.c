//宏观上揭示了递归，迭代，回溯，动态规划的一个小区吧，当然不是很全面，但也能让自己有新的体会

//记忆递归树中重复出现的值，此时就和动态规划很接近了

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int maxW = INT_MIN;             // 结果放到maxW中
int weight[] = {2, 2, 4, 6, 3}; // 物品重量
int n = 5;                      // 物品个数
int w = 9;                      // 背包承受的最大重量
bool mem[5][10];                // 备忘录，默认值false

void f(int i, int cw)//他的递归效果就是从i，cw起寻找最大值，所以f（i，cw）=f（,通俗就是f(0,0)=max{f(1,0),f(1,2)}
{ // 调用f(0, 0)
    //先写递归深处也就是最右端的情况，确定终止条件与递归的实现效果
    if (cw = w || i == n)//必须党羽，如果大于，你靠超重算什么本事，如果小于，那一开始就满足了，那就直接return，大家都不思进取
    { // cw==w表示装满了，i==n表示物品都考察完了
        if (cw > maxW)
            maxW = cw;
        return;
    }
    if (mem[i][cw])
        return;        // 重复状态，反正仅仅求最大值，对前面的路线无要求
    mem[i][cw] = true; // 记录(i, cw)这个状态
    f(i + 1, cw);      // 选择不装第i个物品
    if (cw + weight[i] <= w)
    {
        f(i + 1, cw + weight[i]); // 选择装第i个物品
    }
}
//上面一个f(i,j)函数体里已经包括了f(i+1,j)和f(iO+1,j+2),而且终止条件相当于是自动取大机制，，卧槽，这甚至不叫递归，这叫包括F！
//感觉这个通过一个函数里两个函数竞争的形式，才是真正意义上的递归，而一个函数包一个函数的才需要回溯寻找另一个函数的max

int main()
{
    f(0, 0); // 调用f(0, 0)
    printf("最大承重：%d\n", maxW);
    return 0;
}
