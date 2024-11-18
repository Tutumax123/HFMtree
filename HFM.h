#ifndef HFM_H_INCLUDED
#define HFM_H_INCLUDED



#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 100
#define MAX_BIT_NUM 20
#define CHAR_NUM 10 // �������Ǵ������0-9������

typedef struct HTNode {
    int data; // ������֣�0-9��
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

typedef struct HCode {
    char cd[MAX_BIT_NUM];
    int start;
} HCode, *HuffmanCode;

// ��������
void CreateHT(HuffmanTree ht, int freq[], int n);
void CreateHCode(HuffmanTree ht, HuffmanCode hcd, int freq[], int n);
void PrintHCode(HuffmanCode hcd, int freq[], int n);



#endif // HFM_H_INCLUDED
