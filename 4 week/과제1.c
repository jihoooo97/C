#define MAX_ROWS 3
#define MAX_COLS 3

#include <stdio.h>

int main(void) {
	
	char TTT[MAX_ROWS][MAX_COLS] = {"",};
	int x, y; // x, y를 입력받을 변수
	int i, j; // 배열 출력에 쓰일 인덱스
	int win;

	printf("게임 실행 횟수 제한: 총 %d회\n", MAX_ROWS * MAX_COLS);
	for (i = 0; i < MAX_ROWS; i++) {
		printf("|---|---|---|\n|");
		for (j = 0; j < MAX_COLS; j++) {
			printf(" %d |", MAX_ROWS*i +j+1);
		}
		printf("\n");
	}
	printf("|---|---|---|\n게임 시작\n\n");

	for (int cnt = 0; cnt < MAX_ROWS*MAX_COLS; cnt++) {
		printf("%d번째 입력(user %d): ", cnt+1, cnt%2+1);
		scanf_s("%d%d", &x, &y);

		if (!(x >= 0 && x <= 2) || !(y >= 0 && y <= 2)) {
			printf("좌표를 (0, 0) ~ (2, 2)의 값만 입력하세요.\n\n");
			cnt--;
		}
		if (TTT[x][y] == 'O' || TTT[x][y] == 'X') {
			printf("이미 선택된 셀입니다.\n");
			cnt--;
		}

		else {
			if (cnt % 2 == 0)
				TTT[x][y] = 'O';
			else
				TTT[x][y] = 'X';

			for (i = 0; i < MAX_ROWS; i++) {
				printf("|---|---|---|\n|");
				for (j = 0; j < MAX_COLS; j++) {
					printf(" %c |", TTT[i][j]);
				}
				printf("\n");
			}
			printf("|---|---|---|\n\n");

			// 가로, 세로
			for (i = 0; i < MAX_ROWS; i++) {
				for (j = 0; j < MAX_COLS - 2; j++) {
					if ((TTT[i][j] != NULL && (TTT[i][j] == TTT[i][j + 1]) && (TTT[i][j + 1] == TTT[i][j + 2])) || // 가로
						(TTT[j][i] != NULL && (TTT[j][i] == TTT[j + 1][i]) && (TTT[j + 1][i] == TTT[j + 2][i]))    // 세로
						) {
						printf("승리자: user %d\n", cnt % 2 + 1);
						exit(0);
					}
				}
			}

			// 대각선
			if ((TTT[0][0] != NULL && (TTT[0][0] == TTT[1][1]) && (TTT[1][1] == TTT[2][2])) ||
				(TTT[2][0] != NULL && (TTT[2][0] == TTT[1][1]) && (TTT[1][1] == TTT[2][0]))) {
				printf("승리자: user %d\n게임 종료\n\n", cnt % 2 + 1);
				exit(0);
			}
		}
	}
	
	return 0;
}