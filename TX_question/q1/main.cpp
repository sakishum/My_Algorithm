/**
 * @file main.cpp
 * @Synopsis  将一个4字节的整数的二进制表示中的001替换为011，输出替换后的整数
 * e.g.
 *    1 0 1 0 0 1 1 0 1 0
 * (1)              1 1 1  &操作结果010不为1，则111左移1位；
 * (2)            1 1 1    &操作结果101不为1，则111左移1位；
 * (3)          1 1 1      &操作结果110不为1，则111左移1位；
 * (4)        1 1 1        &操作结果011不为1，则111左移1位；
 * (5)      1 1 1          &操作结果001为1，  则111左移3位；
 * (6)1 1 1				   &操作结果101不为1，结束。
 *		相关算法： KMP，KMP 算法是拿来处理字符串匹配的。 
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-01-22
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>

/**
 * @Synopsis  Replace001by011 
 *		we cannot make right shift because of signed number
 * @Param nValue
 *
 * @Returns	Result   
 */
int Replace001by011(unsigned int nValue) {
	unsigned int ifilter = 7;	/// 111
	unsigned int shift = 0;		
	unsigned int wholeshift=0;   
	/// 4BYTE = 32 BIT
	/// the filter can right shift 29 at most.
	while (wholeshift <= (sizeof(int)*8 - 3)) {
		if ((nValue&(ifilter<<wholeshift)) == static_cast<unsigned int>(1<<wholeshift)) {
			/// do replace 
			nValue |= (1<<(wholeshift+1));	/// replace 001 with 011
			shift = 3;
		} else {
			shift = 1;
		}
		wholeshift += shift;
	} 
	return nValue;
}

int rpc011by010(unsigned int value) {
	unsigned int ifilter = 7;	// 111
	unsigned int shift = 0;
	unsigned wholeshift = 0;
	while (wholeshift <= (sizeof(int)*8 - 3)) {
		if ((value & (ifilter<<wholeshift)) == static_cast<unsigned int>(3<<wholeshift)) {
			value |= (1 << (wholeshift+1));
			shift += 3;
		} else {
			shift += 1;
		}
		wholeshift += shift;
	}
	return value;
}

uint32_t replace(uint32_t num) {
	uint32_t filter = 7;	// 111
	uint32_t shift = 0;
	uint32_t wholeshift = 0;
	// 4Byte = 32bit
	// 可以移动 29次 (32 - 3)
	while (wholeshift <= sizeof(uint32_t)*8 - 3) {
		//std::cout << "1: " << (num&(filter<<wholeshift)) << "2: " << (1<<wholeshift) << std::endl;
		if ((num&(filter<<wholeshift)) == static_cast<uint32_t>(1<<wholeshift)) {
			// 替换
			num |= (1<<(wholeshift+1));
			shift = 3;
		} else {
			shift = 1;
		}
		wholeshift += shift;
	}
	//printf("ret = %X\n", num);
	return num;
}

uint32_t replace0001by010(uint32_t num) {
	unsigned filter = 7;
	uint32_t shift = 0;
	uint32_t wholeshift = 0;
	while (wholeshift <= sizeof(uint32_t)*8 -1) {
		if ((num&(filter << wholeshift)) == static_cast<uint32_t>(1<<wholeshift)) {
			printf("%d, %d\n", num, (2<<(wholeshift)));
			num ^= (3<<(wholeshift));
			shift = 3;
		} else {
			shift = 1;
		}
		wholeshift += shift;
	}
	return num;
}

int main(int, char**) {
	printf("Before: 9 -> 1001, After: 11011 -> %d\n", Replace001by011(9));
	printf("Before: 9 -> 1001, After: 11011 -> %d\n", replace(9));
	//printf("Before: 9 -> 1001, After: %x\n", replace0001by010(9));
	return EXIT_SUCCESS;
}

