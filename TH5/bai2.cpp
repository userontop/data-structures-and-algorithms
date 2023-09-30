#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef int ElementType;
struct TreeNode;
typedef struct TreeNode *Node;
typedef struct TreeNode *Tree;

struct TreeNode{
	ElementType Element;
	Node Left;
	Node Right;
};


int isEmpty_Tree(Tree T);
Tree MakeEmppty(Tree T);
Tree Insert(ElementType X, Tree &T);
Node Search(ElementType X, Tree T);
Tree Delete(ElementType X, Tree &T);
Node FindMin(Tree T);
Node FindMax(Tree T);
ElementType ReTtrieve(Node P);
int isEmpTy_Tree(Tree T);
Node LeftChild(Tree p);
Node RightChild(Tree p);

void preOrder(Tree T);
void inOrder(Tree T);
void posOrder(Tree T);

int countNode(Tree T);
int countLeafNode(Tree T);


void menu(){
	printf("\n1. nhap cay\n");
	printf("2. tim kiem\n");
	printf("3. xoa\n");
	printf("4. Duyet tien tu\n");
	printf("5. Duyet trung tu\n");
	printf("6. Duyet Hau Tu\n");
	printf("7. Dem so nut ren cay\n");
	printf("8. dem so la tren cay\n");
	printf("0. Thoat");
}

int isEmpty_Tree(Tree T){
	return (T == NULL);
}
Tree MakeEmpty(Tree T){
	if(T != NULL){
		MakeEmpty(T ->Left);
		MakeEmpty(T ->Right);
		free(T);
	}
	return NULL;
}
Tree Insert(ElementType X, Tree &T){
	if(T == NULL){
		T = (TreeNode*) malloc(sizeof(struct TreeNode));
		if(T == NULL) printf("Out of space");
		else{
			T -> Element = X;
			T->Left = T->Right = NULL;
		}
	}	
	else if(X < T ->Element)
		T->Left = Insert(X, T->Left);
		else if(X > T ->Element)
		T->Right = Insert(X, T->Right);
}
Node Search(ElementType X, Tree T){
	if(T == NULL)
		return NULL;
	if(X < T->Element)
		return Search( X, T->Left);
	else if(X > T->Element)
		return Search(X, T->Right);
	else
		return T;
}
Tree Delete(ElementType X, Tree &T){
	Node TmpCell;
	if(T == NULL) printf("Element not found");
	else 
		if(X < T->Element)
			T->Left = Delete(X, T->Left);
		else
			if(X > T->Element)
				T->Right = Delete(X, T->Right);
		else
			if(T->Left != NULL && T->Right != NULL){
				TmpCell = FindMin(T->Right);
				T->Element = TmpCell-> Element;
				T->Right = Delete(T->Element, T->Right);
			} 
			else{
				TmpCell = T;
				if(T->Left == NULL)	T = T->Right;
				else if(T->Right == NULL) T = T->Left;
				free(TmpCell);	
			}
	return T;
}
Node FindMin(Tree T){
	if(T==NULL)
		return NULL;
	else if(T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Node FindMax(Tree T){
	if(T==NULL)
		return NULL;
	else if(T->Right == NULL)
		return T;
	else
		return FindMax(T->Right);
}
ElementType ReTtrieve(Node P){
	return P->Element;
}
Node LeftChild(Tree p){
	if (p!=NULL) 
		return p->Left; 
	else 
		return NULL;
}
Node RightChild(Tree p){
	if (p!=NULL)
		return p->Right;
	else 
		return NULL; 
}

void preOrder(Tree T){
	if(T!=NULL)
		printf("\t%d",T->Element);
	if (LeftChild(T)!=NULL)
		preOrder(LeftChild(T));
	if (RightChild(T)!=NULL)
		preOrder(RightChild(T));
}
void inOrder(Tree T){
	if (LeftChild(T)!=NULL)
		inOrder(LeftChild(T));
	printf("\t%d",T->Element);
	if (RightChild(T)!=NULL)
		inOrder(RightChild(T));
}
void posOrder(Tree T){
	if (LeftChild(T)!=NULL) 
		posOrder(LeftChild(T)); 
	if (RightChild(T)!=NULL)
		posOrder(RightChild(T)); 
	printf("\t%d ",T->Element);
}

int countNode(Tree T){
	int a = 0;
	if(isEmpty_Tree(T)) 
		return 0; 
	else 
		return a += 1 + countNode(LeftChild(T))
	+ countNode(RightChild(T));
}
int countLeafNode(Tree T){
	if(T!=NULL) 
		return(LeftChild(T)==NULL)
				&&(RightChild(T)==NULL); 
	else 
		return 0; 
}

int main(){
	Tree T = NULL;
	int chon = 0;
	int x;
	do{
		menu();
		printf("\nchon: ");
		scanf("%d", &chon);
		switch(chon){
			case 1:{
				printf("nhap cay nhi phan\n");
				int n, x;
				printf("nhap so nut cua cay:");
				scanf("%d", &n);
				for(int i = 0 ; i < n; i++){
					printf("nhap nut %d: ", i + 1);
					scanf("%d", &x);
					Insert(x, T);
				}
				break;
			}
			case 2:{
				Node P;
				printf("nhap x: "); scanf("%d", &x);
				P = Search(x, T);
				if(P == NULL)
					printf("khong tim thay %d\n", x);
					else
						printf("tim that %d\n", x);				
				break;
			}
			case 3:{
				printf("\nnhap gia tri x can xoa: ");
				scanf("%d", &x);
				Delete(x, T);
				break;
			}
			case 4:{
				printf("Duyet tien tu: \n");
				preOrder(T);
				break;
			}
			case 5:{
				printf("Duyet trung tu: \n");
				inOrder(T);
				break;
			}
			case 6:{
				printf("Duyet hau tu: \n");
				posOrder(T);
				break;
			}
			case 7:{
				printf("Dem so nut tren cay: %d", countNode(T));
				break;
			}
			case 8:{
				printf("dem so la tren cay: %d", countLeafNode(T));
				break;
			}
			case 0:{
				break;
			}
			default:{
				break;
			}
		}
	}while(chon != 0);
	return 1;
}

