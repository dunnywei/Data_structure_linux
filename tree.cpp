
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
