#include<stdio.h>
#include<string.h>
#define MAX 100
struct HangHoa{
	char ms[32];
	int namsx;
	float gia;
	float km;
};
typedef HangHoa ElementType;
struct Node{
	ElementType Element;
	Node *Next;
};
typedef Node *PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

void MakeNull_List(List &L);
Position Header(List L);
ElementType Retrieve(Position P);
void Insert_List(ElementType X,Position P, List L);

void nhap(ElementType &X);
float tinhKhuyenMai(ElementType &X);
void nhapDS(List L, int n);
float tinhKhuyenMai(ElementType &X);
void xuat(ElementType X);
void xuatDS(List L);
void inHH(List L,float g);
float TMax(List L);
void inKM(List L);


void MakeNull_List(List &L){
	L= new Node;
	L->Next=NULL;
}	
Position Header(List L){
	return L;
}	
ElementType Retrieve(Position P){
	return P->Element;
}	
void Insert_List(ElementType X,Position P, List L){
	Position TmpCell;
	TmpCell = new Node;
	if(TmpCell == NULL){
		printf("Bo nho day!");
	}
	else{
		TmpCell->Element=X;
		TmpCell ->Next= P->Next;
		P->Next= TmpCell;
	}
		
}	

void nhap(ElementType &X){
	printf("\nNhap ma so: ");fflush(stdin);gets(X.ms);
	printf("Nhap nam san xuat: ");scanf("%d",&X.namsx);
	printf("Nhap gia: ");scanf("%f",&X.gia);
	tinhKhuyenMai(X);
}	
float tinhKhuyenMai(ElementType &X){
	X.km=X.gia*5/100;
	return X.km;
}
void nhapDS(List L, int n){
	ElementType X;
	Position P= Header(L);
	for(int i=0;i<n;i++){
		printf("Hang hoa thu: %d",i+1);
		nhap(X);
		Insert_List(X,P,L);
	}	
}	
	
void xuat(ElementType X){
	printf("\nma so: %s",X.ms);
	printf("\tnam san xuat: %d",X.namsx);
	printf("\tgia: %.2f",X.gia);
	printf("\tkhuyenmai: %.2f",X.km);
}	
void xuatDS(List L){
	int i=0;
	for(Position P= Header(L)->Next;P!=NULL;P=P->Next){
		xuat(P->Element);
	}	
}	
void inHH(List L, float g){
	int d=0;
	for(Position P= Header(L)->Next;P!=NULL;P=P->Next){
		ElementType X = Retrieve(P);
		if(X.gia<g){
			xuat(X);
			d++;
		}	
	}
	if(d==0){
		printf("Khong co!");
	}	
}
float TMax(List L){
	Position P = L->Next;
	ElementType X = P->Element;
	float max = X.km;
	for(P->Next;P!=NULL;P=P->Next){
		X = P->Element;
		if(max<X.km){
			max=X.km;
		}	
	}
	return max;	
	
}	
void inKM(List L){
	float max =TMax(L);
	for(Position P= Header(L)->Next;P!=NULL;P=P->Next){
		ElementType X = Retrieve(P);
		if(X.km==max){
			xuat(X);
		}
	}	
			
}
	

int main(){
	List L;
	MakeNull_List(L);
	int n;
	printf("Nhap so luong hang hoa: ");
	scanf("%d",&n);
	
	nhapDS(L,n);
	printf("Danh sach vua nhap la: ");
	xuatDS(L);
	
	printf("\n-----------------------------");
	float g;
	printf("\nNhap gia nho hon: ");
	scanf("%f",&g);
	printf("\nHH co gia it hon gia ntbp: ");
	inHH(L,g);
	
	printf("\n-----------------------------");
	printf("\nIn km lon nhat: ");
	inKM(L);
	
	
	return 0;
}

