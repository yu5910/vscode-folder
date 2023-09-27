#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    struct TrieNode *fail;
    bool isEndOfWord;
    char *output;
};

struct TrieNode *createNode()
{
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    node->fail = NULL;
    node->output = NULL;
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode *root, const char *key)
{
    struct TrieNode *current = root;
    for (int i = 0; key[i] != '\0'; i++)
    {
        int index = key[i] - 'a';
        if (current->children[index] == NULL)
        {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
    current->output = (char *)malloc(strlen(key) + 1);
    strcpy(current->output, key);
}

void buildAC(struct TrieNode *root)
{
    struct TrieNode **queue = (struct TrieNode **)malloc(sizeof(struct TrieNode *) * 1000);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        struct TrieNode *current = queue[front++];

        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            if (current->children[i] != NULL)
            {
                queue[rear++] = current->children[i];
                struct TrieNode *fail = current->fail;

                if (current != root)
                {
                    while (fail != NULL && fail->children[i] == NULL)
                    {
                        fail = fail->fail;
                    }
                }

                if (fail == NULL || current == root)
                {
                    current->children[i]->fail = root;
                }
                else
                {
                    current->children[i]->fail = fail->children[i];
                }

                if (current->children[i]->fail->output != NULL)
                {
                    char *newOutput = (char *)malloc(strlen(current->children[i]->output) + strlen(current->children[i]->fail->output) + 2);
                    strcpy(newOutput, current->children[i]->output);
                    strcat(newOutput, " ");
                    strcat(newOutput, current->children[i]->fail->output);
                    free(current->children[i]->output);
                    current->children[i]->output = newOutput;
                }
            }
        }
    }

    free(queue);
}

void searchAC(struct TrieNode *root, const char *text)
{
    struct TrieNode *current = root;

    for (int i = 0; text[i] != '\0'; i++)
    {
        int index = text[i] - 'a';

        while (current != root && current->children[index] == NULL)
        {
            current = current->fail;
        }

        if (current->children[index] != NULL)
        {
            current = current->children[index];
        }

        if (current->output != NULL)
        {
            printf("Found %s at position %d\n", current->output, i - strlen(current->output) + 1);
        }
    }
}

int main()
{
    struct TrieNode *root = createNode();

    // Insert keywords into the Trie
    insert(root, "hello");
    insert(root, "her");
    insert(root, "hi");
    insert(root, "how");
    insert(root, "so");
    insert(root, "see");

    // Build the AC automaton
    buildAC(root);

    // Search for words in a text
    searchAC(root, "hershow");

    return 0;
}
