#include <stdlib.h>

// 定义节点
typedef struct Node
{
    int key;
    int val;
    int isOccupied; // 标记此位置是否被占用
} Node;

// 定义哈希表
typedef struct HashTable
{
    int size;
    Node *table;
} HashTable;

// 初始化哈希表
HashTable *createHashTable(int size)
{
    HashTable *ht = malloc(sizeof(HashTable));
    ht->size = size;
    ht->table = malloc(sizeof(Node) * size);
    for (int i = 0; i < size; i++)
    {
        ht->table[i].isOccupied = 0;
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
    while (ht->table[idx].isOccupied)
    {
        idx = (idx + 1) % ht->size; // 线性探测
    }
    ht->table[idx].key = key;
    ht->table[idx].val = val;
    ht->table[idx].isOccupied = 1;
}

// 查找节点
Node *search(HashTable *ht, int key)
{
    int idx = hashCode(key, ht->size);
    while (ht->table[idx].isOccupied && ht->table[idx].key != key)
    {
        idx = (idx + 1) % ht->size; // 线性探测
    }
    if (ht->table[idx].isOccupied)
    {
        return &ht->table[idx];
    }
    else
    {
        return NULL;
    }
}

// 删除节点
void delete(HashTable *ht, int key)
{
    int idx = hashCode(key, ht->size);
    while (ht->table[idx].isOccupied && ht->table[idx].key != key)
    {
        idx = (idx + 1) % ht->size; // 线性探测
    }
    if (ht->table[idx].isOccupied)
    {
        ht->table[idx].isOccupied = 0;
    }
}

// 二次探测// 插入节点
void insert(HashTable *ht, int key, int val)
{
    int idx = hashCode(key, ht->size);
    int i = 1;
    while (ht->table[idx].isOccupied)
    {
        idx = (idx + i * i) % ht->size; // 二次探测
        i++;
    }
    ht->table[idx].key = key;
    ht->table[idx].val = val;
    ht->table[idx].isOccupied = 1;
}