#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int fib(int n){
	if(n<=2)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}

void print(int *x,int n){
	
	for(int i=0;i<n;i++){
		printf("%d\n",x[i]);
	}
}

int main(){

	int x[5];
	int *y=(int*)calloc(5,sizeof(int));
	int *z = new int[5]	;
//	printf("%d\n",sizeof(x)/sizeof(int));
	for(int i=0;i<sizeof(x)/sizeof(int);i++){
		scanf("%d",&x[i]);
	}
	
	print(x,sizeof(x)/sizeof(int));
	
	char *s="string";
	printf("%s %d\n",s,strlen(s));
	
	free(y);
	delete []z;
//	printf("%lf\n",1e-5);
//	
//	for(int i=0;i<10;i++){
//		printf("%d\n",fib(i));
//	}
	return 0;
} 
