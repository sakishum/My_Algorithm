#include <cstdlib>
#include <iostream>
#include <cstring>

// 互换
void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

// 翻转
void reverseString(char a[], int from, int to) {
	while (from < to) {
		char t = a[from];
		a[from++] = a[to];
		a[to--] = t;
	}
}

// a 是待调整的堆数组, i 是待调整的数组元素的位置, len 是数组的长度
// 功能: 根据数组 a 构建大根堆
void fixDown(char a[], int i, int len) {
	// 左节点位置 = 2 * (父节点位置) + 1
	int lchild = 2 * i + 1;
	// 右节点位置 = 2 * (父节点位置) + 2
	int rchild = 2 * i + 2;
	// 节点中较小的节点
	int minIndex = 0;
	if (lchild < len && a[lchild] < a[i]) {
		std::cout << "i: " << i <<", lchild: " << lchild << ", a[lchild]: " << a[lchild] << std::endl;
		minIndex = lchild;
	} else {
		minIndex = i;
	}

	if (rchild < len && a[rchild] < a[minIndex]) {
		std::cout << "i: " << i << ", rchild: " << rchild << ", a[rchild]: " << a[rchild] <<  std::endl;
		minIndex = rchild;
	}

	if (minIndex != i) {
		// 如果较小的子节点小于父节点那么就把较小的节点往上移动，替换他的父节点
		swap(a + i, a + minIndex);
		std::cout << "minIndex: " << minIndex << ", i: " << i << ", swap(" << a[i] << ", " << a[minIndex] << ")" << std::endl;
		fixDown(a, minIndex, len);
	}
}

void initHeap(char a[], int len) {
	// (len - 1)/2 是最后一个非叶子节点
	for (int i = (len - 1)/2; i >= 0; --i) {
		fixDown(a, i, len - 1);
	}
	std::cout << "After init: " << a << std::endl;
}

void heapSort(char a[], int len) {
	// 调整序列的前半部分元素, 调整之后第一个元素是序列中最大的元素
	initHeap(a, len);
	// 从最后一个元素开始对序列惊醒调整，不断缩小调整的范围直到第一个元素
	for (int i = len -1; i != 0; --i) {
		// 把第一个元素和当前的最后一个元素交换,
		// 保证当前最后一个位置的元素都是现在的这个序列之中最大的
		swap(a + i, a + 0);
		// 不断缩小调整 heap 的范围, 每一次调整完毕保证第一个元素是当前序列的最大值
		fixDown(a, 0, i);
	}
}

void filterAndSort(char a[], int len) {
	heapSort(a, len);
	std::cout << "After heap sort: " << a << std::endl;

	int i = 0;
	int startIndex = 0, endIndex = -1;
	for (i = 0; i != len; ++i) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			++endIndex;
		} else {
			break;
		}
	}

	if (endIndex > startIndex) {
		reverseString(a, startIndex, endIndex);
	}

	startIndex = endIndex + 1;
	for (; i != len; ++i) {
		if (a[i] >= 'A' && a[i] <= 'Z') {
			++endIndex;
		} else {
			break;
		}
	}

	if (endIndex > startIndex) {
		reverseString(a, startIndex, endIndex);
	}

	startIndex = endIndex + 1;
	for (; i != len; ++i) {
		if (a[i] >= '0' && a[i] <= '9') {
			++endIndex;
		} else {
			break;
		}
	}

	if (endIndex > startIndex) {
		reverseString(a, startIndex, endIndex);
	}
}


int main(void) {
	char str[] = "MDEXE098FGH453a4cf9";
	//char str[] = "A1b";
	int length = strlen(str) - 1;
	std::cout << "Before sort: " << str << ", len: "<< length << std::endl;
	filterAndSort(str, length);
	std::cout << "After sort: " << str << ", len: "<< length << std::endl;
	std::cin.get();
	return EXIT_SUCCESS;
}
