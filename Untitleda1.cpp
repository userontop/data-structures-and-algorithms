#include<stdio.h>
#include<stdbool.h>


int main(){
	int a[] = {1, 3, 5, 4, 2};
	int n = 4;
	int x;
	printf("nhap vao x: ");
	scanf("%d",&x);
	bool tam = binarySearch(a, x, n);
	if(tam == 1)
		printf("\nx co trong mang A.");
		else 
			printf("\nx khong co trong mang A.");
}

int binarySearch(int a[], int x, int n)
{ int left = 0, right = n - 1, middle;
     do {
              middle = (left + right) / 2;
              if (a[middle] == x)
                       return TRUE;
             else if (x < a[middle])
                      right = middle - 1;
              else left = middle + 1;
         } while (left <= right);
     return FALSE;
}
