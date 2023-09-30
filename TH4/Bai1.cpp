#include<iostream>
#include<string.h>
using namespace std;

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef PtrToNode Position;

struct Node
{
	ElementType Element;
	Position Next;
};

void MakeEmpty(Stack &S);
int IsEmpty(Stack S);
void Push(ElementType X, Stack S);
void Pop(Stack S);
ElementType Top(Stack S);

void Read(int n, Stack S);
void Write_Pos(int k, Stack S);
void Write(int n, Stack S);
int main()
{
	Stack S;
	MakeEmpty(S);
	int n;
	cout<<"Nhap n: "; cin>>n;
	cout<<"Day fibonacci: ";
	Read(n, S);
	Write(n, S);
	return 0;
}

void MakeEmpty(Stack &S)
{
	S = new Node;
	S->Next = NULL;
}

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

void Push(ElementType X, Stack S )
{
	Position TmpCell, P;
	P = S;
	TmpCell = new Node;
	if( TmpCell == NULL )
		cout<<"Out of space!!!";
		
	TmpCell->Element = X;
	TmpCell->Next = P->Next;
	P->Next = TmpCell;
}

void Pop(Stack S)
{
	Position P, TmpCell;
	P = S;
	if(P->Next!=NULL)
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		delete TmpCell;
	}
}

ElementType Top(Stack S)
{
	return S->Next->Element;
}

void Read(int n, Stack S)
{
	Push(1, S);
	Push(1, S);
	for(int i=2; i<=n; i++)
	{
		ElementType Fn_1=Top(S);
		Pop(S);
		ElementType Fn_2=Top(S);
		ElementType Fn=Fn_1+Fn_2;
		Push(Fn_1, S);
		Push(Fn, S);
	}
}

void Write_Pos(int k, Stack S)
{
	Position P=S->Next;
	int i=0;
	while(P!=NULL)
	{
		if(i==k)
		{
			cout<<P->Element<<" ";
		}
		i++;
		P=P->Next;
	}
}

void Write(int n, Stack S)
{
	for(int i=n-1; i>=0; i--)
	{
		Write_Pos(i, S);
	}
}
