#include <stdio.h>
#include <stdlib.h>

int move = 0;
typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

void error(char *message) 
{
	fprintf(stderr, "%s\n", message);
}
/*
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	move++;
	printf("Move : %d", move);
	return head;
}*/

ListNode* insert_at(ListNode* head, int pos, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	int move = 0;
	if (head == NULL)
	{
		head = p;
		p->data = value;
		p->link = NULL;
		
	}
	else if (pos == 0)
	{
		p->data = value;
		p->link = head;
		head = p;
		
	}
	else {
		ListNode* pre = head;
		for (int i = 0; i < pos - 1; i++)
		{
			if (pre->link == NULL)
			{
				ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
				new_node->data = value;
				new_node->link = NULL;
				pre->link = new_node;
				move++;
				printf("Move: %d\n", move);
				return head;
			}
			pre = pre->link;
			move++;
		}
		ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
		new_node->data = value;
		new_node->link = pre->link;
		pre->link = new_node;
		move++;
	}
	printf("Move: %d\n", move);
	return head;
}



ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* delete(ListNode* head, ListNode* pre, int pos)
{
	int move = 0;
	ListNode* removed;

	if (head == NULL)
	{
		printf("List is empty.\n");
		return head;
	}

	if (pos == 0)
	{
		removed = head;
		head = head->link;

	}
	else if (pre == NULL)
	{
		return head;
	}
	else
	{
		removed = pre->link;
		pre->link = removed->link;
		move++;
	}

	printf("Moves: %d\n", move);
	free(removed);
	return head;
}
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
}
int main(void)
{
	ListNode *head = NULL;
	ListNode *pre = NULL;
	int element;
	int s = 0;
	int pos = 0;
	while (1)
	{
		printf("\n= = = = Menu = = = =\n");
		printf("0. Exit\n1. Insert \n2. Delete \n3. Print\n");
		printf("\nSlect Menu = ");
		scanf_s("%d", &s);
		if (s == 1)
		{
			printf("\nEnter the position: ");
			scanf_s("%d %d", &pos, &element);
			head = insert_at(head, pos, element); 
			if (head == NULL) { 
				printf("Failed to insert..\n"); 
			}
			else { // 삽입이 성공적으로 이루어졌다면
				printf("\n");
			}
		}
		else if (s == 2)
		{
			printf("\nDelete the position: ");
			scanf_s("%d", &pos);
			head = delete(head,pre,pos);
		}

		else if (s == 3)
		{
			print_list(head);
		}

		else if (s == 0) {
			printf("Exit the program");
			break;
		}
		else {
			printf("잘못된 입력입니다. 다시 입력 해주세요\n");

		}
	}
}