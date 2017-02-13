/**
* @file main.cpp
* @Synopsis  Remove Duplicates from Sorted List (在一个排序号的数组里面删除重复的元素).
		Given a sorted linked list, delete all duplicates such that each element appear only once.
		For example,
		Given 1->1->2, return 1->2.
		Given 1->1->2->3->3, return 1->2->3.
* @author Saki Shum, sakishum1118@gmail.com
* @version 0.0.1
* @date 2015-08-27
*/

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

#define SafeDelete(x) do { if (NULL != x) { delete x; x = NULL; } } while(0);

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
	~ListNode(void) {
		std::cout << "destructor, val = " << val << std::endl; 
	}
};


class Solution {
public:
    static ListNode* deleteDuplicates(ListNode* head) {
       if (NULL == head) {
			return head;
		} 
		
		int val = head->val;
		ListNode *ptr = head;
		while (ptr && ptr->next) {
			if (ptr->next->val != val) {
				val = ptr->next->val;
				ptr = ptr->next;
			} else {
				ListNode *next = ptr->next->next;
				// delete repeated node;
				SafeDelete(ptr->next)
				ptr->next = next;
			}
		}
		return head;
    }
};

auto main(int, char**) -> int32_t {
	ListNode *node1 = new ListNode(1); 
	ListNode *node2 = new ListNode(1); 
	ListNode *node3 = new ListNode(2); 
	node1->next = node2;
	node2->next = node3;
	Solution::deleteDuplicates(node1);
	ListNode *ptr = node1;
	while (ptr != NULL) {
		std::cout << ptr->val << std::endl;
		ptr = ptr->next;
	}
	exit(EXIT_SUCCESS);	
}
