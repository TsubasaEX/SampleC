#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main(){
	
//	int *a=new int;
//	
//	cin>>*a;
//	cout<<*a<<endl;
//	
//	delete a;
//	
//	int *b=new int[2];
//
//	for(int i=0;i<2;i++){
//		cin>>b[i];
//	}
//	for(int i=0;i<2;i++){
//		cout<<b[i]<<endl; 
//	}
//	
//	delete[]b;
	
	int **c=new int*[3];
	printf("123ytyrtyry\n");
	
	for(int i=0;i<3;i++){
		c[i]=new int[4];
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			c[i][j]=j;
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<c[i][j];
		}
		cout<<endl;
	}
	for(int i=0;i<3;i++)
		delete[]c[i];
	delete []c;
	
	int **d=(int **)calloc(3,sizeof(int *));
	for(int i=0;i<3;i++)
		d[i]=(int *)calloc(4,sizeof(int));
		
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			d[i][j]=j;
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			cout<<d[i][j];
		}
		cout<<endl;
	}
	
	for(int i=0;i<3;i++)
		free(d[i]);
	free(d);

	
	return 0;
	
} 
