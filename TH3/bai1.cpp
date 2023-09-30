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
void lietKe(List l, ElementType x);
void sapXep(List *l);

int main(){
	List l;
	MakeNull_List(&l);
	nhapDS(&l);
	printf("\nIn DS: ");
	xuatDS(l);
	ElementType x;
	printf("\nnhap x:");
	nhap(&x);
	lietKe(l, x);
	sapXep(&l);
	printf("\nsap xep danh sach: ");
	xuatDS(l);
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
void lietKe(List l, ElementType x){
	int count = 0;
	for(Position p = 0; p < l.Last; p++){
		if(l.Elements[p] == x){
			printf("\nvi tri xuat hien %2d", p + 1);
			count++;
		}
	}	
	printf("\nX xuat hien %d lan.", count);
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
