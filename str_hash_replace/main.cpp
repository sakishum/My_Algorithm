#include <cstdlib>
#include <iostream>
#include <cstring>

#define NUM 52
#define LEN 100

int hashChar[NUM];

// 问点： 字符串是否均为大写/小写
// 排除非字符，全部字符转化为小写字母，且换算成数字: a => 0, b => 1
int hash(char c) {
	if (!isalpha(c)) return -1;
	if (islower(c)) return c - 'a';
	return c - 'A' + 26;
}

void initialHash(char *a) {
	int pos = 0;
	for (int i = 0; a[i]; ++i) {
		pos = hash(a[i]);
		if (pos == -1) {
			perror("B contains illegal charaters\n");
		} else {
			std::cout << "pos: " << pos << std::endl;
			hashChar[pos] = 1;
		}
	}
}

void delSameStr(char *a) {
	int i = 0;
	int pos = 0;
	while (a[i]) {
		pos = hash(a[i]);
		std::cout << "a[i]: " << a[i] << ", pos: " << pos << std::endl;
		if (hashChar[pos] == 1) {
			for (int j = i; a[j]; ++j) {
				a[j] = a[j+1];
			}
		} else {
			++i;
		}
	}
}

int main(void) {
	char a[] = "hello worls";
	char b[] = "er";
	// 从字符串 a 中剔除字符串 b 中的字符。
	// 空间复杂度要求为 O(1)。时间复杂度越优越好。
	
	// Hash查找因为其O(1)的查找性能而著称，被对查找性能要求高的应用所广泛采用。
	// (1) 创建一个定长的线性Hash表，一般可以初始化时指定length;
	// (2) 设计Hash函数，将关键字key散射到Hash表中。其中hash函数设计是最为关键的，均匀分布、冲突概率小全在它；
	// (3) 通常采用拉链方法来解决hash冲突问题，即散射到同一个hash表项的关键字，以链表形式来表示(也称为桶backet);
	// (4) 给定关键字key，就可以在O(1) + O(m)的时间复杂度内定位到目标。其中，m为拉链长度，即桶深。
	
	// Hash应用中，字符串是最为常见的关键字，应用非常普通，现在的程序设计语言中基本上都提供了字符串hash表的支持。
	// 思路: 构造一个哈希表，将字符串B 映射到此表中，
	// 当要对A进行处理时，只需要用哈希函数进行查找即可。
	// 此题目是想要实现块数查找，Hash 是个不错的选择，
	// 这个查找的效率为 O(1)，由于 Hash 表长度固定，所以
	// 空间复杂度是O(1)，满足题意。
	initialHash(b);
	delSameStr(a);
	std::cout << "After operation, a: " << a << std::endl;
	return EXIT_SUCCESS;
}
