#include<stdio.h>
#include<String.h>
#define MAX 100
struct hocsinh{
	char Mssv[MAX];
	char hoTen[MAX];
	float diem;
	char xeploai[MAX];
};

typedef hocsinh Elementype;
struct Node{
	Elementype Element;
	Node *next;
};
typedef Node* PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;
Position Header(List l);
void nhapNode(Elementype &x);
void nhapDs(List L, int n);
void makeNull_List(List &L);
void insertList(Elementype x, Position p, List l);
void xepLoai(List &l);
void xuatNode(Elementype x);
void xuatDs(List L);
int dem(List L);
float diemMax(List L);
float diemTB(List L);
void inds(List L);
void sapxep(List L);
Elementype gTri(List L);
void tach(List L, List L1, List L2);
int main(){
	List ds;
	int n;
	printf("nhap vao so luong hoc sinh: ");
	scanf("%d", &n);
	makeNull_List(ds);
	nhapDs(ds, n);
	xepLoai(ds);
	xuatDs(ds);
	printf("\nco %d hoc sinh co diem cao nhat = %f\n", dem(ds), diemMax(ds));
	printf("\ncac hoc sinh co diem lon hon dtb chung: \n");
	inds(ds);
	printf("\nsap xep: \n");
	sapxep(ds);
	printf("\ntach:");
	List L1, L2;
	makeNull_List(L1);
	makeNull_List(L2);
	tach(ds, L1, L2);
	printf("\nham1: \n");
	xuatDs(L1);
	printf("\nham2: \n");
	xuatDs(L2);
	return 0;
}
Position Header(List l){
	return l;
}

Elementype gTri(Position P){
	return P -> Element;
}
void nhapNode(Elementype &x){
	printf("\nhoTen: ");
	scanf("%s", &x.hoTen);
	printf("Mssv: ");
	scanf("%s", &x.Mssv);
	printf("diem: ");
	scanf("%f", &x.diem);
}


void nhapDs(List L, int n){
	Position p = Header(L);
	Elementype x;
	for(int i = 0; i< n; i++){
		printf("nhap hs thu %d: ", i + 1);
		nhapNode(x);
		insertList(x, p, L);
	}
}

void xuatNode(Elementype x){
	printf("\nHo va Ten: %s", x.hoTen);
	printf("\nMSSV: %s", x.Mssv);
	printf("\nDiem Thi: %.2f", x.diem);
	printf("\nXep Loai: %s", x.xeploai);
}
void xuatDs(List L){
	Position P = Header(L) -> next;
	Elementype x;
	while(P != NULL){
		printf("\nHoc sinh: ");
		Elementype x = gTri(P);
		xuatNode(x);
		P = P -> next;
	}
}


void makeNull_List(List &L){
	L = new Node;
	L -> next = NULL;	
}


void insertList(Elementype x, Position p, List l){
	Position tmp;
	tmp = new Node;
	if(tmp == NULL)
		printf("\n danh sach rong.");
	else{
		tmp -> Element = x;
		tmp -> next = p -> next;
		p -> next = tmp;
	}
}


void xepLoai(List &l){
	Position P = Header(l) -> next;	
	while(P != NULL){
		if(P -> Element.diem >= 5)
			strcpy(P -> Element.xeploai, "TT");
		else
			strcpy(P -> Element.xeploai, "KT");
		P = P -> next;
	}
}


float diemMax(List L){
	Position P = Header(L) -> next;
	float iMax = 0;
	while(P != NULL){
	Elementype x = gTri(P);
		if(iMax < x.diem)
			iMax = x.diem;
	P = P -> next;
	}
	return iMax;
}

int dem(List L){
	int count = 0;
	Position P = L -> next;
	while(P != 	NULL){
		Elementype x = gTri(P);
		if(x.diem == diemMax(L)){
			count++;
		}
		P = P->next;
	}
	return count;
}


float diemTB(List L){
	int Tong = 0;
	int count = 0;
	Position P = L->next;
	while(P != NULL){
		Elementype x = gTri(P);
		Tong += x.diem;
		count++;
		P = P->next;
	}
	return (float)Tong / count;
}

void inds(List L){
	Position p = Header(L) -> next;
	while(p != NULL){
		Elementype x = gTri(p);
		if(x.diem > diemTB(L)){
			xuatNode(x);
		}
		p = p->next;
	}
}

void sapxep(List L){
	Position p = Header(L) -> next;
	while(p != NULL){
		Position Q = p-> next;
		while(Q != NULL){
			if(strcmp(p -> Element.Mssv, Q->Element.Mssv)>0){
				Elementype T = p -> Element;
				p -> Element = Q->Element;
				Q->Element = T;
			}
			Q=Q->next;
		}
		p = p->next;
	}
}

void tach(List L, List L1, List L2){
	Position p = Header(L) -> next;
	Position p1 = Header(L1);
	Position p2 = Header(L2);
	while(p != NULL){
		Elementype x = gTri(p);
		if(strcmp(x.xeploai,"TT")==0){
			insertList(x,p1,L1);
		}
		else{
			insertList(x, p2, L2);
		}
		p = p->next;
	}	
}
