// Middle of the Linked List.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head) {
	
	struct ListNode* p = head;
	int length = 0;
	int i;

	for (p = head; p != NULL; p = p->next)
	{
		length++;
	}

	int middle = length / 2;

	p = head;
	for (i = 0; i < middle; i++)
	{
		p = p->next;
	}
	return p;
}

struct ListNode* list(int* vals, int length)
{
	ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));;
	ListNode* pnew;
	ListNode* pend;

	int i;
	if (length > 0){
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
	int input[] = { 1, 2, 3, 4, 5 };
	int length = 5;
//	int input[] = { 1,2,3,4,5,6 };
//	int length = 6;
	int* vals = input;

	ListNode* head;
	head = list(vals, length);

	ListNode* middle = middleNode(head);

	printf("%d", middle->val);

	int a = 5;
	int b = a / 2;
	int e = a % 2;

	int c = 6;
	int d = c / 2;
	int f = c % 2;
    
	return 0;
}
