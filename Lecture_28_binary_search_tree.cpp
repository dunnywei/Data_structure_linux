//https://www.youtube.com/watch?v=qH6yxkw0u78&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=28
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

//BstNode* rootptr=NULL; 

BstNode* getNewNode(int _data)
{   
   BstNode* newNode=(BstNode*)malloc(sizeof(BstNode));
   (*newNode).data=_data; //(9:03)
   (*newNode).left=NULL;
   (*newNode).right=NULL;
   
   return newNode;
}


BstNode* Insert(BstNode* root,int data)
{
   //(7:11)
   if(root==NULL) //(9:39)
   {
      root=getNewNode(data);
      
   }else if(data<=root->data){
	   root->left=Insert(root->left,data);
   }else{
	   root->right=Insert(root->right,data);//(15:15)
   }
   
   return root;	
}

bool Search(BstNode* root,int data)
{
	bool result=true;
	if(root==NULL)
	{
		return false;
	}
	else if(root->data==data)
	{
		return true;
	}
	else if(data<=root->data){
		return Search(root->left,data);
	}
	else {
		return Search(root->right,data);
	}
	return result;
}



int main()
{
   int value=0;
   BstNode* root=NULL;
   root=Insert(root,15);
   
   root=Insert(root,10);
   root=Insert(root,20);
   root=Insert(root,25);
   
   /*
   Insert(root,10);
   Insert(root,20);
   Insert(root,25);
   */
   printf("root->data is %d \n",root->data);
   printf("please enter the value you want to search\n");
   //cin>>value;
   scanf("%d",&value);
   printf("value is %d\n",value);
   
   printf("The value is %d \n",value);
   if(Search(root,value)==true)
   {
      printf("found \n");//(17:47)
   }
  
}
/*
//my modified version




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

//BstNode* rootptr=NULL; 

BstNode* getNewNode(int _data)
{   
   BstNode* newNode=(BstNode*)malloc(sizeof(BstNode));
   (*newNode).data=_data; //(9:03)
   (*newNode).left=NULL;
   (*newNode).right=NULL;
   
   return newNode;
}


BstNode* Insert(BstNode* root,int data)
{
    if(root==NULL)
    {
        root=getNewNode(data);
        printf("data is %d \n",data);
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }else{
         root->right=Insert(root->right,data);
    }
    return root;
}

bool Search(BstNode* root,int data)
{
    bool result=false;
	if (data==root->data) {
	   printf("found it, ,root->data %d\n ",root->data);

	    result=true;
	}
	else if(data<=root->data) {
	    printf("data<=root->data and root->left->data is %d\n ",root->left->data);
	    result=Search(root->left,data);
	}
	else {
	    printf("else and root->right->data is %d\n ",root->right->data);

	    result=Search(root->right,data);
	}
	
	return result;
}



int main()
{
   int value=0;
   BstNode* root=NULL;
   root=Insert(root,15);
   
   root=Insert(root,10);
   root=Insert(root,20);
   root=Insert(root,25);
   
   /*
   Insert(root,10);
   Insert(root,20);
   Insert(root,25);
   */
   printf("root->data is %d \n",root->data);
   printf("please enter the value you want to search\n");
   //cin>>value;
   scanf("%d",&value);
   printf("value is %d\n",value);
   
   if(Search(root,value)==true)
   {
      printf("found \n");//(17:47)
   }else {
       printf("Not found \n");
   }
  
}



*/

/*Lecture 28:Binary search tree - Implementation in C/C++

https://www.youtube.com/watch?v=COZK7NATh4k&index=28&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P

-Binary search Tree (BST):A binary tree in which for each node, value of all the nodes
in left subtree is lesser or equal and value of all nodes in right subtree is greater(0:36)
-It must be true for all nodes (1:00) not just the root node (1:02)
-Fig 1 (1:09)

         15
	/  \
      10   20
     / \  /  \
    8 12 17   25
 -It is like a double link list since you have two nodes. One point to the preious node (2:29)
 -Doubl link list is a linear arrangment (2:35)
 -malloc has to be accessed through a pointer (3:15)
 -We need to know the address of the root node (3:53) so we can access all other nodes in a tree(3:57)
 -(4:46),(7:11)
 -We also can insert it without using by using a temporary (16:35) loop
 -
*/


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
	-In node 2, we only have 1 incoming link (9:52) and 3 out going links (9:56)
	-There will be one link between each parent and child relationship (10:00)
	-One incoming edge for each node except root (10:08)
->We are going to cover two properties as depth and height (10:15)
->Depth of X=length of path from root to x (10:21). Or # of edge in path from root to X(10:32)
 	-(think as penetration power from top to buttom)
	-depth of root node will be 0 (10:35)
	-eg, node 5 has depth of 2 (10:46)
	-depth of node 9,node 10 and node 11 are 3 (10:59)
->Height of X=# of edeges in largest path from x to leaf node (11:09)
	-(Think as how tall you are from buttom to top)
	-Height of Node 3 is 2 (11:26)
	-Height of leaf node is 0 (11:47)
	-Height of root or Node 1 is 3 (11:57)
