// 目标一：掌握递归
// 目标二：完善结构体的知识
#include <stdio.h>

// 定义一个用户结构体，包括用户自己的id和推荐该用户的id
typedef struct
{
    int userID;
    int referrerID;
} user;

// 创建储存所有用户信息的数组
user users[5] = {
    {1, -1}, // 用户A
    {2, 1},  // 用户B(他的refferID是1)
    {3, 2},
    {4, 1},
    {5, 4}}; // 数组的结尾也有分号

// 开始查找最终推荐人
int findUltimateReffer(int ID)
{
    user currentUser;
    // 开始查找那个用户是要找的ID
    for (int i = 0; i < sizeof(users) / sizeof(users[0]); i++)
    {
        if (users[i].userID == ID)
        { // 看看是否匹配
            currentUser = users[i];
            break; // 因为匹配的只有一个,所以找到后就可以结束循环了
        }
    }

    if (currentUser.referrerID == -1)
    {
        return currentUser.userID;
    }
    return findUltimateReffer(currentUser.referrerID); // 否则就去查找当前推荐人
}

int main()
{
    int userIDToFind = 3;                                    // 要查找的用户ID
    int ultimateReferrer = findUltimateReffer(userIDToFind); // 最终查找的结果储存起来
    printf("用户%d的最终推荐人是用户%d\n", userIDToFind, ultimateReferrer);

    return 0;
}