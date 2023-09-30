#include<stdio.h>
#include <stdlib.h>
#define MAX 100
struct ABS{
	int Key;
	char value[];
};
void nhap(ABS *a[], int n);
void xuat(ABS *a[], int n);

int main(){
	int n;
	ABS *P;
	printf("nhap n:");
	scanf("%d", &n);
	P = new ABS[n];
	nhap(&P, n);
	printf("\nXuat: ");
	xuat(&P,n);
	delete(P);
}

void nhap(ABS *a[], int n){
	for(int i = 0; i < n; i++){
		printf("\nmang %d", i+1);
		printf("\nkey = ");
		scanf("%d", &a[i]->Key);
		printf("chuoi ky tu: ");
		scanf("%s", &a[i]->value);
	}
}
void xuat(ABS *a[], int n){
	for(int i = 0; i < n; i++){
		printf("\nABS %d:", i+1);
		printf("\nKey: %d", a[i]->Key);
		printf("\nValue: %s", a[i]->value);
	}
}


