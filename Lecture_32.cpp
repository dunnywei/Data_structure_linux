//Lecutre_32_Binary tree traversal - breadth-first and depth-first strategies

//https://www.youtube.com/watch?v=9RHO6jU--GU&index=32&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P



#define max(X,Y) ((X)>(Y) ? (X):(Y))

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
   (*newNode).data=_data;
   (*newNode).left=NULL;
   (*newNode).right=NULL;
   
   return newNode;
}


BstNode* Insert(BstNode* root,int data)
{
   if(root==NULL)
   {
      root=getNewNode(data);
      
   }else if(data<=root->data){
	   root->left=Insert(root->left,data);
   }else{
	   root->right=Insert(root->right,data);
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

int FindMin(BstNode* root)
{
    //Lecture 30(1:01)
    BstNode* current=root;
    if(current==NULL)//we need to check if tree is empty or not(3:07)
    {
	 printf("Error occurs since Tree is empty \n");
	 return -1;
    }
    while(current->left!=NULL)
    {
	    current=current->left;
    }
    return current->data;
}

int FindMin_recursion(BstNode* root)
{
    BstNode* current=root;
    if(current==NULL)
    {
	 printf("Error occurs since Tree is empty \n");
	 return -1;
    }
    else if(current->left==NULL)//Lecture 30 (4:43)
    {
	return current->data;
    }
    return FindMin_recursion(current->left);
   

}

int FindHeight(BstNode* root)
{
   //Lecture 31 (3:00)
   BstNode* current=root;
   int leftheight=0;
   int rightheight=0;

   if(current==NULL)
   {
       return -1;
   }
   leftheight=FindHeight(current->left);
   rightheight=FindHeight(current->right);
   return max(leftheight,rightheight)+1;//(7:07)
}

int main()
{
   int value=0;
   BstNode* root=NULL;
   root=Insert(root,15);
   
   root=Insert(root,10);
   root=Insert(root,20);
   root=Insert(root,25);
   //root=Insert(root,9);
   //root=Insert(root,8);	

   
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
      printf("found \n");
   }
   //printf("FindMin is %d \n",FindMin(root));
   //printf("FindMin_recursion is %d \n",FindMin_recursion(root));
	
	
   printf("FindHeight(root) %d \n",FindHeight(root));
}

//Lecture 32 starts
/*
->When we want to traverse the tree, tree is not a linear data as the array or linke list (0:08)(0:13) 
->Linear means that we have the logical star and logical end (0:19) so will have a pointer from start and traverse
to the next node until the end (0:24)
->However tree is not a linear data structure (0:33)
->Which order should I vist the node?
->In binary tree, we can have more than one possible direction (0:48)
->Definition of Tree Traversal->The process of visiting each node in the tree exactly once in some order (1:25)
->visi=reading/processing data in a node (1:33)
	-In this lession, traverse meanse priting data in the node (1:37)
->There are two categories for traversing the tree
->1)Breadth-frist (1:47) and 2)Depth First (1:49)
->Both bradth-first and depth-first are used in another data structure Graph (2:00)

->Tree is a special kind of graph(2:07)
->In readth-frist (1:47)
  -Visit all the nodes at the same depth or level(2:20) before visiting the node at next level
  (2:22)
  -After level 0, we will visit the node from left to right (3:18)
  -So we will visit F    as level 0 (3:24)
                    D,J  as Level 1
                    BEGK as Level 2
		   ACI   as Level 3
		    H    as level 4
  -It is a.k.a level traversal (3:45) or level order
  -We visit all of the childeren (in the same level) before going to the grand-children (next 
  level (4:01)
->In Depth-frist (4:14)
   -we would go to a child and complete the whole subtree of the child before going to
   the next child (4:19)
   -We start at F, we should finish this left subtree of F in its complete depth (4:32)
   -We should finish the left grandchildren of F->D before going to the right child of F->J (4:42)
   -Once we are at J, we will complete the the right subtree of F (4:48)
   -IN Depth first appraoch, the relative order of visiting (4:54) the left 
   of subtree, the right subtree and root node (4:58) can be different (5:00)
   -For example we can first vist the right of subtree (5:03), then the root then the left of
   subtree (5:07)
   -OR we can visit root, left of the subtree and right of the subtree (5:13)
   -Core startegy (5:20) in depth-first->visiting the complete subtree in that path(5:19)
   -Visiting a node is reading,processing and printting data in that node (5:28) 
   -There are three popular depth startegies (5:36)
   	-1st->(<Root>)<Left><Right> (5:39). Where left subtree and right subtree will visit recursively (5:46). A.K.A pre-order traversal (5:50)
	      -D(data),L,R->read data on the current node then LEFT and RIGHT (6:58)
	
	-2nd-><Left>(<Root>)<Right>. A.K.A in order traversal (6:00)
	    -LDR
	-3rd-><Left><Right>(<Root>_. A.K.A post order traversal (6:07)
	    -LRD(7:27)
   -Convetionally left subtree is always visited before right subtree (6:17)
   -Only the position of root is changing (6:25)
		   -      F                L0
			/  \
		       D    J              L1
		     / \  /  \
		    B   E G    K	   L2
	           / \     \
                  A  C     I               L3
		          /
			 H                 L4
->Using the example and find out the Preorder (DLR) or (VLR) (7:45)
	-Start at root node and for each node, we first need to read the data(7:50)
	-(8:15)So starts at FDBACE (9:22). Left of F is done
	-FDBACE then right of the tree 
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->
->

*/
