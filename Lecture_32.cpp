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
*/
