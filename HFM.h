#ifndef HFM_H_INCLUDED
#define HFM_H_INCLUDED



#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 100
#define MAX_BIT_NUM 20
#define CHAR_NUM 10 // 假设我们处理的是0-9的数字

typedef struct HTNode {
    int data; // 存放数字（0-9）
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef struct HCode {
    char cd[MAX_BIT_NUM];
    int start;
} HCode, *HuffmanCode;

// 函数声明
void CreateHT(HuffmanTree ht, int freq[], int n);
void CreateHCode(HuffmanTree ht, HuffmanCode hcd, int freq[], int n);
void PrintHCode(HuffmanCode hcd, int freq[], int n);



#endif // HFM_H_INCLUDED
