#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>

template<typename T>
class TreeNode {
public:
	TreeNode(void) : lson(NULL), rson(NULL), freq(1), high(0) {}
	T data;			// 值
	int32_t high;	// 以此节点为根的树高度
	uint32_t freq;	// 频率
	TreeNode *lson;	// 指向左节点的指针
	TreeNode *rson;	// 指向右节点的指针
};

// AVL 树类的属性与方法
template<typename T>
class AVLTree {
public:

private:
	TreeNode<T> *root;
	void insertPri(TreeNode<T> *&node, T x);
	TreeNode<T> *findPri(TreeNode<T> *node, T x);
	void insubtree(TreeNode<T> *node);
	void deletePri(TreeNode<T> *&node, T x);
	int32_t heigh(TreeNode<T> *node);
};

int main(int, char**) {
	exit(EXIT_SUCCESS);
}
