#include<stdio.h>
#define MAX 100
int timKiemTuanTu_LiearSearch(int a[], int n, int x);
int timKiemNhiPhan_binarySearch(int a[], int n, int x);//dã sap xep
void sapXepChonTrucTiep_SelectionSort(int a[], int n);// hoan vi
void hoanvi(int *a, int *b);
void chenTrucTiep_InsertionSort();// dã sap xep







int timKiemTuanTu_LinearSearch(int a[], int n, int x){
	for(int i = 0; i < n; i ++){
		if(a[i] = x)
			return i;
	}
	return -1;
}

int timKiemNhiPhan_binarySearch(int a[], int n, int x){
	int left = 1, right = n, mid = (left + right) / 2;
	do{
		if(a[mid] == x)
			return mid;
		else if(a[mid] > x)	left = mid++;
		else right = mid--;	
	}while(left <= right);
	return -1;
}

void hoanvi(int *a, int *b){
	int c = *a;
		*a = *b;
		*b = c;
}

void sapXepChonTrucTiep_SelectionSort(int a[], int n){
	int k;
	for(int i = 0; i < n - 1; i++){
		k = i;
		for(int j = i - 1; j < n; j++){
			if(a[k] > a[j])
				k = j;
		}
			hoanvi(a[k], a[i]);
	}
}

