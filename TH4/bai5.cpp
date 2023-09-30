#include<stdio.h>
#include<iostream>
#include<String.h>
#define MAX 100
using namespace std;

struct hocsinh{
	int stt;
	float diemTB;
	char name[MAX], ms[MAX], xeploai[MAX], hanhkiem[MAX];
};

typedef hocsinh ElementType;

struct Node{
	ElementType Element;
	Node *next;
};

typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

Position first(List L);
Position header(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void MakeNull_List(List &L);
void Insert_List(ElementType X, Position P, List L);
void read(ElementType *X);
void read_List(List L);
void write(ElementType X);
void write_List(List L);
Position name_Search(List L, char name[]);
Position ms_Search(List L, char ms[]);
void LietKe_LoaiGioi(List L);
void sapXepTheoMS(List L);

int main(){
	List L;
	MakeNull_List(L);
	read_List(L);
	write_List(L);
	char name[MAX];
	printf("\nten  can tim: ");fflush(stdin);
	gets(name);
	Position P = name_Search(L,name);
	if(P != NULL){
		ElementType X = Retrieve(P);
		write(X);
	}else
		printf("\nkhong tim thay!");
	char ms[MAX];
	printf("\nms can tim: ");
	fflush(stdin);gets(ms);
	P = ms_Search(L, ms);
	if(P != NULL){
		ElementType X = Retrieve(P);
		write(X);
	}else
		printf("\nkhong tim thay!");
		sapXepTheoMS(L);
		printf("\nds da sap xep: ");
		write_List(L);
	return 0;
}


void MakeNull_List(List &L){
	L = new Node;
	if(L == NULL){
		printf("\nERROR!");
		return;
	}
		L->next = NULL;
}
void Insert_List(ElementType X, Position P, List L){
	Position  tmp;
	tmp = new Node;
	if(tmp == NULL)
		printf("\nERROR!");
	tmp->Element = X;
	tmp->next = P->next;	
	P->next = tmp;
}
void read(ElementType *X){
	printf("\nms: ");fflush(stdin);gets(X->ms);
	printf("ten: ");fflush(stdin);gets(X->name);
	printf("diem = ");scanf("%f", &X->diemTB);
	printf("hanh kiem: ");fflush(stdin);gets(X->hanhkiem);
	if(X->diemTB >= 8 && strcmp(X->hanhkiem, "tot") == 0)
		strcpy(X->xeploai, "gioi");
	else if(X->diemTB >= 8 && strcmp(X->hanhkiem,"kha") == 0)
		strcpy(X->xeploai, "kha");
	else if(X->diemTB >= 6.5 && strcmp(X->hanhkiem,"tot") == 0)
		strcpy(X->xeploai, "kha");
	else if(X->diemTB >= 6.5 && strcmp(X->hanhkiem,"kha") == 0)
		strcpy(X->xeploai, "kha");
	else if(X->diemTB >= 6.5 && strcmp(X->hanhkiem,"trungbinh") == 0)
		strcpy(X->xeploai, "trung binh");
	else{
		strcpy(X->xeploai, "yeu");
	}
}
void read_List(List L){
	Position P = header(L);
	ElementType X;
	int n;
	printf("n: ");scanf("%d", &n);
	for(int i =0; i < n; i++){
		X.stt = i + 1;
		printf("\nstt %d: \n", X.stt);
		read(&X);
		Insert_List(X, P, L);
	}
}
Position first(List L){
	return L->next;
}
Position header(List L){
	return L;
}
Position Advance(Position P){
	return P->next;
}
ElementType Retrieve(Position P){
	return P->Element;
}
void write(ElementType X){
	printf("%d\t%s\t%s\t%.1f\t%s\t%s\n", X.stt, X.ms, X.name, X.diemTB, X.hanhkiem, X.xeploai);
}
void write_List(List L){
	Position P = first(L);
	printf("\nDanh sach hoc sinh: \n");
	while(P != NULL){
		ElementType X = Retrieve(P);
		write(X);
		P = Advance(P);
	}
}
Position name_Search(List L, char name[]){
	Position P = first(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		if(strcmp(X.name, name) == 0)
			return P;
		P = Advance(P);
	}
	return NULL;
}
Position ms_Search(List L, char ms[]){
	Position P = first(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		if(strcmp(X.ms, ms) == 0)
			return P;
		P = Advance(P);
	}
	return NULL;	
}
void LietKe_LoaiGioi(List L){
	Position P = first(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		if(strcmp(X.xeploai, "gioi") == 0)
			write(X);
		P = Advance(P);
	}
}
void sapXepTheoMS(List L){
	Position P = first(L);
	while(P != NULL){
		Position Q = first(L);
		while(Q != NULL){
			if(Q->Element.stt > P->Element.stt){
				ElementType tmp = P->Element;
				P->Element = Q->Element;
				Q->Element = tmp;
			}
			Q = Advance(Q);
		}
		P = Advance(P);
	}
}
