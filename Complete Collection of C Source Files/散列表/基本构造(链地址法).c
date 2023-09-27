//直接用的高级解法,即散列表和链表一块用

#include <stdlib.h>

// 定义节点
typedef struct Node
{
    int key;
    int val;
    struct Node *next;
} Node;

// 定义哈希表
typedef struct HashTable
{
    int size;
    Node **table;
} HashTable;

// 初始化哈希表
HashTable *createHashTable(int size)
{
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = malloc(sizeof(Node *) * size);
    for (int i = 0; i < size; i++)
    {
        ht->table[i] = NULL;
    }
    return ht;
}

// 哈希函数
int hashCode(int key, int size)
{
    return key % size;
}

// 插入节点
void insert(HashTable *ht, int key, int val)
{
    int idx = hashCode(key, ht->size);
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->val = val;
    node->next = ht->table[idx];
    ht->table[idx] = node;
}

// 查找节点
Node *search(HashTable *ht, int key)
{
    int idx = hashCode(key, ht->size);
    Node *node = ht->table[idx];
    while (node != NULL && node->key != key)
    {
        node = node->next;
    }
    return node;
}

// 删除节点
void delete(HashTable *ht, int key)
{
    int idx = hashCode(key, ht->size);
    Node *node = ht->table[idx];
    Node *prev = NULL;
    while (node != NULL && node->key != key)
    {
        prev = node;
        node = node->next;
    }
    if (node == NULL)
    {
        return; // 没有找到要删除的节点
    }
    if (prev == NULL)
    {
        ht->table[idx] = node->next; // 删除的是头节点
    }
    else
    {
        prev->next = node->next; // 删除的是中间或尾节点
    }
    free(node);
}
// 释放哈希表
void freeHashTable(HashTable *ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        Node *node = ht->table[i];
        while (node != NULL)
        {
            Node *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}
