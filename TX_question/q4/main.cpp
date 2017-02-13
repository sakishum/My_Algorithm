/**
 * @file main.cpp
 * @Synopsis  单链表反转
 *			  
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-01-22
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

struct ListNode {
	int m_nKey;
	ListNode* m_pNext;
};

/// 反转链表 ( 带头结点)
void ReverseList(ListNode *pHead) {
	if (NULL == pHead) {
		return;
	}
	ListNode *pNode = pHead;
	ListNode *pPrev = NULL;
	ListNode *pNext = NULL;
	while (NULL != pNode) {
		pNext = pNode->m_pNext;
		if (NULL == pNext) {
			pHead = pNode;
		}
		//printf("%d\n", pNode->m_nKey);
		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
}

int main(int, char**) {
	int a = 4;
	(++a) += (a++);
	printf("a = %d\n", a);	// 11
	//int arr[];	// 定义数组时必须要显式设置数组大小
	printf("sizeof(long) = %zu\n", sizeof(long));
	printf("sizeof(double) = %zu\n", sizeof(double));
	ListNode *list1 = new ListNode();
	ListNode *list2 = new ListNode();
	ListNode *list3 = new ListNode();

	list1->m_nKey = 3;
	list1->m_pNext = list2;
	list2->m_nKey = 2;
	list2->m_pNext = list3;
	list3->m_nKey = 1;
	list3->m_pNext = NULL;

	printf("Before: \n");
	ListNode *pStart = list1;
	while (pStart != NULL) {
		printf("%d\t", pStart->m_nKey);
		pStart = pStart->m_pNext;
	}
	printf("\nProcessing...\n");
	ReverseList(list1);
	
	printf("After: \n");
	pStart = list3;
	while (pStart != NULL) {
		printf("%d\t", pStart->m_nKey);
		pStart = pStart->m_pNext;
	}

	delete list1;
	list1 = NULL;
	delete list2;
	list2 = NULL;
	delete list3;
	list3 = NULL;
	{
		int a = 2;
		int b = 1;
		int c = 2;
		std::cout << (a ^ b << c) << std::endl;;
	}
	return EXIT_SUCCESS;
}
