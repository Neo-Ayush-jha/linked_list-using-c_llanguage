#include<stdio.h>
#include<stdlib.h>
int main(){
	int *name,i,n;
	scanf("%d",&n);
	name=(int*)malloc(n*sizeof(int));
	printf("enter number of stunent = ");
	if(name == NULL){
		printf("memory not allocated\n");
	}else{
		printf("enter element of array:\n");
		for(i=0;i<n;i++){
			scanf("%d",&*(name+i));
		}
		printf("Element of array are \n");
		for(i=0;i<n;i++){
			printf("\n name = %d",*(name+i));
		}
	}
	
}
