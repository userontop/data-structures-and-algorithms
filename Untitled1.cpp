#include<stdio.h>
int main(){
	FILE *fp;
	int i;
	fp = fopen("integer.txt", "wt");
	if(fp != NULL){
		for(i = 1;i <= 10; i++){
			fprintf(fp,"%5d", i);
		}
	}
	fclose(fp);
	return 0;
}
