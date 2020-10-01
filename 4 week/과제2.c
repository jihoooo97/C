#include <stdio.h>

int main(void) {

	char c = 'F';
	char* season[] = { "Spring", "Summer", "Fall", "Winter" };

	char* ptr, ** dptr;
	int i;

	ptr = &c;
	dptr = &ptr;

	printf("일반 변수  : %c\n", c);
	printf("포인터 변수: %c\n", *ptr);
	printf("이중 포인터: %c\n\n", **dptr);

	dptr = season;

	for (i = 0; i < 4; i++) {
		// 1. season을 이용해서 출력
		// *(season+i)도 가능합니다
		printf("%d번째 배열 요소 출력: %s\n", i + 1, season[i]);

		// 2. ddpr을 이용해서 출력
		printf("%d번째 배열 요소 출력: %s\n", i + 1, *(dptr + i));
	}

	return 0;

}