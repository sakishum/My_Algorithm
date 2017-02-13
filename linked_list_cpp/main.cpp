#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

class CNode {
public:
	int32_t _data;
	CNode *next;
};

class CNodeList {
public:
	CNode *head;
};

void print(CNode *head) {
	for (CNode *p = head; p != nullptr; p = p->next) {
		printf("%d\t", p->_data);
	}
	printf("\n");
}

int32_t getLength(CNode *head) {
	int32_t len = 0;
	while (head != nullptr) {
		head = head = head->next;
		++len;
	}
	return len;
}

void insertBegin(CNode *&head, int32_t val) {
	CNode *newNode = new CNode();
	newNode->_data = val;
	newNode->next = head;
	head = newNode;
}

void insertEnd(CNode *&head, int32_t val) {
	CNode *newNode = new CNode();
	newNode->_data = val;
	newNode->next = nullptr;
	if (head == nullptr) {
		head = newNode;
	} else {
		CNode *ptr = head;
		while (ptr->next != nullptr) {
			ptr = ptr->next;
			ptr->next = newNode;
		}
	}
}

void insert(CNode *&head, int32_t num) {
	CNode *p1 = head;
	CNode *p2 = nullptr;
	while (p1->_data < num && p1->next != nullptr) {
		p2 = p1;
		p1 = p1->next;
	}

	CNode *ptr = new CNode();
	ptr->_data = num;
	if (p1->_data < num) {
		p1->next = ptr;
		ptr->next = nullptr;
	} else if (p1 == head) {
		ptr->next = p1;
		head = ptr;
	} else {
		p2->next = ptr;
		ptr->next = p1;
	}
}

void remove(CNode *&head, int32_t num) {
	CNode *p1 = head;
	CNode *p2 = nullptr;
	while (p1->_data != num && p1->next != nullptr) {
		p2 = p1;
		p1 = p1->next;
	}

	if (p1->_data != num) {
		printf("%d Not Found\n", num);
	} else {
		if (p1 == head) {
			head = p1->next;
			delete p1;
		} else {
			p2->next = p1->next;
			delete p1;
		}
	}
}
























auto main(int, char**) -> int32_t {
	exit(EXIT_SUCCESS);
}
