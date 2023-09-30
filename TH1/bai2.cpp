#include<stdio.h>
#include<math.h>
#define MAX 100
void nhap(int a[], int n);
void xuat(int a[], int n);
int imax(int a[], int n);
int snt(int a[], int n);
int vT(int a[], int n);
int timMax(int a, int b);
void tim(int a[], int n, int b[], int &nb);
int main(){
	int n, a[MAX], d;
	printf("nhap n: ");
	scanf("%d", &n);
	nhap(a, n);
	printf("\nchuoi so: ");
	xuat(a, n);
	int max = imax(a, n);
	printf("\nso lon nhat = %d", max);
	int sl = snt(a, n);
	if(sl == 0)
		printf("\nkhong co snt trong mang");
	else
		printf("\nso luong so nguyen to co trong mang: %d", sl);
	int tam = vT(a, n);
	printf("\nvi tri so nguyen to xuat hien dau tien: thu %d", tam);
	int b[MAX], nb;
	tim(a, n, b, nb);
	printf("\ndai so tang dan dai nhat: ");
	xuat(b, nb);
	return 0;
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

int imax(int a[], int n){
	int max = a[0];
	for(int i = 1; i < n; i++){
		if(a[i] > max)
			max = a[i];
	}
}

int snt(int a[], int n){
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 2; j <= sqrt(n); j++){
			if(a[i] % j == 0)
				count++;
		}
	}
	return count;
}

int vT(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = 2; j <= sqrt(n); j++){
			if(a[i] % j == 0)
				return i;
		}
	}
	return -1;
}


int timMax(int a, int b){
	if(a > b)
		return a;
	else 
		return b;
}


void tim(int a[], int n, int b[], int &nb){
	nb = 0;
	int count = 0;
	int c = 0;
	b[nb] = a[0];
	for(int i = 0; i < n; i++){
		if(a[i] > a[i + 1]){
			nb++;
			b[nb] = a[i + 1];
		}
	}
	int tam;
	for(int i = nb; i <= n; i++){
		if(a[i] < a[i + 1]){
			tam = i - count;
			count++;
		}
		else{
			if(count >= nb){
				for(int j = tam; j < n; j++){
					b[c] = a[j];
					c++;
				}
			}
		}	
	}
	nb = c;
}



