#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Btree {
public:
	Btree(void) : root_(NULL) { }
	~Btree(void) { destoryTree(); }
	void destoryTree(void);
	void insert(int key);
	void proOrderR(int (*vist)(const TreeNode*));
	void inOrderR(int (*vist)(const TreeNode*));
	void postOrderR(int (*vist)(const TreeNode*));
	void levelOrderR(int (*vist)(const TreeNode*));
	TreeNode *search(int key);
	TreeNode *invertTree(void);

private:
	void insert(int val, TreeNode *leaf);
	void destoryTree(TreeNode *root);
	void preOrderR(const TreeNode *node, int (*vist)(const TreeNode*)) const;
	void inOrderR(const TreeNode *node, int (*vist)(const TreeNode*)) const;
	void postOrderR(const TreeNode *node, int (*vist)(const TreeNode*)) const;
	void levelOrderR(const TreeNode *node, int (*vist)(const TreeNode*)) const;
	TreeNode *search(int key, TreeNode *leaf) const;

private:
	TreeNode *root_;
};

void Btree::insert(int key){
	if (NULL != root_) {
		insert(key, root_);
	} else {
		root_ = new TreeNode(key);
	}
}

void Btree::insert(int key, TreeNode *node) {
	if (key < node->val) {
		if (node->left != NULL) {
			insert(key, node->left);
		} else {
			node->left = new TreeNode(key);
		}
	} else if (key >= node->val) {
		if (node->right != NULL) {
			insert(key, node->right);
		} else {
			node->right = new TreeNode(key);
		}
	}
}

void Btree::destoryTree(void) {
	destoryTree(root_);
}

void Btree::destoryTree(TreeNode *node) {
	if (NULL != node) {
		destoryTree(node->left);
		destoryTree(node->right);
		delete node;
		node = NULL;
	}
}
void Btree::proOrderR(int (*vist)(const TreeNode*)) {
	if (NULL == root_) {
		return;
	}
	preOrderR(root_, vist);
}
void Btree::inOrderR(int (*vist)(const TreeNode*)) {
	if (NULL == root_) {
		return;
	}
	inOrderR(root_, vist);
}
void Btree::postOrderR(int (*vist)(const TreeNode*)) {
	if (NULL == root_) {
		return;
	}
	postOrderR(root_, vist);
}
void Btree::levelOrderR(int (*vist)(const TreeNode*)) {
	if (NULL == root_) {
		return;
	}
	levelOrderR(root_, vist);
}
void Btree::preOrderR(const TreeNode *node, int (*vist)(const TreeNode*)) const {
	if (NULL == node) {
		return;
	}
	printf("Enter!\n");
	vist(node);
	preOrderR(node->left, vist);
	preOrderR(node->right, vist);
}
void Btree::inOrderR(const TreeNode *node, int (*vist)(const TreeNode*)) const {
	if (NULL == node) {
		return;
	}
	inOrderR(node->left, vist);
	vist(node);
	inOrderR(node->right, vist);
}
void Btree::postOrderR(const TreeNode *node, int (*vist)(const TreeNode*)) const {
	if (NULL == node) {
		return;
	}
	postOrderR(node->left, vist);
	postOrderR(node->right, vist);
	vist(node);
}
void Btree::levelOrderR(const TreeNode *node, int (*vist)(const TreeNode*)) const {
	if (NULL == node) {
		return;
	}
	const TreeNode *ptr = node;
	std::queue<const TreeNode*> queue;
	if (NULL != ptr) {
		queue.push(ptr);
	}
	while (!queue.empty()) {
		ptr = queue.front();
		queue.pop();
		vist(ptr);
		if (ptr->left != NULL) {
			queue.push(ptr->left);
			queue.push(ptr->right);
		}
	}
}

TreeNode *Btree::invertTree(void) {
	if (NULL == root_) {
		return root_;
	}	
	std::stack<TreeNode*> stack;
	stack.push(root_);
	while (!stack.empty()) {
		TreeNode *ptr = stack.top();
		stack.pop();
		std::swap(ptr->left, ptr->right);
		if (ptr->left) {
			stack.push(ptr->left);
		}
		if (ptr->right) {
			stack.push(ptr->right);
		}
	}
	return root_;
}

TreeNode *Btree::search(int key) {
	return search(key, root_);
}

TreeNode *Btree::search(int key, TreeNode *node) const {
	if (NULL != node) {
		if (key == node->val) {
			return node;
		}

		if (key < node->val) {
			return search(key, node->left);
		} else {
			return search(key, node->right);
		}
	} else {
		return NULL;
	}
}

typedef int32_t (*FUNC_VIST)(const TreeNode*);

int vist(const TreeNode *node) {
	if (NULL != node) {
		std::cout << node->val << "\t";
		return node->val;
	}
	return 0;
}

int main(int, char**) {
	Btree btree;
	printf("%d\n", 0);
	btree.insert(4);
	printf("%d\n", -1);
	btree.insert(2);
	btree.insert(7);
	btree.insert(1);
	btree.insert(3);
	btree.insert(6);
	btree.insert(9);
	printf("%d\n", 1);
	// 查找 7
	TreeNode *node = btree.search(7);
	if (node != nullptr) {
		std::cout << "btree search 7 val :" << node->val << std::endl; 
	}
	printf("%d\n", 2);
	FUNC_VIST pfunc = vist;
	printf("\n 先序:\n");
	btree.proOrderR(pfunc);
	printf("\n 中序:\n");
	btree.inOrderR(pfunc);
	printf("\n 后序:\n");
	btree.postOrderR(pfunc);
	printf("\n 层次:\n");
	btree.levelOrderR(pfunc);
	// invert the btree
	btree.invertTree();
	std::cout << "invert the tree." << std::endl;
	std::cout << std::string(30, '-') << std::endl;
	exit(EXIT_SUCCESS);
}
