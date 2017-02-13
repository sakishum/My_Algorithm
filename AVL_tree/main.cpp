#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>

template<typename T>
class TreeNode {
public:
	TreeNode(void) : lson_(NULL), rson_(NULL), freq_(0), high_(0) { }
	T data_;
	TreeNode *lson_;
	TreeNode *rson_;
	uint32_t freq_;
	int32_t high_;
};

template<typename T>
class AVLTree {
public:
	AVLTree(void) : root_(NULL) { }
	void insert(T x);
	TreeNode<T> *find(T x);
	void deleteNode(T x);
	void traversal(void);
	
private:
	TreeNode<T> *root_;
	void insertpri(TreeNode<T>* &node, T x);
	TreeNode<T> *findpri(TreeNode<T> *node, T x);
	void insubtree(TreeNode<T> *node);
	void deleteNodepri(TreeNode<T>* &node, T x);
	int32_t high(TreeNode<T> *node);
	void singRotateLeft(TreeNode<T>* &k2);
	void singRotateRight(TreeNode<T>* &k2);
	void doubleRotateLR(TreeNode<T>* &k3);
	void doubleRotateRL(TreeNode<T>* &k3);
	int32_t max(int32_t cmpa, int32_t cmpb);
};

template<typename T>
int32_t AVLTree<T>::high(TreeNode<T> *node) {
	if (node != NULL) {
		return node->high_;
	}
	return -1;
 }

template<typename T>
int32_t AVLTree<T>::max(int32_t cmpa, int32_t cmpb) {
	return cmpa>cmpb?cmpa:cmpb;
}

template<typename T>
void AVLTree<T>::singRotateLeft(TreeNode<T>* &k2) {
	TreeNode<T> *k1;
	k1 = k2->lson_;
	k2->lson_ = k1->rson_;
	k1->rson_ = k2;

	k2->high_ = max(high(k2->lson_), high(k2->rson_)) + 1;
	k1->high_ = max(high(k1->lson_), k2->high_) + 1;
}

template<typename T>
void AVLTree<T>::singRotateRight(TreeNode<T>* &k2) {
	TreeNode<T> *k1;	
	k1 = k2->rson_;
	k2->rson_ = k1->lson_;
	k1->lson_ = k2;

	k2->high_ = max(high(k2->lson_), high(k2->rson_)) + 1;
	k1->high_ = max(high(k1->rson_), k2->high_) + 1;
}

template<typename T>
void AVLTree<T>::doubleRotateLR(TreeNode<T>* &k3) {
	singRotateRight(k3->kson_);
	singRotateLeft(k3);
}

template<typename T>
void AVLTree<T>::doubleRotateRL(TreeNode<T>* &k3) {
	singRotateLeft(k3->rson_);
	singRotateRight(k3);
}

int32_t main(int32_t, char**) {
	exit(EXIT_SUCCESS);
}

