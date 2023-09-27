#include <stdio.h>
#define CACHE_SIZE 5

int cache[CACHE_SIZE];
int cacheUsage[CACHE_SIZE];
int cacheCount = 0;

void initCache() {
  for (int i = 0; i < CACHE_SIZE; i++) {
    cache[i] = -1; //初始化缓存中的变量为-1，假设-1表示缓存中的该位置未储存数据
    cacheUsage[i] = 0; //初始化缓存的使用情况
  }
}
int findLRUCacheIndex() {
  int minUsage = cacheUsage[0];
  int index = 0;
  for (int i = 0; i < CACHE_SIZE; i++) {
    if (cacheUsage[i] < minUsage) {
      minUsage = cacheUsage[i];
      index = i;
    }
  }
  return index;
}
void accessCache(int data) {
  int index = -1;
  for (int i = 0; i < CACHE_SIZE; i++) {
    if (cache[i] == data) {
      index = i;
      cacheUsage[i]++;
      break;
    } else if (cacheCount < CACHE_SIZE) {
      index = cacheCount;
      cache[index]=data;//别忘了移动数据
      cacheCount++;
      break;
    } else {
      index = findLRUCacheIndex();
      cache[index] = data;
      cacheUsage[index] = 0;
      break;
    }
  }
}
void addcacheUsage(int index) {
  for (int i = 0; i < CACHE_SIZE; i++) {
    if (i == index) {
      cacheUsage[i]++;
    }
  }
}
void printCache() {
  if (cacheCount < CACHE_SIZE) {
    for (int i = 0; i < cacheCount; i++) {
      printf("%d ", cache[i]); // 添加空格分隔符
    }
  }
  else {
    for (int i = 0; i < CACHE_SIZE; i++) {
      printf("%d ", cache[i]); // 添加空格分隔符
    }
  }
  printf("\n"); // 添加换行符
}


int main() {
  initCache();
  accessCache(1);
  printCache();
  return 0;
}
