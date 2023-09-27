#include <stdio.h>
#include <stdlib.h>

// 定义学生结构体
typedef struct Student
{
    int studentID;
    int score;
} student;

// 定义跳表节点结构体
typedef struct SkipListNode
{
    int key;
    student *value;
    struct SkipListNode **next;
} skipListNode;

// 定义跳表结构体
typedef struct SkipList
{
    int level;            // 当前跳表的层级数
    int maxLength;        // 当前跳表的最大层级
    skipListNode *header; // 头节点
} skipList;

// 创建新的学生节点
student *createStudent(int studentID, int score)
{
    student *newStudent = (student *)malloc(sizeof(student));
    newStudent->studentID = studentID;
    newStudent->score = score;
    return newStudent;
}

// 创建新的跳表节点
skipListNode *createSkipListNode(int key, student *value, int level)
{
    skipListNode *newNode = (skipListNode *)malloc(sizeof(skipListNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = (skipListNode **)malloc((level + 1) * sizeof(skipListNode *));
    for (int i = 0; i <= level; i++)
    {
        newNode->next[i] = NULL;
    }
    return newNode;
}

// 创建新的跳表
skipList *createSkipList(int maxLength)
{
    skipList *newSkipList = (skipList *)malloc(sizeof(skipList));
    newSkipList->level = 0;
    newSkipList->maxLength = maxLength;
    newSkipList->header = createSkipListNode(-1, NULL, maxLength);
    return newSkipList;
}

// 在跳表中查找学生信息
student *search(skipList *list, int studentID)
{
    skipListNode *node = list->header;
    for (int level = list->level; level >= 0; level--)
    {
        while (node->next[level] != NULL && node->next[level]->key < studentID)
        {
            node = node->next[level];
        }
    }
    node = node->next[0];
    if (node != NULL && node->key == studentID)
    {
        return node->value;
    }
    return NULL;
}

// 在跳表中插入学生信息
void insert(skipList *list, int studentID, int score)
{
    student *newStudent = createStudent(studentID, score);
    skipListNode *update[list->maxLength + 1];
    skipListNode *node = list->header;
    for (int level = list->level; level >= 0; level--)
    {
        while (node->next[level] != NULL && node->next[level]->key < studentID)
        {
            node = node->next[level];
        }
        update[level] = node;
    }
    node = node->next[0];
    if (node == NULL || node->key != studentID)
    {
        int newNodeLevel = 0;
        while (rand() < RAND_MAX / 2 && newNodeLevel < list->maxLength)
        {
            newNodeLevel++;
        }

        if (newNodeLevel > list->level)
        {
            for (int level = list->level + 1; level <= newNodeLevel; level++)
            {
                update[level] = list->header;
            }
            list->level = newNodeLevel;
        }

        skipListNode *newNode = createSkipListNode(studentID, newStudent, newNodeLevel);

        for (int level = 0; level <= newNodeLevel; level++)
        {
            newNode->next[level] = update[level]->next[level];
            update[level]->next[level] = newNode;
        }
    }
}

// 在跳表中删除学生信息
void delete(skipList *list, int studentID)
{
    skipListNode *update[list->maxLength + 1];
    skipListNode *node = list->header;

    for (int level = list->level; level >= 0; level--)
    {
        while (node->next[level] != NULL && node->next[level]->key < studentID)
        {
            node = node->next[level];
        }
        update[level] = node;
    }

    node = node->next[0];

    if (node != NULL && node->key == studentID)
    {
        for (int level = 0; level <= list->level; level++)
        {
            if (update[level]->next[level] != node)
            {
                break;
            }
            update[level]->next[level] = node->next[level];
        }

        free(node->value);
        free(node);

        while (list->level > 0 && list->header->next[list->level] == NULL)
        {
            list->level--;
        }
    }
}

// 测试代码
int main()
{
    skipList *list = createSkipList(5);

    insert(list, 1001, 85);
    insert(list, 1002, 92);
    insert(list, 1005, 78);
    insert(list, 1003, 95);

    student *searchResult = search(list, 1005);
    if (searchResult != NULL)
    {
        printf("Student ID: %d, Score: %d\n", searchResult->studentID, searchResult->score);
    }
    else
    {
        printf("Student not found.\n");
    }

    delete (list, 1002);

    searchResult = search(list, 1002);
    if (searchResult != NULL)
    {

        printf("Student ID: %d, Score: %d\n", searchResult->studentID, searchResult->score);
    }
    else
    {
        printf("Student not found.\n");
    }

    return 0;
}
