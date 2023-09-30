#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAX 100
using namespace std;
struct hangHoa{
	char maHang[MAX], tenHang[MAX];
	int donGia, sl, thangTien;
};

typedef hangHoa ElementType;	

struct Node{
	ElementType Element;
	Node *next;
};
typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;


void MakeNull_List(List &L);
void Insert_List(ElementType X, Position P, List L);
void read(ElementType *X);
void read_List(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
int tongDoanhThu(List L);
void write(ElementType X);
void write_List(List L);
void sapXepDSTheoTenHang(List L);
void lietKeHangThanhTien(List L);
void lietKeHangSoLuong(List L);
Position timMaHang(List L, const char *ms);
int main(){
	List L;
	MakeNull_List(L);
	read_List(L);
	int tdt = tongDoanhThu(L);
	printf("\ntong danh thu =  %d", tdt);
	printf("\nIn ds mat hang: \n");
	write_List(L);
	char ms[MAX];
	printf("\nms can tim: ");
	fflush(stdin);
	scanf("%s", &ms);
	Position k = timMaHang(L,ms);
	if(k >= 0){
		ElementType X = Retrieve(k);
		write(X);
	}
	else
		cout<<"\nkhong co";
	printf("\nsap xep ds theo ten hang: \n");
	sapXepDSTheoTenHang(L);
	write_List(L);
	printf("\ncac hang hoa thanh tien > 100000: \n");
	lietKeHangThanhTien(L);
	printf("\ncac hang hoa so luong < 10: \n");
	lietKeHangSoLuong(L);
	return 0;
}




void MakeNull_List(List &L){
	L = new Node;
	if(L == NULL){
		cout << "\nkhong du bo nho!";
		return;
	}
	L->next = NULL;
}
void Insert_List(ElementType X, Position P, List L){
	Position tmp;
	tmp = new Node;
	if(tmp == NULL)
		cout << " error!";
	tmp->Element = X;
	tmp->next = P->next;
	P->next = tmp;
}
void read(ElementType *X){
	printf("\nma hang: ");fflush(stdin);
	gets(X->maHang);
	printf("ten hang: ");fflush(stdin);gets(X->tenHang);
	printf("don gia: ");scanf("%d", &X->donGia);
	printf("so luong: ");scanf("%d",&X->sl);
	X->thangTien = X->donGia * X->sl;
}
void read_List(List L){
	int n;
	printf("n: ");
	scanf("%d", &n);
	Position P = Header(L);
	ElementType X;
	for(int i = 0 ; i < n; i ++){
		cout << "don Hang " << i + 1 << ":"<<endl;
		read(&X);
		Insert_List(X,P,L);
	}
}
Position Header(List L){
	return L;
}

Position First(List L){
	return L->next;
}

Position Advance(Position P){
	return P->next;
}

ElementType Retrieve(Position P){
	return P->Element;
}

int tongDoanhThu(List L){
	int tDT = 0;
	Position P = First(L);
	while(P != NULL){
		ElementType X = Retrieve(P);	
		tDT += X.thangTien;
		P = Advance(P);
	}
	return tDT;
}

void write(ElementType X){
	printf("%s\t%s\t%d\t%d\t%d\n", X.maHang, X.tenHang,X.donGia,X.sl, X.thangTien);
}

void write_List(List L){
	Position P = First(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		write(X);
		P = Advance(P);
	}
}

Position timMaHang(List L, const char *ms){
	Position P = First(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		int k = strcmp(ms, X.maHang);
		if(k == 0)	
			return P;
		P = Advance(P);
	}
	return NULL;
}

void sapXepDSTheoTenHang(List L){
	Position P = First(L);
	while(P != NULL){
		Position Q = First(L);
		while(Q != NULL){
			if(strcmp(P->Element.tenHang, Q->Element.tenHang) == 1){
				ElementType tmp = P->Element;
				P->Element = Q->Element;
				Q->Element = tmp;
			}
			Q = Advance(Q);
		}
		P = Advance(P);
	}
}

void lietKeHangThanhTien(List L){
	Position P = First(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		if(X.thangTien > 100000)
			write(X);
		P = Advance(P);
	}
}

void lietKeHangSoLuong(List L){
	Position P = First(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		if(X.sl < 10)
			write(X);
		P = Advance(P);
	}
}
