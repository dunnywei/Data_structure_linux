//Lecutre_33_Binary tree: Level Order Traversal

//https://www.youtube.com/watch?v=86g8jAQug04&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=33


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

//Lecture 33 starts
/*
->
->
->
->		            F(400)                         L0
->			/            \
->		       D(200)          J(100)              L1
->	              /      \        /       \
->                   B(120)   E(160) G(220)    K(300)	   L2
->                  /      \           \
->                 A(320)  C(780)     I(560)               L3
->		                      /
->			             H(720)                L4
->
->Queue
   -><-|400| <-
   ->  | F |
   -> nothing is written here
   queue(FIFO)
->
->
->In this lession, we are going to focus on the implementation of level traversal (0:03)
->We will visit all nodes at the particular depth (0:11) or level before visiting the next deeper level
(0:15)
->FDJBEGKACIH
->If I have a pointer named "current" (1:10), I can go left to D (1:21). HOwever from D, I can't go to J (1:23)
	-Since we don't have a link from D to J. The only link is from F(1:28)
	-Once we are in D, we can't go back to F since there is no backward link from D to F (1:32)
	-Whwat we can do is as we visit a noode, we can reference or address all its children (1:48) in a queue (1:50) so
	we can visit them later.
->A node in a queue is called discovered node. The address is known to us but is not visited
  yet (1:58)
->Initially, We can start at the address of the root in the queue to mean that intially this is
  the only discovered node (2:05)
	-400 means the address of root node is 400 (2:18)
	-Storing the address in the queue (2:25).Storing the nodes in the queue means storing the address in the queue (2:25)
	-Initially, we will start at the discover node (2:29)
	-As long as the queue has at least one discovered node (queue is not empty),we can take out
	the node from the front (2:39) we can visit it and enqueue its children (2:42) 
	   -visiting a node means to print the value in that node (2:46)	
	   -In this case, 400 will be taken out as 
	   
	-><- (empty)  <-
	->   |     |
        ->F is written here
	    -Now including the children as left child and right child(2:57)
	--><- |200|100|  <-
	->    | D | J |
        ->F is written here
	    -	
	-
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
