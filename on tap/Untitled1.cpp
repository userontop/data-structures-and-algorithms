#include<stdio.h>
int main(){
	for(int i = 1000; i < 2000;i++)
		for(int j = 2000; j < 3000; j++)
			for(int k = 3000; k < 4000;k++)
				for(int g = 4000; g < 5000; g++){				
					printf("\nPress %d%d%d%d for 0 seconds Pause 1 Milliseconds",i,j,k,g);
				}
}
