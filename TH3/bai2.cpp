#include<stdio.h>
#define MaxLength 100  
typedef int ElementType;  
typedef int Position; 
typedef struct 
{ 
	ElementType Elements[MaxLength]; 
	Position Last; 
} List;
void MakeNull_List(List *L);
void Insert_List(ElementType X, Position P, List *L);
void nhap(ElementType *x);
void nhapDS(List *l);
void xuat(ElementType x);
void xuatDS(List L);
void sapXep(List *l);
void tronDs(List l, List m, List *t);
int main(){
	List l;
	MakeNull_List(&l);
	nhapDS(&l);
	List m;
	MakeNull_List(&m);
	nhapDS(&m);
	printf("\nIn DS 1: ");
	xuatDS(l);
	printf("\nIn DS 2: ");
	xuatDS(m);
	sapXep(&l);
	printf("\nsap xep danh sach 1: ");
	xuatDS(l);
	sapXep(&m);
	printf("\nsap xep danh sach 2: ");
	xuatDS(m);
	printf("\ntron 2 danh sach va sap xep.");
	List t;
	tronDs(l, m, &t);
	xuatDS(t);
}
void MakeNull_List(List *L)
{
	L->Last=0;
}


void Insert_List(ElementType X, Position P, List *L)
{ 	
	if (L->Last==MaxLength) 
		printf("Danh sach day"); 
	else if (P<0 || P>L->Last) 
		printf("Vi tri khong hop le"); 
	else
	{ 	Position Q;
		for(Q=L->Last;Q>P-1;Q--)	{
			L->Elements[Q]=L->Elements[Q-1]; 
		}
		L->Elements[P]=X; //?ua x v?o vi tr? p 
		L->Last++; //Tang do d?i danh s?ch l?n 1 
	} 
}


void nhap(ElementType *x){
	scanf("%d", x);
}
void nhapDS(List *l){
	int n;
	printf("nhap n: ");
	scanf("%d", &n);
	ElementType x;
	for(int i = 0; i < n; i++){
		printf("pt %d: ", i + 1);
		nhap(&x);
		Insert_List(x, l->Last,l);
	}
}
void xuat(ElementType x){
	printf("%2d", x);
}
void xuatDS(List L){
	for(Position p = 0; p < L.Last; p++){
		xuat(L.Elements[p]);
	}
}

void sapXep(List *l){
	ElementType tam;
	for(Position p = 0; p < l->Last - 1; p++){
		for(Position q = 0; q < l->Last; q++){
			if(l->Elements[p] > l->Elements[q]){
				tam = l->Elements[p];
				l->Elements[p] = l->Elements[q];
				l->Elements[q] = tam;
			}
		}
	}
}

void tronDs(List l, List m, List *t){
	int n = 0;
	int k = 0;
	for(Position p = k; p < l.Last; p++){
		for(Position q = n; q < m.Last; q++){
			if(l.Elements[p] < m.Elements[q]){
				Insert_List(l.Elements[p], t->Last,t);
				k++;
				break;
			}else{
				Insert_List(m.Elements[q], t->Last,t);
				n++;
			}
		}
	}
	
	for(Position p = k; p < l.Last; p++){
		Insert_List(l.Elements[p], t->Last,t);
	}
	for(Position q = n; q < m.Last; q++){
		Insert_List(m.Elements[q], t->Last,t);
	}
}
