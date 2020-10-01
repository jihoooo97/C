#define LEN 10

#include <stdio.h>

int main() {

	int i, j;

	int target;

	int data[LEN] = { 9, 11, 3, 5, 7, 8, 15, 13, 2, 20 };



	for (i = 1; i < LEN; i++) {

		target = data[i];  // 정렬할 기준값

		//

		for (j = i-1; j >= 0 && data[j] > target; j--) {

			data[j + 1] = data[j];

		}

		data[j+1] = target;

	}

	printf("정렬 완료:");

	for (i = 0; i < LEN; i++)

		printf("%d ", data[i]);



	return 0;

}