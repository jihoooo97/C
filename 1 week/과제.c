#define _CRT_SECURE_NO_WARNINGS

/*  �ۼ���: 201621142 ����ȣ  */

#include <stdio.h>

// 10������ 2������ ��ȯ�ϴ� �Լ�
void Dec_to_Bin(int n)
{
    int i;                      // ������ index ����
    int bin[16] = { 0 };          // 16��Ʈ�� ǥ���ϱ� ���� �迭�� 0���� �ʱ�ȭ

    for (i = 0; i < 16; i++) {
        bin[i] = n % 2;           // �迭�� 10������ 2�� ������ ���� �� �Է�
        n = n / 2;                 // �ٽ� 2�� ������
        if (n == 0) break;         // ������ �� �ؼ� n�� 0�̸� �ݺ��� Ż��
    }
    for (i = 15; i >= 0; i--) {      // 16��Ʈ�� ���
        printf("%d", bin[i]);
        if (i != 0 && i % 8 == 0)        // 8��Ʈ�� ����� ��� ex: 00000000 00000001
            printf(" ");
    }
    printf("(2)\n");
}

int main(void)
{
    int dec, i;

    printf("16��Ʈ���� 2���� ���ϱ�\n\n");
    for (i = 0; i < 3; i++) {        // 3���� ����� Ȯ���ϱ� ���� �ݺ� 
        printf("10���� �Է�: ");
        scanf("%d", &dec);

        if (dec > 65536) {
            printf("16��Ʈ������ ���� �Է��ϼ���. (�ִ�65536)\n");
            continue;
        }

        Dec_to_Bin(dec);        // �Է¹��� 10������ �Լ���
        printf("\n");           // �Ű������� �����ϸ鼭 �Լ� ȣ��
    }

    system("pause");
    return 0;

}