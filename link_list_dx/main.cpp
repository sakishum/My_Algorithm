#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <stack>

struct Node {
	int data;
	Node *next;
};

void reverse(Node *head) {
	Node *pre = NULL;
	Node *cur = head->next;
	Node *next = NULL;
	while (cur) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	head->next = pre;
}

void loop(Node *head) {
	Node *node = head->next;
	while (node) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;
}

void rloop(Node *head) {
	Node *node = head->next;
	std::stack<int> ist;
	while (node) {
		ist.push(node->data);
		node = node->next;
	}
	while (!ist.empty()) {
		std::cout << ist.top() << " ";
		ist.pop();
	}
	std::cout << std::endl;
}

void destory(Node *head) {
	Node *p = head;
	while (head) {
		p = head;
		head = head->next;
		delete p;
		p = NULL;
	}
}

int main(int, char**) {
	Node *head = new Node();
	Node *p1 = new Node();	p1->data = 1;
	Node *p2 = new Node();	p2->data = 2;
	Node *p3 = new Node();	p3->data = 3;
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = NULL;
	loop(head);
	rloop(head);

	reverse(head);
	loop(head);
	destory(head);
	exit(EXIT_SUCCESS);
}
