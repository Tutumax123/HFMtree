#include "HFM.h"

int main() {
    char input[1000]; // ������������ִ����Ȳ�����1000���ַ�
    int freq[CHAR_NUM] = {0}; // ����0-9�ĳ��ִ���
    HuffmanTree ht = (HuffmanTree)malloc(MAX_TREE_NODES * sizeof(HTNode));
    HuffmanCode hcd = (HuffmanCode)malloc(CHAR_NUM * sizeof(HCode));
    int n = CHAR_NUM; // ����0-9����10��

    printf("������һ�����֣�\n");
    scanf("%s", input);

    // ͳ��ÿ�����ֵĳ��ִ���
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            freq[input[i] - '0']++;
        } else {
            printf("��������Ƿ��ַ���������0-9֮������֡�\n");
            free(ht);
            free(hcd);
            return 1;
        }
    }

    // ��ʼ�����������ڵ�����
    for (int i = 0; i < n; i++) {
        ht[i].data = i;
        ht[i].weight = freq[i];
    }

    // ������������
    CreateHT(ht, freq, n);

    // ���ɹ���������
    CreateHCode(ht, hcd, freq, n);

    // ��ӡ����������
    PrintHCode(hcd, freq, n);

    // �ͷ��ڴ�
    free(ht);
    free(hcd);

    return 0;
}
