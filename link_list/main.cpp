#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>

class IntALLNode {
public:
	IntALLNode(void) : next(NULL) {	}
	IntALLNode(int ell, IntALLNode *ptr = NULL) : info(ell), next(ptr) { }
	int info;
	IntALLNode *next;
};

class IntALList {
public:
	IntALList(void) : head(NULL), tail(NULL) { }
	~IntALList(void);
	int isEmpty(void) {
		return head == NULL;
	}
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(void);
	int deleteFromTail(void);
	void deleteNode(int);
	bool isInList(int) const;
	void printList(void);
	void reversal(void);
private:
	IntALLNode *head;
	IntALLNode *tail;
};

IntALList::~IntALList(void) {
	for (IntALLNode *p; !isEmpty(); ) {
		p = head->next;
		delete head;
		head = p;
	}
}

void IntALList::reversal(void) {
	if (isEmpty()) {
		return;
	}
	std::cout << "Enter" << std::endl;
	IntALLNode *current, *pnext, *prev;
    if (head == NULL || head->next == NULL)
        return ;
    current = head->next;  /* p1指向链表头节点的下一个节点 */
    pnext = current->next;
    current->next = NULL;
    while (pnext) {
        prev = pnext->next;
        pnext->next = current;
        current = pnext;
        pnext = prev;
        printf("交换后：current = %d,next = %d \n", current->info, current->next->info);
    }
    head->next = current;  /* 将链表头节点指向p1 */
}

void IntALList::addToHead(int el) {
	head = new IntALLNode(el, head);
	if (tail == NULL) {
		tail = head;
	}
}

void IntALList::addToTail(int el) {
	if (tail != NULL) {
		tail->next  = new IntALLNode(el);
		tail = tail->next;
	} else {
		head = tail = new IntALLNode(el);
	}
}

int IntALList::deleteFromHead(void) {
	int el = head->info;
	IntALLNode *tmp = head;
	if (head == tail) {
		head = tail = NULL;
	} else {
		head = head->next;
	}
	delete tmp;
	return el;
}

int IntALList::deleteFromTail(void) {
	int el = tail->info;
	if (head == tail) {
		delete head;
		head = tail = NULL;
	} else {
		IntALLNode *tmp;
		for (tmp = head; tmp->next != tail; tmp = tmp->next);
		delete tail;
		tail = tmp;
		tail->next = NULL;

	}
	return el;
}

// O(n)
void IntALList::deleteNode(int el) {
	if (head != NULL) {
		if (head == tail && el == head->info) {
			delete head;
			head = tail = NULL;
		} else if (el == head->info) {
			IntALLNode *tmp = head;
			head = head->next;
			delete tmp;
		} else {
			IntALLNode *pred, *tmp;
			for (pred = head, tmp = head->next;
					tmp != NULL && !(tmp->info == el);
					pred = pred->next, tmp = tmp->next);
			if (tmp != NULL) {
				pred->next = tmp->next;
				if (tmp == tail) {
					tail = pred;
				}
				delete tmp;
			}
		}
	}
}

bool IntALList::isInList(int el) const {
	IntALLNode *tmp;
	for (tmp = head; tmp != NULL && !(tmp->info == el); tmp = tmp->next);
	return tmp != NULL;
}

void IntALList::printList(void) {
	if (head != NULL) {
		for (IntALLNode *p = head; p != NULL; p = p->next) {
			std::cout << "info : " << p->info << " ";
		}
		std::cout << std::endl;
	}
}

int main(void) {
	//int d = rand()%0;	// warning: division by zero [-Wdiv-by-zero]
	//std::cout << d << std::endl;
	IntALList llist;
	llist.addToHead(12);
	llist.addToTail(34);
	llist.addToHead(33);
	llist.addToTail(24);
	// head(33) -> 12 -> 24 ->  tail(34) 
	llist.printList();
	llist.reversal();
	llist.printList();

	if (llist.isInList(34)) {
		std::cout << 34 << " In List" << std::endl;
	}
	std::cin.get();
	return EXIT_SUCCESS;
}
