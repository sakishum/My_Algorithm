#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define Max( a , b ) ( (a) > (b) ? (a) : (b) )

typedef int ElementType;
struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

struct AvlNode {
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int     Height;
};

static int Height( Position P ) {
	if ( P == NULL )
		return -1;
	else
		return P->Height;
}

/*This function can be called only if k2 has a left child*/
/*Perform a rotate between a node (k2) and its left child*/
/*Update heights , then return new root*/
static Position SingleRotateWithLeft( Position k2 ) {
	Position k1;

	k1 = k2->Left;
	k2->Left = k1->Right;
	k1->Right = k2;

	k2->Height = Max( Height( k2->Left) , Height( k2->Right ) ) + 1;
	k1->Height = Max( Height( k1->Left) , k2->Height ) + 1;

	return k1; //new root
}

static Position SingleRotateWithRight( Position k2 ) {
	Position k1;

	k1 = k2->Right;
	k2->Right = k1->Left;
	k1->Left = k2;

	k2->Height = Max( Height( k2->Left ) , Height( k2->Right ) ) + 1;
	k1->Height = Max( Height( k1->Right ) , k2->Height ) + 1;

	return k1;
}

/*This function can be called only if k3 has a left*/
/*child and k3's left child has a right child*/
/*Do the left-right double rotation*/
/*Update heights,then return new root*/
static Position DoubleRotateWithLeft( Position k3 ) {
	/*Rotate between k1 and k2*/
	k3->Left = SingleRotateWithRight( k3->Left );

	/*Rotate between k3 and k2*/
	return SingleRotateWithLeft( k3 );
}

static Position DoubleRotateWithRight( Position k3 ) {
	/*Rotate between k1 and k2*/
	k3->Right = SingleRotateWithLeft( k3->Right );

	/*Rotate between k3 and k2*/
	return SingleRotateWithRight( k3 );
}


AvlTree Insert( ElementType X , AvlTree T ) {
	if ( T == NULL ) {
		/*Create and return a one-node tree */
		T = ( AvlTree )malloc (sizeof( struct AvlNode ));
		if ( T == NULL ) {
			printf("Out of space!!!\n");
		} else {
			T->Element = X ; T->Height = 0 ; //The height of the leef is 0 !!! Different from the normal tree!
			T->Left = T->Right = NULL;
		}
	} else if ( X < T->Element ) {
			T->Left = Insert ( X , T->Left );
			if( Height(T->Left) - Height( T->Right) == 2 ) {
				if ( X < T->Left->Element ) {
					T = SingleRotateWithLeft( T );
				} else {
					T = DoubleRotateWithLeft( T );
				}
			}
	} else if ( X > T->Element ) {
			T->Right = Insert( X , T->Right );
			if( Height(T->Right) - Height(T->Left) == 2 ) {
				if ( X > T->Right->Element ) {
					T = SingleRotateWithRight( T );
				} else {
					T = DoubleRotateWithRight( T );
				}
			}
	}
	/* Else X is in the tree already; we'll do nothing!*/

	T->Height = Max( Height( T->Left) , Height( T->Right ) ) + 1;
	return T;
}

AvlTree Init_AvlTree(AvlTree T, ElementType *ElementArry,int length) {
	int i;
	//逐个插入查找二叉树中
	T->Element = ElementArry[0]; //在初始化的过程中直接把第一个点作为根节点。

	for(i=1;i<length;i++)
		Insert(ElementArry[i],T);

	return T;
}

int main(int, char const **) {
	// 初始化指针
	AvlTree T = ( AvlTree )malloc(sizeof( struct AvlNode ));
	T->Left = NULL;
	T->Right = NULL;
	//Position Temp;
	ElementType ElementArry[11]= {15,6,18,3,7,17,20,2,4,13,9};
	/*Initialize the AvlTree*/
	T = Init_AvlTree( T , ElementArry , 11 );

	printf("%d\n", T->Left->Right->Left->Element );

	return 0;
}

