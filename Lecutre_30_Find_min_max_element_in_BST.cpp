//Lecutre_30_Find_min_max_element_in_BST.cpp
//->https://www.youtube.com/watch?v=Ut90klNN264&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=30

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

/*Lecture 30 starts
 *->Trees in left is less/Equal and right of tree is greater
 *->
*/
