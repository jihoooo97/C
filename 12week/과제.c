#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>

typedef struct {
	char name[10];
	char pnum[10];
} element;

typedef struct PhoneBook {
	element data;
	struct PhoneBook* next;
	struct PhoneBook* prev;
} PhoneBook;


// 리스트 초기화
void init(PhoneBook* head) {
	head->next = head;
	head->prev = head;
}

// 노드 삽입 함수 
void insertNode(PhoneBook* before, element data)
{
	PhoneBook* newnode = (PhoneBook*)malloc(sizeof(PhoneBook));

	newnode->data = data;
	newnode->next = before;
	newnode->prev = before->prev;
	before->prev->next = newnode;
	before->prev = newnode;

	printf("\n삽입 완료!\n");
}

//정순 출력 
void printList(PhoneBook* head)
{
	PhoneBook* p;
	for (p = head->next; p->next != head; p = p->next) {
		printf("\n %s는 %s에게 연락해야 합니다.", p->data.name, p->next->data.name);
		printf(" %s의 전화번호는 %s 입니다.\n", p->next->data.name, p->next->data.pnum);
	}
	printf("\n------------------- \n");
}

// 특정 노드 삭제 함수
void delNode(PhoneBook* head) {
	PhoneBook* p;
	PhoneBook* del;
	char name[10];

	printf("삭제하려는 사람: ");
	scanf(" %s", name);

	for (p = head->next; p != head; p = p->next) {
		if (strcmp(p->data.name, name) == 0) {
			del = p;
			del->prev->next = del->next;
			del->next->prev = del->prev;
			printf("\n %s가 빠졌습니다.", p->data.name);
			printf("\n %s는 %s에게 연락해야 합니다.", del->prev->data.name, del->next->data.name);
			printf(" %s의 전화번호는 %s 입니다.\n", del->next->data.name, del->next->data.pnum);
			free(del);
			return;
		}
	}
}

int main() {
	PhoneBook* pb = (PhoneBook *)malloc(sizeof(PhoneBook));
	int cnt = 0;
	element data; // 이름, 번호

	init(pb);

	while (strcmp(data.name, "Q") != 0) {
		printf("[%d]번째 사람(Q 입력시 종료)\n", cnt + 1);
		printf("이름: ");
		scanf("%s", data.name);
		if (strcmp(data.name, "Q") == 0) break;

		printf("전화번호: ");
		scanf("%s", data.pnum);

		insertNode(pb, data);
		cnt++;
	}

	printList(pb);
	printf("모든 구성원들에게 연락을 했습니다.\n\n");

	delNode(pb);

	return 0;

}