#include "pch.h"
#include <iostream>

struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode * start, * end;
	start = head;
	int i;

	end = start;
	for (i = 0; i < n; i++) {
		end = end->next;
	}

	//when (the length of list) = n 
	if (end == NULL) {
		head = head->next;
		return head;
	}

	while (end->next != NULL) {
		start = start->next;
		end = end->next;
	}

	struct ListNode * q;
	q = start->next;
	start->next = q->next;
	free(q);

	return head;
}

/*struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	int length = 0;
	struct ListNode * p;
	int i;

	for (p = head; p != NULL; p = p->next) {
		length++;
	}

	if (length == 1) {
		return NULL;
	}

	int Nth = length - n;

	if (Nth == 0) {
		head = head->next;
	}
	else {

		if (Nth == length - 1) {
			p = head;
			for (i = 0; i < Nth - 1; i++) {
				p = p->next;
			}
			p->next = NULL;
		}
		else {
			p = head;
			for (i = 0; i < Nth - 1; i++) {
				p = p->next;
			}

			struct ListNode *q;
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	return head;
}
*/

struct ListNode* Createlist(int* vals, int length)
{
	ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));;
	ListNode* pnew;
	ListNode* pend;

	int i;
	if (length > 0) {
		head->val = vals[0];
		head->next = NULL;
	}
	pend = head;
	pend->next = NULL;

	for (i = 1; i < length; i++) {
		pnew = (struct ListNode*)malloc(sizeof(struct ListNode));
		pnew->val = vals[i];
		pnew->next = NULL;

		pend->next = pnew;
		pend = pnew;
	}
	return head;
};

int main()
{
	//int input[5] = {1, 2, 3, 4, 5};
	//int length = 5;
	//int n = 2;

	int input[2] = {1, 2};
	int length = 2;
	int n = 2;

	ListNode * p;

	ListNode * head;
	head = Createlist(input, length);

	ListNode * output;
	output = removeNthFromEnd(head, n);

	for (p = output; p != NULL; p = p->next) {
		printf("%d", p->val);
	}

	return 0;
}

