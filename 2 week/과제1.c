#define RAWS 3   // 행
#define COLS 4   // 열

#include <stdio.h>

int main() {

	int arr[RAWS][COLS];  // 2차원 배열 선언
	int* ptrArr = arr;

	// 배열 초기화

	for (int i = 0; i < RAWS; i++) {

		for (int j = 0; j < COLS; j++) {
			arr[i][j] = (COLS * i) + j + 1;  // 1 ~ 12(RAWS * COLS)까지 초기화

			printf("%3d ", *(ptrArr + (COLS * i) + j));  // 배열 포인터로 출력
		}
		printf("\n");
	}

	return 0;

}