// 작성자 201621142 유지호

#include <stdio.h>
#include <string.h>

void CheckAanagram(char* s1, char* s2) {

	if (strlen(s1) != strlen(s2))
		printf("%s와(과) %s는(은) 애너그램이 아닙니다.\n", s1, s2);
	else {
		int i, j;
		int idx, cnt=0, len = strlen(s1); // 일치하는 글자 표기할 idx, 애너그램여부 판별 cnt
		int alp[26] = { 0, }; // 알파벳 누적할 배열
		char *str1 = malloc(sizeof(char) * len);
		char *str2 = malloc(sizeof(char) * len);

		strcpy(str1, s1);
		strcpy(str2, s2);

		// 문자열을 소문자로 변환
		for (i = 0;i < len; i++) {
			if (str1[i] >= 'A' && str1[i] <= 'Z')
				str1[i] += ('a' - 'A');

			if (str2[i] >= 'A' && str2[i] <= 'Z')
				str2[i] += ('a' - 'A');

		}

		// 알파벳 비교후 해당하면 누적
		for (i = 0; i < len; i++) {
			for (j = 0; j < len; j++) {
				if (str1[i] == str2[j]) { // 문자열 비교
					idx = str1[i] - 97;// 알파벳 배열에서 해당 알파벳 위치 0~25
					alp[idx]++;        // ex) a면 ascii 97이므로 97을 뺀 0부터 인덱스
					cnt++;			   // 일치하는 글자수 카운트
					str2[j] = "";	   // 중복되지 않게 함
					break;
				}
			}
		}

		if (cnt == len) {
			printf("=========== 일치하는 글자 ===========\n");
			for (i = 0; i < 26; i++)
				if (alp[i] != 0)
					printf("%c: %d  ", i + 97, alp[i]);

			printf("\n=====================================\n");
			printf("%s와 %s는 애너그램입니다.\n\n", s1, s2);
		}
		else
			printf("%s와 %s는 애너그램이 아닙니다.\n\n", s1, s2);

	}

}


int main() {

	char s1[] = "Everland";
	char s2[] = "Lavender";
	CheckAanagram(s1, s2);

	char s3[] = "split";
	char s4[] = "lisp";
	CheckAanagram(s3, s4);


	return 0;

}