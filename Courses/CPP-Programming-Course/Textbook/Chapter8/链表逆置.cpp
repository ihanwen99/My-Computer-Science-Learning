#include<iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
};

ListNode* reverseList(ListNode* head) {
	ListNode* pre = NULL, * curr = head;
	while (curr != NULL) {
		ListNode* tmp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = tmp;
	}
	return pre;
}