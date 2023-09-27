#define LOAD_FACTOR_THRESHOLD 0.75
#define SHRINK_FACTOR_THRESHOLD 0.25

// 扩容函数
void expand(HashTable *ht)
{
    int newSize = ht->size * 2;
    Node **newTable = malloc(sizeof(Node *) * newSize);
    for (int i = 0; i < newSize; i++)
    {
        newTable[i] = NULL;
    }
    for (int i = 0; i < ht->size; i++)
    {
        Node *node = ht->table[i];
        while (node != NULL)
        {
            Node *next = node->next;
            int newIndex = hashCode(node->key, newSize);
            node->next = newTable[newIndex];
            newTable[newIndex] = node;
            node = next;
        }
    }
    free(ht->table);
    ht->table = newTable;
    ht->size = newSize;
}

// 缩容函数
void shrink(HashTable *ht)
{
    int newSize = ht->size / 2;
    Node **newTable = malloc(sizeof(Node *) * newSize);
    for (int i = 0; i < newSize; i++)
    {
        newTable[i] = NULL;
    }
    for (int i = 0; i < ht->size; i++)
    {
        Node *node = ht->table[i];
        while (node != NULL)
        {
            Node *next = node->next;
            int newIndex = hashCode(node->key, newSize);
            node->next = newTable[newIndex];
            newTable[newIndex] = node;
            node = next;
        }
    }
    free(ht->table);
    ht->table = newTable;
    ht->size = newSize;
}

// 插入节点
void insert(HashTable *ht, int key, int val)
{
    // ... 插入节点的代码 ...

    // 检查是否需要扩容
    if (ht->count > ht->size * LOAD_FACTOR_THRESHOLD)
    {
        expand(ht);
    }
}

// 删除节点
void delete(HashTable *ht, int key)
{
    // ... 删除节点的代码 ...

    // 检查是否需要缩容
    if (ht->count < ht->size * SHRINK_FACTOR_THRESHOLD && ht->size > 1)
    {
        shrink(ht);
    }
}
