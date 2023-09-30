#include<stdio.h>
#define MAX 100
void nhap(int a[], int n);
void xuat(int a[], int n);


void hoanvi(int &a, int &b);
void sapXepChonTrucTiep(int a[], int n);
void sapXepChenTrucTiep(int a[], int n);
void sapXepDoiChoTrucTiep(int a[], int n);
void sapXepNoiBot(int a[], int n);


int main(){
	int n, a[MAX], k;
	printf("nhap n: ");
	scanf("%d", &n);
	nhap(a, n);
	printf("\nchuoi so: ");
	xuat(a, n);
	printf("\n1.Sap xep chon truc tiep:\n2.Sap xep chen truc tiep:\n3.Sap xep doi cho truc tiep:\n4.Sap xep noi bot:");
	printf("\n->");
	scanf("%d",&k);
	switch(k){
		case 1:{
			printf("\n1.Sap xep chon truc tiep");
			sapXepChonTrucTiep(a, n);
			printf("\nham  da sap xep");
			xuat(a, n);
			break;
		}
		case 2:{
			printf("\n2.Sap xep chen truc tiep");
			sapXepChenTrucTiep(a, n);
			printf("\nham  da sap xep");
			xuat(a, n);	
			break;
		}
		case 3:{
			printf("\n3.Sap xep doi cho truc tiep");
			sapXepDoiChoTrucTiep(a, n);
			printf("\nham  da sap xep");
			xuat(a, n);
			break;
		}
		case 4:{
			printf("\n1.Sap xep noi bot");
			sapXepNoiBot(a, n);
			printf("\nham  da sap xep");
			xuat(a, n);
			break;
		}
		default:{
			printf("\nkhong hop le.");
			break;
		}
	}	

}

void nhap(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("a[%d] : ", i);
		scanf("%d", &a[i]);
	}
}
void xuat(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%2d", a[i]);
	}
}


void hoanvi(int &a, int &b){
	int c = a;
		a = b;
		b = c;
}


void sapXepChonTrucTiep(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		int min = i;
		for (int j = i + 1; j < n; j++){
			if (a[min] > a[j])
				min = j;
			hoanvi(a[i], a[min]);
		}
	}
}

void sapXepChenTrucTiep(int a[], int n){
	int tam, j;
	for(int i = 0; i < n; i++){
		tam = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > tam){
			a[j + 1] = a[j];
			j = j - 1;
		}
	a[j + 1] = tam;
	}

}


void sapXepDoiChoTrucTiep(int a[], int n){
	for (int i = 0; i < n-1; i++){
		for (int j = i + 1; j < n;j++){
			if (a[i]>a[j])
				hoanvi(a[i], a[j]);
		}
	}
}


void sapXepNoiBot(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[j - 1])
				hoanvi(a[j], a[j - 1]);
		}
	}
}

