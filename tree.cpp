//https://www.youtube.com/watch?v=qH6yxkw0u78&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=25
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;
typedef struct BstNode
{
	int data;
	struct BstNode* left;
	struct BstNode* right;
}BstNode;

BstNode* rootptr=NULL; 

void insert(BstNode* _tmpp_root,int data)
{
	
}

BstNode* createNewNode(int _data)
{
   BstNode* newNode=(BstNode*)malloc(sizeof(BstNode));
   (*newNode).data=_data;
   (*newNode).left=NULL;
   (*newNode).right=NULL;	
   return newMode;
}

int main()
{
	
}

/*
Lecture 25->Data structures: Introduction to Trees (1:51)


-Cost of operaton->array list for binary search will be fast (1:35) 
-Tree is used for heirachy data (1:51) such as organizatoin's structure (2:54)
-Termalnology
	-Tree refers to Nodes linke to gether (3:18) to simulate a hierachy.
	-Tree is non-linear data structure (3:21)It is a hierachy data
	-Top is called root of the tree (3:31)
	-a node contains a reference to the next node:Children (3:56)
	-Node 2 and Node 3 are called Childeren of node 1(5:04)
	-Node 1 is called as parent node of node 2 and node 3 (5:08)]
	-Node 4, NOde 5 and Node 6 are children of node 2 (5:27)
	-Dhildren of same parent are called sibling (5:37)
		-Node 2 and 3 are sibling and node 7,8 are sibling (5:45)
		-root will be an only node without a parent (5:59)
	-Any tree DOESN'T have a child is called a leaf node (6:11)
	-All node with at least one child is a.k.a as internal node(6:24)
	-

*/
