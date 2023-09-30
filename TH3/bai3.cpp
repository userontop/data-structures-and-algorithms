#include<stdio.h>
#define MaxLength 100  
struct  sinhVien{
	char mssv[MaxLength], ten[MaxLength];
	float diem;
};
typedef sinhVien ElementType;  
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

int main(){
	List l;
	MakeNull_List(&l);
	nhapDS(&l);
	printf("\nIn:\n");
	xuatDS(l);
	sapXep(&l);
	printf("\nsap xep sv theo diem:\n");
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
		L->Elements[P]=X;
		L->Last++;
	} 
}


void nhap(ElementType *x){
	printf("Mssv: ");fflush(stdin);scanf("%s", x->mssv);
	printf("ten: ");fflush(stdin);gets(x->ten);
	printf("diem: ");fflush(stdin);scanf("%f", &x->diem);
}


void nhapDS(List *l){
	int n;
	printf("nhap n: ");
	scanf("%d", &n);
	ElementType x;
	for(int i = 0; i < n; i++){
		printf("sv %d: \n", i + 1);
		nhap(&x);
		Insert_List(x, l->Last,l);
	}
}
void xuat(ElementType x){
	printf("%s\t%s\t%f\n", x.mssv, x.ten, x.diem);
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
			if(l->Elements[p].diem > l->Elements[q].diem){
				tam = l->Elements[p];
				l->Elements[p] = l->Elements[q];
				l->Elements[q] = tam;
			}
		}
	}
}