->Height of the tree=height of the root node (12:04)
->Simpleset tree is any node can have at most 2 children (12:34)=binary tree (12:42)
->binary tree
	-center is to store data(13:13)
	-left is to store the address of left child
	-right is to store the address of right child(13:22)
	-Binary tree can't have more than two children (13:25)
	-We can define strcutre in C/C++ as in (13:40)
->generic tree
	-Can have many number of children (14:14)
->Application
	-Storing natually hierachical data (14:47) eg file system
	-organizing data eg quick search, insertion, deletion eg binary search tree gives log and time for searching element
	(15:16)
	-Trie for storing dictionary for dynmaic search(15:30)
	-Networking algorithm (15:43)
*/

/*
Lecture 26: Data structures  Binary tree
https://www.youtube.com/watch?v=H5JubkIy_p8&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=26

->Binary tree
	-It is good for storing the ordered data(0:35)
	-Each node can have at most two children (0:36)
	-However a node with one child can exist (0:48)
	-Each node in a binary tree can have at most 2 children, we call one of the children as left child
	and another as right child (1:00)
	-If there is "NULL" for the edge, it means it doesn't point to anything (1:44)
->classified binary trees into different types (1:59)
	-The only condition for binary tree is that it CAN'T have more than two children (2:15)
	-Strict binary tree->Each node can have either 2 or 0 children
	-Complete binary tree->all levels except possibly the last completely filled and all nodes are
	as left as possible (2:36)
		-maximum # of nodes at level i is 2^i  (3:49) starts from
		level 0 (4:10) 
		-eg level 0 is 2^0=1
		-The example given is not a complete binary tree since it is not left most(5:04)
		however, its level 2 is all filled
		-It changes to the complete binary tree in (5:10)
	-Perfect binary tree->all levels are filled
		-maxium number of nodes in a binary tree with a height as h (6:03)
		=2^0+2^1+....+2^h (6:10)=[2^(h+1)]-1 (6:20)
		OR=[2^(heights+1)]-1 OR= [2^(# of levels)]-1
		->in this case, our levels are 4 so we have 2^(4)-1=15 (6:38)
	-What will be the height of a perfect binary tree with n nodes? (6:59)
	-Need to solve the equation of n=[2^(h+1)]-1->h=log2(n+1)-1 (7:26)
->Height of complete binary tree-> floor[log2(n)] (7:9)
	-In this case, n=15 so floor[log2(15)]=3
->this math will help us to understand the cost of binary tree(8:31)
->cost of operation in trees depends on the height of the tree (8:36)
->In binary tree, the search, insertion and deletion is proprotional to the height of tree (8:50)
->So we want height of tree will be less (8:55)
->Height of tree will be less if the tree will be dense (8:55), if the tree will be closer to
a perfect binary tree or complete binary tree (9:02)
->minimum height of  a tree with nodes can be h=log2(n+1)-1 when the tree (9:07) will be a complete 
binary tree
->In an arrangment like a link list
	-With n node, mimimum height possible is floor[log2(n)]  (9:21)
	-max height=n-1
	-It is a.k.a as sparse tree (9:33) like a link list
->Time taken operation is proportional to the height of the tree (9:40) as O(h) (9:47)	
	-h=height of binary tree (9:50)
	-Complete binary tree will be O[log2(n)] (9:57), Best case (10:07)
	-In sparse tree, it will be O(n) (10:03), Worst case
	-Listen to the example again between (10:07 to 10:32)
->We want to keep the height of the tree as minimum as possible (10:32)
->We try to keep binary tree balanced-> Different between height of left and right subtree for
every node is not more than k(most 1) (10:39)
->Height-> # of edges in the longest path from root to a leaf (11:05)
->Height of an empty tree is -1 so
->height of tree with 1 node=0 (11:21)
->|difference|=|hleft-hright| (12:18)
->One example, |difference|=|1-2| (12:48)(??) (around 13:07)
	-Check the comment as 
	-We are saying height of left and right subtrees.  Height is defined as number of edges in some longest path  from root to   a leaf. 
	For the sub-trees, the root node is not the node marked in red. 
	For left subtree, root node is the left child and for right sub-tree root node is the right child.  
	We need to calculate from root of the respective subtrees.
->Another example, |difference|=|1-(-1)| (13:01)(13:13)
->We try to keep the height as minimized so the various operations that depends on height are minimized
(13:25)
->Store binary tree in memory(13:33)
	-dynamically create nodes (14:02)
		-most common way (14:04)
	-arrays
		-complete binary tree(14:41)
		-eg: array as 2,4,1,5,8,7,9
		     indices  0,1,2,3,4,5,6
		 -for nodea at index i
		 	left-child-index=2i+1
			right-child-indx=2i+2 (15:17)
		-It is used to implemen heap (15:57)
->binary search tree->for quick insertion and search quickly (16:14)
		
*/
