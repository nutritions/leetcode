#include<stdio.h>

int main(){
	int a[10]={0};
	for(int i=0;i<10;i++){
		printf("%d ",a[i]); 
	}
	printf("\n");
	int i=0;
	printf("%d\n",i-1); 
	printf("%d\n",a[i-1]);
	i=13;
	printf("%d\n",i+1); 
	printf("%d\n",a[i+1]);
	for(int i=0;i<10&&a[i-1]==0;i++){
		printf("%d ",i); 
	}
	return 0; 
} 