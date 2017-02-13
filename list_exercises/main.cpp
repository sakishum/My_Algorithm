/**
 * @file main.cpp
 * @Synopsis  简单链表。
 * @author Saki Shum, sakishum1118@gmail.com
 * @version 0.0.1
 * @date 2014-10-15
 */

#include <cstdio>
#include <cstdlib>
#include <cstdint>

class CListNode {
public:
	CListNode(int32_t data) {
		this->m_data = data;
		this->m_pNext = NULL;
	}

	int32_t getData(void) const {
		return this->m_data;
	}

	CListNode *getNext(void) {
		return this->m_pNext;
	}

	void setData(int32_t data) {
		this->m_data = data;
	}

	void setNext(CListNode *pNext) {
		this->m_pNext = pNext;
	}

private:
	int32_t m_data;			// 节点数据
	CListNode *m_pNext;		// 指向下个节点的指针
};  // class CListNode

class CList {
public:
	// 构造链表，需要提供链表头结点
	CList(CListNode *pHead) {
		this->m_pHead = pHead;
	}

	~CList(void) {
		CListNode *pCurr = m_pHead;
		while (pCurr) {
			CListNode *pNext = pCurr->getNext();
			delete pCurr;
			pCurr = pNext;
		}
	}

	// 添加节点
	CList *add(CListNode *pNode) {
		CListNode *pCurr = m_pHead;
		while (pCurr->getNext()) {
			pCurr = pCurr->getNext();
		}
		pCurr->setNext(pNode);
		return this;
	}

	// 翻转
	CList *reverse(void) {
		CListNode *pCurr = m_pHead;
		CListNode *pNext = pCurr->getNext();
		m_pHead->setNext(NULL);
		while (pNext) {
			CListNode *pTmp = pNext->getNext();
			pNext->setNext(pCurr);
			pCurr = pNext;
			pNext = pTmp;
		}
		m_pHead = pCurr;
		return this;
	}

	// 排序
	CList *sort(void) {
		CListNode *pOldHead = m_pHead->getNext();
		CListNode *pNewHead = m_pHead;
		pNewHead->setNext(NULL);
		while (pOldHead) {
			CListNode *pNewPre = NULL,
					  *pNewCurr = pNewHead,
					  *pTmp = pOldHead->getNext();
			// 循环检测相邻的两个节点替换，根据比较结果互相替换位置
			for (; pNewCurr && pNewCurr->getData() <= pOldHead->getData(); 
					pNewPre = pNewCurr, pNewCurr = pNewCurr->getNext()); 
			if (pNewCurr == pNewHead) {
				pOldHead->setNext(pNewHead);
			} else {
				pNewPre->setNext(pOldHead);
				pOldHead->setNext(pNewCurr);
			}
			pOldHead = pTmp;
			//this->print();
		}
		m_pHead = pNewHead;
		return this;
	}

	// 打印
	CList *print(void) {
		CListNode *pCurr = m_pHead;
		while (pCurr) {
			printf("%d -> ", pCurr->getData());
			pCurr = pCurr->getNext();
		}
		printf("Null\n");
		return this;
	} 

private:
	CListNode *m_pHead;		// 链表表头节点
};  // class CList

int main(void) {
	CList *ilist = new CList(new CListNode(0));
	ilist->add(new CListNode(2))
		->add(new CListNode(3))
		->add(new CListNode(1))
		->add(new CListNode(5))
		->add(new CListNode(4))
		->add(new CListNode(6));

	ilist->print();
	ilist->sort();
	ilist->print();
	ilist->reverse();
	ilist->print();
	delete ilist;
	return EXIT_SUCCESS;
}
