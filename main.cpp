#include "HFM.h"

int main() {
    char input[1000]; // 假设输入的数字串长度不超过1000个字符
    int freq[CHAR_NUM] = {0}; // 数字0-9的出现次数
    HuffmanTree ht = (HuffmanTree)malloc(MAX_TREE_NODES * sizeof(HTNode));
    HuffmanCode hcd = (HuffmanCode)malloc(CHAR_NUM * sizeof(HCode));
    int n = CHAR_NUM; // 数字0-9，共10个

    printf("请输入一串数字：\n");
    scanf("%s", input);

    // 统计每个数字的出现次数
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            freq[input[i] - '0']++;
        } else {
            printf("输入包含非法字符，请输入0-9之间的数字。\n");
            free(ht);
            free(hcd);
            return 1;
        }
    }

    // 初始化哈夫曼树节点数据
    for (int i = 0; i < n; i++) {
        ht[i].data = i;
        ht[i].weight = freq[i];
    }

    // 构建哈夫曼树
    CreateHT(ht, freq, n);

    // 生成哈夫曼编码
    CreateHCode(ht, hcd, freq, n);

    // 打印哈夫曼编码
    PrintHCode(hcd, freq, n);

    // 释放内存
    free(ht);
    free(hcd);

    return 0;
}
