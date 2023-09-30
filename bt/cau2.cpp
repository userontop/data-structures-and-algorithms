#include<stdio.h>
#include<iostream>
#include<String.h>
using namespace std;
#define MAX 100
struct sinhvien{
	char mssv[MAX], ten[MAX], xeploai[MAX];
	float diem;
};

typedef sinhvien ElementType;
struct Node{
	ElementType Element;
	Node *next;
};

typedef Node* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

Position Header(List l);
void makeNull_List(List &l);
void insertList(ElementType x, Position p, List l);
void nhapNode(ElementType &x);
void nhapDS(List l, int n);
void xuatNode(ElementType x);
void xuatDS(List l);
void sapXepTang(List l);
void sapXepGiam(List l);
void xeploai(List &l);
void tach(List l, List l2, List l3);

int main(){
	List L;
	int n;
	cout << "nhap n: ";cin >> n;
	makeNull_List(L);
	nhapDS(L, n);
	xeploai(L);
	cout << "\n\nXuat danh sach sinh vien: \n";
	xuatDS(L);
	cout << "\n\nSap xep tang dan: \n";
	sapXepTang(L);
	xuatDS(L);
	cout << "\n\nSap xep giam dan: \n";
	sapXepGiam(L);
	xuatDS(L);
	List l1, l2;
	makeNull_List(l1);
	makeNull_List(l2);
	tach(L, l1, l2);
	cout << "\nDanh sach l1: \n";
	xuatDS(l1);
	cout << "\nDanh sach l2: \n";
	xuatDS(l2);
	return 0;
}

Position Header(List l){
	return l;
}
void makeNull_List(List &l){
	l = new Node;
	l->next = NULL;
}
void insertList(ElementType x, Position p, List l){
	Position tmp;
	tmp = new Node;
	if(tmp == NULL)
		cout << "\ndanh sach rong";
	else{
		tmp->Element = x;
		tmp->next = p->next;
		p->next = tmp;
	}
}
void nhapNode(ElementType &x){
	cout << "\nmssv: ";cin >> x.mssv;
	cout << "ten: ";cin >> x.ten;
	cout << "diem: ";cin >> x.diem;
}
void nhapDS(List l, int n){
	Position P = Header(l);
	ElementType x;
	for(int i = 0; i < n; i++){
		cout << "\nnhap sinh vien " << i + 1 << ": ";
		nhapNode(x);
		insertList(x, P, l);
	}
}
void xuatNode(ElementType x){
	cout << "\nmssv: " << x.mssv;
	cout << "\nten: " << x.ten;
	cout << "\ndiem: " << x.diem;
	cout << "\nxeploai: " << x.xeploai;
}
void xuatDS(List l){
	Position P = l->next;
	while(P != NULL){
		cout << "\n\tsinh vien: ";
		ElementType x = P->Element;
		xuatNode(x);
		P = P->next;
	}
}
void xeploai(List &l){
	Position P = l->next;
	while(P != NULL){
		if(P->Element.diem >= 5)
			strcpy(P->Element.xeploai, "TT");
		else
			strcpy(P->Element.xeploai, "KT");
		P= P->next;	
	}
}
void sapXepTang(List l){
	Position P = Header(l)->next;
	while(P != NULL){
		Position Q = P->next;
		while(Q != NULL){
			if(strcmp(P->Element.mssv,Q->Element.mssv) > 0){
				ElementType Tmp = P->Element;
				P->Element = Q->Element;
				Q->Element = Tmp;
			}
			Q = Q->next;
		}
		P = P->next;
	}
}
void sapXepGiam(List l){
	Position P = Header(l)->next;
	while(P != NULL){
		Position Q = P->next;
		while(Q != NULL){
			if(strcmp(P->Element.mssv, Q->Element.mssv) < 0){
				ElementType tmp = P->Element;
				P->Element = Q->Element;
				Q->Element = tmp;
			}
			Q = Q->next;
		}
		P = P->next;
	}
}
void tach(List l, List l2, List l3){
	Position P = l->next;
	Position P1 = l2;
	Position P2 = l3;
	while(P != NULL){
		if(strcmp(P->Element.xeploai, "TT") == 0)
			insertList(P->Element, P1, l2);
		else
			insertList(P->Element, P2, l3);
		P = P->next;
	}
}

