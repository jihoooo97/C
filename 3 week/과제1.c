// 작성자 201621142 유지호
#define MAX_ARR 10

#include <stdio.h>

int SequentialSearch(int num, int *arr, int n) {
    if (arr[n] == num) return n;
    if (n == -1) return -1;
    SequentialSearch(num, arr, n-1);
}

int main() {
    int data[MAX_ARR] = { 2,3,5,7,8,9,11,13,15,20 };
    int num, result;

    while (1) {

        printf("찾으려는 숫자를 입력하시오: ");
        scanf("%d", &num);
        if (num < 0) {
            printf("양의 정수만 입력해주세요.\n");
            continue;
        }

        result = SequentialSearch(num, data, MAX_ARR - 1);
        if (result == -1) {
            printf("해당 숫자가 존재하지 않습니다.\n");
            continue;
        }
        printf("%d는 %d번 index에 있습니다.\n", num, result);
        break;

    }

	return 0;
}