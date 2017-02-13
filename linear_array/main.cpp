/**
 * @file main.cpp
 * @Synopsis  线性表是数据结构中的概念。数组中除第一个元素外，
 *		其他元素有且仅有一个直接前驱，第一个元素没有前驱；除最
 *		后一个元素外，其他元素有且仅有一个直接后继，最后一个元
 *		素无后继。这样的特性称为线性关系。所议称数组元素在一个
 *		线性表中。线性表实际包括顺序表（数组）和链表。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-09-29
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>

template <typename T, int size>
class CSeqlist {
public:
	CSeqlist(void) : m_maxsize(size), m_last(-1) {
	}

	int length(void) {
		return m_last + 1;
	}

	int find(T &val) const;
	bool isIn(T &val);
	bool insert(T &val, int pos);
	bool remove(T &val);
	int next(T &val);
	int prior(T &val);
	bool isEmpty(void) {
		return (-1 == m_last);
	}
	bool isFull(void) {
		return ((m_maxsize - 1) == m_last);
	}
	T get(int pos) {
		return (pos < 0 || pos > m_last ? NULL : m_slist[pos]); 
	}
	T& operator[](int i);

private:
	T m_slist[size];
	int m_maxsize;
	int m_last;
};

template <typename T, int size>
int CSeqlist<T, size>::find(T &val) const {
	int i = 0;
	while (i <= m_last && m_slist[i] != val) {
		++i;
	}
	if (i > m_last) {
		return -1;
	} else {
		return i;
	}
}

template <typename T, int size>
bool CSeqlist<T, size>::isIn(T &val) {
	int i = 0;
	bool found = false;
	while (i <= m_last && m_slist[i] != val) {
		if (m_slist[i] != val) {
			++i;
		} else {
			found = true;
		}
	}
	return found;
}

template <typename T, int size>
bool CSeqlist<T, size>::insert(T &val, int pos) {
	bool ret = false;
	if (pos  < 0 || pos  > m_last + 1 || m_last == m_maxsize -1) {
		return ret;
	} else {
		++m_last;
		for (int i = m_last; i > pos; --i) {
			m_slist[i] = m_slist[i + 1];
		}
		m_slist[pos] = val;
		return true;
	}
}

template <typename T, int size>
bool CSeqlist<T, size>::remove(T &val) {
	bool ret = false;
	int i = find(val), j;
	if (i >= 0) {
		--m_last;
		for (j = i; j <= m_last; ++j) {
			m_slist[j] = m_slist[j+1];
		}
		ret = true;
	}
	return ret;
}

template <typename T, int size>
int CSeqlist<T, size>::next(T &val) {
	int i = find(val);
	if (i >= 0 && i < m_last) {
		return i+1;
	} else {
		return -1;
	}
}

template <typename T, int size>
int CSeqlist<T, size>::prior(T &val) {
	int i = find(val);
	if (i >= 0 && i < m_last) {
		return i - 1;
	} else {
		return -1;
	}
}

template <typename T, int size>
T &CSeqlist<T, size>::operator[](int i) {
	if (i > (m_last + 1) || i < 0 || i >= m_maxsize) {
		std::cout << "out of border." << std::endl;
		exit(1);
	}
	if (i > m_last) {
		++m_last;
	}
	return m_slist[i];
}

// 注意：
// 在ANSI C中，这种写法是错误的，因为数组的大小应该是个常量，
// 而const int n,n只是一个变量（常量 != 不可变的变量，但在标
// 准C++中，这样定义的是一个常量，这种写法是对的），实际上，
// 根据编译过程及内存分配来看，这种用法本来就应该是合理的，
// 只是 ANSI C对数组的规定限制了它。
const int MAXLENGTH = 10;

int main(void) {
	CSeqlist<int, 100> iseqlist;
	int a[MAXLENGTH] = {2,3,5,7,11,13,17,19,23,29};
	for (int j = 0; j < 10; ++j) {
		if (!iseqlist.insert(a[j], j)) {
			std::cout << "Couldn\'t insert." << std::endl;
			break;
		}
	}

	int len  = iseqlist.length();
	for (int i = 0; i != len; ++i) {
		std::cout << iseqlist[i] << std::endl;
	}

	return EXIT_SUCCESS;
}

