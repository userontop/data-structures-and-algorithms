#include<stdio.h>
#define MAX 100
void nhap(int a[], int n);
void xuat(int a[], int n);

int timKiemTT(int a[], int n, int d);
void hoanvi(int &a, int &b);
void sapXep(int a[], int n);
int timKiemNP(int a[], int n, int d);

int main(){
	int n, a[MAX], d;
	printf("nhap n: ");
	scanf("%d", &n);
	nhap(a, n);
	printf("\nchuoi so: ");
	xuat(a, n);
	printf("\nnhap so can tim: ");
	scanf("%d", &d);
	int tam = timKiemTT(a, n, d);
	if(tam == -1)
		printf("\nso can tim khong co trong chuoi a[]");
	else 
		printf("\n%d co trong chuoi o vi tri a[%d]", d, tam);
	sapXep(a, n);
	printf("\nham sap xep: ");
	xuat(a, n);
	tam = timKiemNP(a, n, d);
	if(tam == -1)
		printf("\nso can tim khong co trong chuoi a[]");
	else 
		printf("\n%d co trong chuoi o vi tri a[%d]", d, tam);
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


int timKiemTT(int a[], int n, int d){
	for(int i = 0; i < n; i++){
		if(a[i] == d)
			return i;
	}
		return -1;
}

void hoanvi(int &a, int &b){
	int c = a;	
		a = b;
		b = c;
}


void sapXep(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[i] > a[j])
				hoanvi(a[i], a[j]);	
		}
	}
}

int timKiemNP(int a[], int n, int d){
	int mid, tr = 0, ph = n - 1;
	while(0 <= n - 1){
		mid = (tr + ph) / 2;
		if(a[mid] == d)
			return mid;
		if(d > a[mid])
			tr = mid + 1;	
		else
			ph = mid - 1;
	}
	return mid = -1;
}
