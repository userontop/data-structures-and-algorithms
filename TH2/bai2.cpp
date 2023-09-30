#include<time.h>
#include<assert.h>
#include<stdio.h>
#define MAX 100000
void nhap(int a[], int n);
void xuat(int a[], int n);
void hoanvi(int &a, int &b);
void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void InterchangeSort(int a[], int n);
void BubbleSort(int a[], int n);
void QuickSort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, 	int r);
void shift(int a[], int l, int r);
void creatcheap(int a[], int n);
void heapSort(int a[], int n);
void ShellSort(int a[], int n, int h[], int k);
int randint(int max);
void createrandomarray(int a[], int n, int maximum);

int main(){
	int a[MAX];
	int n = 100000;
	int h[] = {5 , 3, 1}, k = 3;
	int t;
	createrandomarray(a, n, 1000);
	printf("\n1.sx chon truc tiep\n2.sx chen truc tiep\n3.sx doi cho truc tiep\n4.sx noi bot\n5.sx merge sort\n6.sx quick sort\n7.sx heap sort\n8.sx shell sort");
	printf("\n-> ");
	scanf("%d", &t);
	clock_t start = clock();
	switch(t){
		case 1 :{
			SelectionSort(a, n);
			break;
		}
		case 2 :{
			InsertionSort(a, n);
			break;
		}
		case 3 :{
			InsertionSort(a, n);
			break;
		}
		case 4 :{
			BubbleSort(a, n);
			break;
		}
		case 5 :{
			QuickSort(a, 0, n - 1);
			break;
		}
		case 6 :{
			mergeSort(a, 0, n - 1);
			break;
		}
		case 7 :{
			heapSort(a, n);	
			break;
		}
		case 8 :{
			ShellSort(a, n, h, k);
			break;
		}
	}
	clock_t end = clock();
	double c = (double)(end-start)/CLOCKS_PER_SEC;
	printf("\n thoi gian chay(s): %.3f", c);
	return 0;
}

int randint(int max) {
 if ((max - 1) == RAND_MAX) {
   return rand();
  } else {
   long end = RAND_MAX / max;
   assert (end > 0L);
   end *= max;
   int r;
   while ((r= rand()) >= end);
   return r % max;
   }
}


void createrandomarray(int a[], int n, int maximum){
   for (int i = 0; i < n; i++){
       a[i]=randint(maximum);
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


void SelectionSort(int a[], int n){
	for (int i = 0; i < n - 1; i++){
		int min = i;
		for (int j = i + 1; j < n; j++){
			if (a[min] > a[j])
				min = j;
			hoanvi(a[i], a[min]);
		}
	}
}

void InsertionSort(int a[], int n){
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


void InterchangeSort(int a[], int n){
	for (int i = 0; i < n-1; i++){
		for (int j = i + 1; j < n;j++){
			if (a[i]>a[j])
				hoanvi(a[i], a[j]);
		}
	}
}


void BubbleSort(int a[], int n){
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j > i; j--){
			if(a[j] < a[j - 1])
				hoanvi(a[j], a[j - 1]);
		}
	}
}


int timP(int a[], int l, int r){//tim chot
       int pivot = a[r];  
        int i = (l-1); 
        for (int j=l; j< r; j++) { 
            if (a[j] < pivot) { 
                i++; 
  

                int temp = a[i]; 
                a[i] = a[j]; 
                a[j] = temp; 
            } 
        } 
        int temp = a[i+1]; 
        a[i+1] = a[r]; 
        a[r] = temp;  
        return i+1; 
}


void QuickSort(int a[], int l, int r){
	if(l < r){
		int tam = timP(a, l ,r);
       	QuickSort( a, l, tam - 1);
       	QuickSort(a, tam + 1, r);
	}
}
 

void merge(int a[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
 
 
    while (j < n2){
        a[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int a[], int l, int r){
    if (l < r){
        int m = l+(r-l)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, r);
        merge(a, l, m, r);
    }
}


void shift(int a[], int l, int r){
	int x, i, j;
	i = l;
	j = 2*i +1;
	x = a[i];
	while(j <= r){
		if(j < r)
			if(a[j] < a[j + 1])
				j++;
		if(a[j] < x) return;
		else {
			a[i] = a[j];
			i = j;
			j = 2 * i + 1;
			a[i] = x;
		}
	}
}


void creatcheap(int a[], int n){
	int l;
	l = (n - 1)/2;
	while(l >= 0){
		shift(a, l, n - 1);
		l = l -1;
	}
}


void heapSort(int a[], int n){
	int r;
	creatcheap(a,n);
	r = n - 1;
	while(r > 0){
		hoanvi(a[0],a[r]);
		r = r -1;
		shift(a,0,r);
	}
}


void ShellSort(int a[], int n, int h[], int k){
	int step, i, j;
	int x, len;
	for(step = 0; step < k; step++){
		len = h[step];
		for(i = len; i < n; i++){
			x = a[i];
			j = i - len;
			while((x < a[j]) && (j >= 0)){
				a[j + len] = a[j];
				j = j - len;
			}
			a[j + len] = x;
		}
	}
}
