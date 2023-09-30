#include<iostream>
#include<string.h>
#define MAX 100
using namespace std;

struct nhanvien{
	char msnv[MAX];
	char hoten[MAX];
	int luongcoban, songaycong, luong;
	float hesoluong;
};


typedef nhanvien ElementType;

struct Node {
	ElementType Element;
	Node *Next;
};
typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

void Makenull_List(List &L);
int IsEmpty_List(List L);
int IsLast(Position P);
Position Locate(ElementType X, List L);
void Delete_List(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert_List(ElementType X, Position P, List L);
void Delete_All_List(List );
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void Read_List(List L);
void SapXepTheoLuong(List L);
void TinhLuong(List L);
void InBangLuong(List L);
void LietKeTheoNgayCong(List L);
void write(ElementType X);
Position TimKiemHoTen(const char *hoten, List L);

int main() {
	List L;
	Makenull_List(L);
	Position P = Header(L);
	Read_List(L);
	TinhLuong(L);
	printf("in bang luong: \n");
	InBangLuong(L);
	char hoten[MAX];
	printf("nhap ho ten can tim: ");
	scanf("%s",hoten);
	Position t = TimKiemHoTen(hoten, L);
	if(t!= NULL){
		ElementType X = Retrieve(t);
	 	write(X);
	}else cout << "ko co";
	printf("\nds khi sap xep theo ten: \n");
	SapXepTheoLuong(L);
	InBangLuong(L);
	printf("\nliet ke theo ngay cong > 24:");
	LietKeTheoNgayCong(L);
	return 1;

}



void Makenull_List(List &L) {
	L= new Node;
	if(L==NULL) {
		cout<<"Khong du bo nho";
		return;
	}
	L->Next = NULL;
}
int IsEmpty_List(List L) {
	return L->Next==NULL;
}
int IsLast(List P) {
	return P->Next==NULL;
}
Position Locate(ElementType X, List L) {
	Position P;
	P=L->Next;
	while(P!=NULL&&strcmp(P->Element.msnv,X.msnv)!=0)
		P=P->Next;
	return P;
}
void Insert_List(ElementType X, Position P, List L) {
	Position TmpCell;
	TmpCell=new Node;
	if(TmpCell==NULL)
		cout<<"Out of space!!!";
	TmpCell->Element=X;
	TmpCell->Next=P->Next;
	P->Next=TmpCell;
}
void Delete_List(ElementType X, List L) {
	Position P, TmpCell;

	P=FindPrevious(X,L);
	if(!IsLast(P)) {
		TmpCell=P->Next;
		P->Next=TmpCell->Next;
		delete(TmpCell);
	}
}
Position FindPrevious(ElementType X, List L) {
	Position P;
	P=L;
	while(P->Next != NULL && strcmp(P->Next->Element.msnv,X.msnv)!=0)
		P=P->Next;
	return P;
}
Position Header(List L) {
	return L;
}
Position First(List L) {
	return L->Next;
}
Position Advance(Position P) {
	return P->Next;
}
ElementType Retrieve(Position P) {
	return P->Element;
}
void read(ElementType *X){
	printf("nv 1:\n");
	printf("nhap msnv: ");
	fflush(stdin);gets(X->msnv);
	printf("nhap ho ten: ");
	fflush(stdin);gets(X->hoten);
	printf("nhap he so luong: ");
	cin>>X->hesoluong;
	cout<<"nhap ngay cong: ";
	cin>>X->songaycong;
	X->luongcoban = 1150000;
}
void Read_List(List L){
	int n;
	printf("nhap n: ");scanf("%d", &n);
	Position P = Header(L);
	ElementType X;
	for(int i= 0; i < n; i++){
		read(&X);
		Insert_List(X, P, L);
	}
}
void SapXepTheoLuong(List L){
	Position P = First(L);
	while(P!= NULL){
		Position Q = L->Next;
		 while(Q != NULL){
		 	if(P->Element.luong > Q->Element.luong){
		 		ElementType tam= P->Element;
		 		P->Element = Q->Element;
		 		Q->Element = tam;
			 }
			 Q = Q->Next;
		 }
		 P=P->Next;
	}
	
}
void TinhLuong(List L){
	Position P = First(L);
	ElementType X = Retrieve(P);
	while(P != NULL){
		P -> Element.luong = P->Element.luongcoban*P->Element.hesoluong*P->Element.songaycong/26;
		P = P->Next;
	}
}
void write(ElementType X){
	printf("%s\t%s\t%.1f\t%d\t%d\n", X.msnv, X.hoten, X.hesoluong, X.songaycong, X.luong);
}
void InBangLuong(List L){
	Position P = First(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		write(X);
		P = P->Next;
	}
}
void LietKeTheoNgayCong(List L){
	Position P = First(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		if(X.songaycong > 24){
			write(X);
		}
		P = P->Next;
	}
}
Position TimKiemHoTen(const char *hoten, List L){
	Position P = First(L);
	while(P != NULL){
		ElementType X = Retrieve(P);
		int k = strcmp(hoten, X.hoten);
		if(k == 0){
			return P;
		}
		P = P-> Next;
	}
	return NULL;
}
