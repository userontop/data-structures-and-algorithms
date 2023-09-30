#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct hocsinh{
	int sobaodanh;
	char ten[30], lop[30];
	float toan, ly, hoa, anh, dtb;
};

typedef hocsinh ElementType;

struct Node{
	ElementType Element;
	Node *next;
};

typedef Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void makeNull_List(List &L);
void inser_List(ElementType X, Position P, List L);
void nhap(ElementType &X);
void nhapDS(List L, int n);
void xuat(ElementType X);
void xuatDS(List L);
void diemTB(ElementType &X);
void sapXep(List L);
void lietKe(List L);


int main(){
	List L;
	int n;
	cout << "nhap vao so luong hoc sinh: ";cin >> n;
	makeNull_List(L);
	cout << "\nNhap vao hoc sinh: ";
	nhapDS(L, n);
	cout << "\n\nIn Danh sach Hoc Sinh:";
	xuatDS(L);
	cout << "\n--------------------";
	cout << "\nSap Xep Danh Sach Hoc Sinh: \n";
	sapXep(L);
	xuatDS(L);
	cout << "\n--------------------";
	cout << "\nCac Thi Sinh co DTB > 8: \n";
	lietKe(L);
	return 0;
}


void makeNull_List(List &L){
	L = new Node;
	L->next = NULL;
}
void inser_List(ElementType X, Position P, List L){
	Position tmp;
	tmp = new Node;
	if(tmp == NULL)
		printf("\nbo nho day!");
	else{
		tmp->Element = X;
		tmp->next = P->next;
		P->next = tmp;
	}
}
void nhap(ElementType &X){
	cout << "\nSo bao danh: "; cin >> X.sobaodanh;
	cout << "ho va ten: "; fflush(stdin);gets(X.ten);
	cout << "lop: ";fflush(stdin);gets(X.lop);
	cout << "toan: "; cin >> X.toan;
	cout << "ly: "; cin >> X.ly;
	cout << "hoa: "; cin >> X.hoa;
	cout << "anh: "; cin >> X.anh;
	diemTB(X);
}
void nhapDS(List L, int n){
	Position P = L;
	for( int i = 0; i < n; i++){
		cout << "\nhoc sinh " << i + 1 <<": ";
		ElementType X;
		nhap(X);
		inser_List(X, P, L);
		P = P->next;
	}
}
void xuat(ElementType X){
	cout << "\nSo bao danh: " << X.sobaodanh;
	cout << "\nho va ten: " << X.ten;
	cout << "\nlop: " << X.lop;
	cout << "\ntoan: " << X.toan;
	cout << "\nly: " << X.ly;
	cout << "\nhoa: " << X.hoa;
	cout << "\nanh: " << X.anh;
	cout << "\nDiem trung binh: " << X.dtb;
}
void xuatDS(List L){
	Position P = L->next;
	int i = 0;
	while(P != NULL){
		i++;
		cout << "\nhoc sinh " << i;
		ElementType X = P->Element;
		xuat(X);
		P = P->next;
	}
}
void diemTB(ElementType &X){
	X.dtb = (X.hoa + X.toan + X.anh + X.ly)/4;
}
void sapXep(List L){
	Position P = L->next;
	while(P != NULL){
		Position Q = P->next;
		while(Q != NULL){
			if(P->Element.dtb < Q->Element.dtb){
				ElementType tmp = P->Element;
				P->Element = Q->Element;
				Q->Element = tmp;
			}
			Q = Q->next;
		}
		P=P->next;
	}
}
void lietKe(List L){
	Position P = L->next;
	while(P != NULL){
		ElementType X = P->Element;
		if(X.dtb > 8)
			xuat(X);
	P = P->next;
	}
}
