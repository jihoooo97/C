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


// ����Ʈ �ʱ�ȭ
void init(PhoneBook* head) {
	head->next = head;
	head->prev = head;
}

// ��� ���� �Լ� 
void insertNode(PhoneBook* before, element data)
{
	PhoneBook* newnode = (PhoneBook*)malloc(sizeof(PhoneBook));

	newnode->data = data;
	newnode->next = before;
	newnode->prev = before->prev;
	before->prev->next = newnode;
	before->prev = newnode;

	printf("\n���� �Ϸ�!\n");
}

//���� ��� 
void printList(PhoneBook* head)
{
	PhoneBook* p;
	for (p = head->next; p->next != head; p = p->next) {
		printf("\n %s�� %s���� �����ؾ� �մϴ�.", p->data.name, p->next->data.name);
		printf(" %s�� ��ȭ��ȣ�� %s �Դϴ�.\n", p->next->data.name, p->next->data.pnum);
	}
	printf("\n------------------- \n");
}

// Ư�� ��� ���� �Լ�
void delNode(PhoneBook* head) {
	PhoneBook* p;
	PhoneBook* del;
	char name[10];

	printf("�����Ϸ��� ���: ");
	scanf(" %s", name);

	for (p = head->next; p != head; p = p->next) {
		if (strcmp(p->data.name, name) == 0) {
			del = p;
			del->prev->next = del->next;
			del->next->prev = del->prev;
			printf("\n %s�� �������ϴ�.", p->data.name);
			printf("\n %s�� %s���� �����ؾ� �մϴ�.", del->prev->data.name, del->next->data.name);
			printf(" %s�� ��ȭ��ȣ�� %s �Դϴ�.\n", del->next->data.name, del->next->data.pnum);
			free(del);
			return;
		}
	}
}

int main() {
	PhoneBook* pb = (PhoneBook *)malloc(sizeof(PhoneBook));
	int cnt = 0;
	element data; // �̸�, ��ȣ

	init(pb);

	while (strcmp(data.name, "Q") != 0) {
		printf("[%d]��° ���(Q �Է½� ����)\n", cnt + 1);
		printf("�̸�: ");
		scanf("%s", data.name);
		if (strcmp(data.name, "Q") == 0) break;

		printf("��ȭ��ȣ: ");
		scanf("%s", data.pnum);

		insertNode(pb, data);
		cnt++;
	}

	printList(pb);
	printf("��� �������鿡�� ������ �߽��ϴ�.\n\n");

	delNode(pb);

	return 0;

}