#include<iostream>
using namespace std;

struct Node {
	int order, coeff; // 次数 和 系数
	Node* nxt; // 指向后一项的指针
};


// IN: Node* a, Node* b, polynomials represented as linked lists
// RETURN: polynomial a+b represented as a linked list
Node* add_poly(Node* a, Node* b) {
	bool exist = false;
	Node* head = new Node;
	Node* curr = head;
	while (a && b) {
		if (a->order == b->order) {
			if (a->coeff + b->coeff != 0) {
				exist = true;
				Node* tmp = new Node;
				tmp->order = a->order;
				tmp->coeff = a->coeff + b->coeff;
				curr->nxt = tmp;
				curr = curr->nxt;
			}
			a = a->nxt;
			b = b->nxt;
		}
		else {
			if (a->order > b->order) {
				if (a->coeff != 0) {
					curr->nxt = a;
					curr = curr->nxt;
				}
				a = a->nxt;
			}
			else {
				if (b->coeff != 0) {
					curr->nxt = b;
					curr = curr->nxt;
				}
				b = b->nxt;
			}
		}
	}
	while (a) {
		if (a->coeff != 0) {
			curr->nxt = a;
			curr = curr->nxt;
		}
		a = a->nxt;
	}
	while (b) {
		if (b->coeff != 0) {
			curr->nxt = b;
			curr = curr->nxt;
		}
		b = b->nxt;
	}
	curr->nxt = NULL;

	if (exist) { return head->nxt; }
	head->order = 0;
	head->coeff = 0;
	head->nxt = NULL;
	return head;

}