#include <stdio.h>

// 定义一个用户结构体，包含用户ID和最终推荐人ID
typedef struct
{
    int userID;
    int ultimateReferrerID;
} User;

// 用户数组，用于存储用户信息
User users[] = {
    {1, -1}, // 用户A
    {2, 1},  // 用户B（被用户A推荐）
    {3, 2},  // 用户C（被用户B推荐）
    {4, 1},  // 用户D（被用户A推荐）
    {5, 4}   // 用户E（被用户D推荐）
};

// 迭代函数，找到用户的最终推荐人
int findUltimateReferrer(int userID)
{
    // 找到对应userID的用户信息
    User currentUser;
    for (int i = 0; i < sizeof(users) / sizeof(users[0]); i++)
    {
        if (users[i].userID == userID)
        {
            currentUser = users[i];
            break;
        }
    }

    // 上一步匹配到了用户，这一步开始迭代查找xia一个
    while (currentUser.ultimateReferrerID != -1)
    { // 确定循环的终止条件，这是while循环的要点
        userID = currentUser.ultimateReferrerID;
        for (int i = 0; i < sizeof(users) / sizeof(users[0]); i++)
        {
            // 开始看看是否有人能匹配到该用户的推荐人，如果匹配不到，那该用户就是最终推荐人
            if (users[i].userID == userID)
            {
                currentUser = users[i];
                break; // 匹配到就退出，继续进入while循环，退出太容易忘啦，不如switch
            }
        }
    }

    return userID;
}

int main()
{
    // 示例：找到用户C的最终推荐人
    int userIDToFind = 3;
    int ultimateReferrer = findUltimateReferrer(userIDToFind);
    printf("用户%d的最终推荐人是用户%d\n", userIDToFind, ultimateReferrer);

    return 0;
}