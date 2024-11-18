#include "HFM.h"

void CreateHT(HuffmanTree ht, int freq[], int n) {
    int i, k, lnode, rnode;
    int min1, min2;

    for (i = 0; i < 2 * n - 1; i++) {
        ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
    }

    min1 = min2 = INT_MAX;

    for (i = n; i < 2 * n - 1; i++) {
        lnode = rnode = -1;
        min1 = min2 = INT_MAX;
        for (k = 0; k < i; k++) {
            if (ht[k].parent == -1) {
                if (freq[k] < min1) {
                    min2 = min1;
                    rnode = lnode;
                    min1 = freq[k];
                    lnode = k;
                } else if (freq[k] < min2) {
                    min2 = freq[k];
                    rnode = k;
                }
            }
        }

        ht[i].weight = freq[lnode] + freq[rnode];
        ht[i].lchild = lnode;
        ht[i].rchild = rnode;
        ht[lnode].parent = i;
        ht[rnode].parent = i;
    }
}

void CreateHCode(HuffmanTree ht, HuffmanCode hcd, int freq[], int n) {
    int i, f, c;
    HCode hc;
    for (i = 0; i < n; i++) {
        hc.start = MAX_BIT_NUM - 1;
        c = i;
        f = ht[i].parent;
        while (f != -1) {
            if (ht[f].lchild == c) {
                hc.cd[hc.start--] = '0';
            } else {
                hc.cd[hc.start--] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        hc.start++;
        hcd[i] = hc;
    }
}

void PrintHCode(HuffmanCode hcd, int freq[], int n) {
    for (int i = 0; i < n; i++) {
        if (freq[i] > 0) { // 只打印出现过的数字的编码
            printf("Number: %d, Huffman Code: ", i);
            for (int j = hcd[i].start; j < MAX_BIT_NUM; j++) {
                printf("%c", hcd[i].cd[j]);
            }
            printf("\n");
        }
    }
}
