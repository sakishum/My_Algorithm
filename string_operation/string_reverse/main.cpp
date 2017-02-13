/**
 * @file main.cpp
 * @Synopsis  给定一个字符串，要求把字符串前若干个字符移动到字符串尾部，
 *		如把字符串 "abcdef" 前 2 个字符'a'、'b'移动到字符串的尾部，使得
 *		原字符串变成字符串"cdefab"。请写一个函数完成此功能，要求对长度
 *		为 n 的字符串操作的时间复杂度为 O(n), 空间复杂度为 O(1)。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2015-05-24
 */

#include <cstdio>
#include <cstdlib>
#include <iostream>

// 将一个字符串分成 X 和 Y 两个部分，在每部分字符串上定义反转操作，
// 如 X^T, 即把X的所有字符串反转(如,X="abc", 那么X^T="cba"), 那么
// 就得到了以下结论:(X^TY^T)^T=YX,显然就解决了字符串的反转问题。

// 三步反转法:
void reverseString(char *s, int from, int to) {
	while (from < to) {
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
	std::cout << "loop: " << s << std::endl;
}

void leftRotateString(char *s, int n, int m) {
	m %= n;		// 若要左移动大于 n 位, 那么和 %n 是等价的。
	std::cout << "m: " << m << ", n: " << n <<std::endl;
	reverseString(s, 0, m - 1);	// 反转[0..m-1], X->X^T 
	reverseString(s, m, n - 1);	// 反转[m..n-1], Y->Y^T
	reverseString(s, 0, n - 1);	// 反转[0..n-1], (X^TY^T)^T=YX
}

int main(void) {
	char str[] = "student";
	std::cout << "str: " << str << std::endl;
	// 长度n: sizeof(str)/sizeof(str[0]) - 1
	// 反转位置m: 3
	leftRotateString(str, sizeof(str)/sizeof(str[0]) - 1, 3);
	std::cout << "str: " << str << std::endl;
	return EXIT_SUCCESS;
}
