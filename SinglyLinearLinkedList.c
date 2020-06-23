//Singly Linear Linked List
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node
{
	int Data;
	struct Node *Next;
}NODE,*PNODE,**PPNODE;

void InsertFirst(PPNODE,int);
void InsertLast(PPNODE,int);
void InsertAtPos(PPNODE,int,int);
void DeleteFirst(PPNODE);
void DeleteLast(PPNODE);
void DeleteAtPos(PPNODE,int);
void Display(PNODE);
int Count(PNODE);

int main()
{
	PNODE Head=NULL;
	int iRet=0;
	
	InsertFirst(&Head,101);
	InsertFirst(&Head,51);
	InsertFirst(&Head,21);
	InsertFirst(&Head,11);

	//Display(Head);
	//iRet=Count(Head);
	//printf("Number of Nodes are %d",iRet);

	InsertLast(&Head,111);
	InsertLast(&Head,121);
	InsertLast(&Head,151);

	InsertAtPos(&Head,10,1);
	InsertAtPos(&Head,20,2);
	InsertAtPos(&Head,150,9);

	DeleteFirst(&Head);
	DeleteLast(&Head);
	DeleteAtPos(&Head,2);
	
	Display(Head);
	iRet=Count(Head);
	printf("Number of Nodes are %d",iRet);
	
	return 0;
}
void InsertFirst(PPNODE First,int iNo)
{
	PNODE NewN=NULL;

	NewN=(PNODE)malloc(sizeof(Node));

	NewN->Data=iNo;
	NewN->Next=NULL;

	if(*First==NULL)
	{
		(*First)=NewN;
	}
	else
	{
		NewN->Next=*First;
		(*First)=NewN;
	}
}
void InsertLast(PPNODE First,int iNo)
{
	PNODE NewN=NULL;
	PNODE Temp=NULL;

	NewN=(PNODE)malloc(sizeof(NODE));

	NewN->Data=iNo;
	NewN->Next=NULL;

	if(*First==NULL)
	{
		(*First)=NewN;
	}
	else
	{
		Temp=(*First);
		while((Temp->Next)!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=NewN;
	}
}
void InsertAtPos(PPNODE First,int iNo,int iPos)
{
	int iSize=0,iCnt=0;
	PNODE NewN=NULL;
	PNODE temp=(*First);
	iSize=Count(*First);
	
	if(iPos==1)
	{
		InsertFirst(First,iNo);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(First,iNo);
	}
	else
	{
		NewN=((PNODE)malloc(sizeof(NODE)));
		NewN->Next=NULL;
		NewN->Data=iNo;

		for(iCnt=0;iCnt<iPos-1;iCnt++)
		{
			temp=temp->Next;
		}

		NewN->Next=temp->Next;
		temp->Next=NewN;
	}


}
void DeleteFirst(PPNODE First)
{
	PNODE temp=*First;

	if(*First!=NULL)
	{
		(*First)=(*First)->Next;
		free(temp);
	}
}
void DeleteLast(PPNODE First)
{
	PNODE temp=NULL;

	if(*First==NULL)
	{
		return;
	}
	else if((*First)->Next==NULL)
	{
		free(*First);
		*First=NULL;
	}
	else
	{
		temp=(*First);
		while(temp->Next->Next!=NULL)
		{
			temp=temp->Next;
		}
		free(temp->Next);
		temp->Next=NULL;
	}
}
void DeleteAtPos(PPNODE First,int iPose)
{
	PNODE temp=(*First);
	PNODE target=NULL;
	int i=0;
	int iSize=Count(*First);
	if((iPose<1)||(iPose>iSize))
	{
		return;
	}
	if(iPose==1)
	{
		DeleteFirst(First);
	}
	else if(iPose==iSize)
	{
		DeleteLast(First);
	}
	else
	{
		for(i=1;i<iPose-1;i++)
		{
			temp=temp->Next;
		}

		target=temp->Next;

		temp->Next=target->Next;
		free(target);
	}
}
void Display(PNODE First)
{
	while((First)!=NULL)
	{
		printf("%d\t",First->Data);
		First=First->Next;
	}
}
int Count(PNODE First)
{
	int iCnt=0;
	while(First!=NULL)
	{
		iCnt++;
		First=First->Next;
	}
	return iCnt;
}