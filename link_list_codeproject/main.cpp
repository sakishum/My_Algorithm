#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <stack>

typedef char ElemType;

struct Node {
	Node(ElemType a,  struct Node *pnext = nullptr) : data_(a), next(pnext) { }
	ElemType data_;
	struct Node *next;
};

void reverse(Node *list) {
	Node *p = nullptr, *q = nullptr;
	p = list->next;				// p 为原链表的当前处理节点
	list->next = nullptr;		// 逆置链表初始化为空

	while (p != nullptr) {		// 当前链表未处理完
		q = p->next;			// q 指针保留原链表当前处理节点的下一个节点
		p->next = list->next;	// 将当前处理节点 p 插入到逆置链 L 的表头
		list->next = p;			
		p = q;					// p 指针指向下一个待插入节点
	}
}

void printlist(Node *list) {
	if (!list) {
		return;
	}

	std::stack<int> sta;
	Node *p = list->next;
	while (p) {
		sta.push(p->data_);
		p = p->next;
	}
	printf("From stack:\n");
	while (!sta.empty()) {
		printf("%d, ", sta.top());
		sta.pop();
	}
	printf("\n");
}

void reverselist(Node *head) {
	if (nullptr == head) {
		return;
	}
	Node *p = nullptr;
	Node *q = nullptr;
	p = head->next;
	head->next = nullptr;
	while (p) {
		q = p->next;
		p->next = head->next;
		head->next = p;
		p = q;
	}
}

void printall(Node *list) {
	Node *p = list->next;
	while (p) {
		printf("%d, ", p->data_);
		p = p->next;
	}
	printf("\n");
}

auto main(int32_t, char**) -> int32_t {
	Node *n3 = new Node(3);
	Node *n2 = new Node(2, n3);
	Node *n1 = new Node(1, n2);
	Node *list = new Node(0, n1);
	printlist(list);
	//printall(list);
	//reverse(list);
	reverselist(list);
	printall(list);

	exit(EXIT_SUCCESS);
}
