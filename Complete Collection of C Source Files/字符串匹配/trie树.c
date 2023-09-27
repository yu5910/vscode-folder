#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode* root, const char* key) {
    struct TrieNode* current = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}
void printWords(struct TrieNode* node, char* prefix) {
    if (node->isEndOfWord) {
        printf("%s\n", prefix); // 如果是单词的结尾，打印单词
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            char newPrefix[strlen(prefix) + 2]; // 创建一个新的前缀字符串
            strcpy(newPrefix, prefix); // 复制旧前缀到新前缀
            newPrefix[strlen(prefix)] = 'a' + i; // 向新前缀添加字符
            newPrefix[strlen(prefix) + 1] = '\0'; // 添加字符串结束符
            printWords(node->children[i], newPrefix); // 递归打印子树
        }
    }
}

void search(struct TrieNode* root, const char* prefix) {
    struct TrieNode* current = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        if (current->children[index] == NULL) {
            return;
        }
        current = current->children[index];
    }
    // Print all words with the given prefix
    printWords(current, prefix);
}



int main() {
    struct TrieNode* root = createNode();
      
    // Insert keywords into the trie
    insert(root, "hello");
    insert(root, "her");
    insert(root, "hi");
    insert(root, "how");
    insert(root, "so");
    insert(root, "see");
    
    // Search for words with the given prefix
    search(root, "h");
    
    return 0;
}
