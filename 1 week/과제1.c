#define _CRT_SECURE_NO_WARNINGS

/*  작성자: 201621142 유지호  */

#include <stdio.h>

// 10진수를 2진수로 변환하는 함수
void Dec_to_Bin(int n)
{
    int i;                      // 정수형 index 변수
    int bin[16] = { 0 };          // 16비트를 표현하기 위해 배열을 0으로 초기화

    for (i = 0; i < 16; i++) {
        bin[i] = n % 2;           // 배열에 10진수를 2로 나머지 연산 후 입력
        n = n / 2;                 // 다시 2로 나누기
        if (n == 0) break;         // 연산을 다 해서 n이 0이면 반복문 탈출
    }
    for (i = 15; i >= 0; i--) {      // 16비트로 출력
        printf("%d", bin[i]);
        if (i != 0 && i % 8 == 0)        // 8비트씩 띄워서 출력 ex: 00000000 00000001
            printf(" ");
    }
    printf("(2)\n");
}

int main(void)
{
    int dec, i;

    printf("16비트까지 2진수 구하기\n\n");
    for (i = 0; i < 3; i++) {        // 3번의 결과를 확인하기 위해 반복 
        printf("10진수 입력: ");
        scanf("%d", &dec);

        if (dec > 65536) {
            printf("16비트까지의 값을 입력하세요. (최대65536)\n");
            continue;
        }

        Dec_to_Bin(dec);        // 입력받은 10진수를 함수에
        printf("\n");           // 매개변수로 전달하면서 함수 호출
    }

    system("pause");
    return 0;

}