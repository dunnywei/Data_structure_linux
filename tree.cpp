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
	-Parent of Parent is called grand parent (6:33)
	-Link is not bidirectional (6:48)
	-When wea are walking the tree, we can only walk in one direction only (6:57)
	-It we can go from Node A to Node B, A is called ancestor of B (7:04). B is the descendent of A
	-Node 1, NOde 2, and Node 5 are all ancesotr of node 10. (7:14)
	-Node 10 is the descendent of Node 1, NOde 2, and Node 5 (7:17)
	-Does node 6 and node 7 are sibling? Sibling must have same parent (7:50). However Node 6 and Node 7
	have same grand parent so they are called COUSINs (7:57)
	-Node 3 is Uncle of node 6 since  Node 2 is the sibling of node 3(8:10)(8:13)
-Le's talk about the property of tree (8:23)
	-Tree can be recursively data structure (8:29)
	-It consits of a root and sub trees (8:37)
	-Roots contains the link to all group in the subtree (8:44)
	-eg, T1,T2 and T3 are sub trees (8:49)
	-In aour case, we have root node, left sub tree and right sub tree (9:00)
	-Recursion is reducing sth in a self similar manner (9:20)
	-Recursive implementation will occur everywhere in the tree data strucutre
->(9:29) Next peroperty is we N nodes, we will have N-1 edges (Links) (9:35)
	-Each arrow in this figure is a.k.a as a link or an edge (9:37)
	-In node 2, we only have 1 incoming link (9:52)
	-
*/
