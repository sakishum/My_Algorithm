#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

/*
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 *
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
 *
 * 处理链表头节点不确定的方法——引入dummy node.
 * */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};  // struct ListNode 

class Solution {
public:
	static ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr) {
			return nullptr;
		}

		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *node = dummy;
		while (node->next != nullptr && node->next->next != nullptr) {
			if (node->next->val == node->next->next->val) {
				int val_prev = node->next->val;
				while (node->next != nullptr && val_prev == node->next->val) {
					ListNode *temp = node->next;
					node->next = node->next->next;
					delete temp;
				}
			} else {
				node = node->next;
			}
		}
		return dummy->next;
	}
};  // class Solution

auto main(int, char**) -> int32_t {
	ListNode *node1 = new ListNode(1); 
	ListNode *node2 = new ListNode(1); 
	ListNode *node3 = new ListNode(1); 
	ListNode *node4 = new ListNode(2); 
	ListNode *node5 = new ListNode(3); 
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	Solution::deleteDuplicates(node1);
	ListNode *ptr = node1;
	while (ptr != nullptr) {
		std::cout << ptr->val << std::endl;
		ptr = ptr->next;
	}

	exit(EXIT_SUCCESS);
}

