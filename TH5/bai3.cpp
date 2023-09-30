#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct sinhvien{
	char mssv[100];
	char hten[100];
	float diemTB;
};

typedef sinhvien ElementType;
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
Tree Delete(const char *X, Tree &T);
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
		T = new TreeNode;
		if(T == NULL) printf("Out of space");
		else{
			T -> Element = X;
			T->Left = T->Right = NULL;
		}
	}	
	else if(strcmp(X.mssv, T->Element.mssv) == -1)
		T->Left = Insert(X, T->Left);
		else if(strcmp(X.mssv, T->Element.mssv) == 1)
		T->Right = Insert(X, T->Right);
		return T;
}
Node Search(ElementType X, Tree T){
	if(T == NULL)
		return NULL;
	if(strcmp(X.mssv, T->Element.mssv) == -1)
		return Search( X, T->Left);
	else if(strcmp(X.mssv, T->Element.mssv) == 1)
		return Search(X, T->Right);
	else
		return T;
}
Tree Delete(const char *X, Tree &T){
	Node TmpCell;
	if(T == NULL) printf("Element not found");
	else 
		if(strcmp(X, T->Element.mssv) == -1)
			T->Left = Delete(X, T->Left);
		else
			if(strcmp(X, T->Element.mssv) == 1)
				T->Right = Delete(X, T->Right);
		else
			if(T->Left != NULL && T->Right != NULL){
				TmpCell = FindMin(T->Right);
				T->Element = TmpCell-> Element;
				T->Right = Delete(T->Element.mssv, T->Right);
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
	cout << "MSSV: " << T->Element.mssv<<endl;
	cout << "Ho ten: " << T->Element.hten << endl;
	cout << "Diem trung binh: " << T->Element.diemTB << endl;
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
	Node P;
	int n;
	cout << "nhap so luong sinh vien: ";
	cin >> n;
	ElementType X;
	for(int i = 0; i < n; i++){
		fflush(stdin);
		cin.clear();
		cout << "nhap sinh vien" << i + 1 << endl;
		cout << "Mssv: ";
		cin.getline(X.mssv, 10);
		cout << "ho ten: ";
		cin.getline(X.hten, 30);
		cout << "Diem trung binh: ";
		cin >> X.diemTB;
		Insert(X, T);
	}
	
	cout << "danh sach sinh vien: \n";
	inOrder(T);
	char ms[10];
	cout << "\nNhap MSSV can tim: ";
	fflush(stdin);
	cin.clear();
	cin.getline(ms, 10);
	P = Search(X, T);
	if(P == NULL)
		printf("khong tim thay %s\n", X);
	else{
		printf("tim thay %s\n", X);	
		cout << "MSsv: " << P->Element.mssv << endl;
		cout << "hoTen: "<< P->Element.hten << endl;
		cout << "Diem trung binh: " << P->Element.diemTB << endl;
	}
	
	cout << "\nNhap MSSV can xoa: ";
	fflush(stdin);
	cin >> ms;
	cin.clear();
	Delete(ms, T);
	cout << "Danh sach sinh vien sau khi xoa\n";
	inOrder(T);
	return 1;
}

