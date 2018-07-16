//https://www.youtube.com/watch?v=92S4zgXN17o&index=1&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <string>

using namespace std;
struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node Node;

Node* A = NULL;

//adding to the front
void createENode(int _number)
{
	
		Node *temp = (struct Node *)malloc(sizeof(struct Node));

		if (temp == 0)
		{
			printf("Can't allocate memory \n");
		}
		temp->data = _number;
		temp->next = A;
		A = temp;
    


	return;
}
void insertNode(int _data, int _pos)
{
	Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=_data;
	temp->next=NULL;
        Node* temp1=A;
	Node* temp2=NULL;
	if(A!=NULL)
	{
	    for(int i=0;i<(_pos-1);i++)
	    {
		    temp1=temp1->next;
	    }
		
	    temp2=temp1->next;
	    temp1->next=temp;
	    temp->next=temp2;
		
	}
	else
	{
		printf("A is NULL\n");
	}
	
}

int traverseList()
{
	int counter=0;
	Node* temp1 = A;
	while (temp1 != NULL)
	{
		printf("@traverseList counter is %d,The data is %d \n", counter, temp1->data);
		temp1 = temp1->next;
		counter+=1;
	}
	
	return counter;
}

void deletehead()
{
	Node *temp = A;
	if (A != NULL)
	{
		if ((A->next != NULL))
		{
			A = temp->next;
			free(temp);

		}
		else{
			printf("@A->next==NULL \n");
			free(temp);
			A = NULL;

		}
	}
	else{
		printf("Nothing to delete \n");
	}
}
void deletN(int _n)
{
	Node *temp1=A;
	if (_n<2)
	{
		A=temp1->next;
		free(temp1);
		return;
	}
	
	//for(int i=0;i<(_n-2);i++)
	for(int i=0;i<(_n-2);i++)
	{
		temp1=temp1->next;
	}
	Node *temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);
}
void reverseIter()
{
	//https://www.youtube.com/watch?v=sYcOK51hl-A&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=9
	Node *current=A;
	Node *prev=NULL;
	Node *next=NULL;
	while (current!=NULL)
	{
	        cout<<"@reverseIter,The value of current->data is"<<current->data<<endl;

		next=current->next;
		current->next=prev;
		prev=current;
		current=current->next; //(9:18) or *(current).next
	}
	A=prev;
}

int main()
{
	int temp;
	
	createENode(6);
    
	createENode(4);
	createENode(2);
	insertNode(8,2);
	printf("There are %d of elements in link\n",traverseList());
	
	//deletN(3);
	//printf("After delete,There are %d of elements in link \n",traverseList());
	reverseIter();
	printf("After reverse, There are %d of elements in link \n",traverseList());
	
	

	/*
	int x;
	for( x= -5 ; x<7; x++) printf("x is %d \n",x);
	printf("hey hey\n");
        createENode(9);
    
	createENode(10);
	createENode(11);
	createENode(12);
	
	printf("There are %d in the list \n",traverseList());
    
   deletN(4);
   traverseList();
   printf("delete first \n");
   deletN(1);
   traverseList();
  */



	/*delete old
	deletehead();
	deleteN(2);
	
    printf("There are %d in the list \n",traverseList());
	
    deleteN(2);
    printf("There are %d in the list \n",traverseList());
	
	deleteN(1);
    printf("There are %d in the list \n",traverseList());

    */
	//printf("The value of A->data is %d \n",A->data);
	/*
	addNodeEnd(9);
	traverseList();
	*/
	/*
	reverseIter();
	traverseList();
	*/
	return 0;
}

//make clean -f Mymakefile
//make all -f Mymakefile
