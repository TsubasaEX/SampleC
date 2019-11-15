#include<stdio.h>

void swap(int *x,int *y){
	int r;
	r=*x;
	*x=*y;
	*y=r;
}

void selection_sort(int *a,int n){
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(&a[i],&a[j]);
	
}


void bubble_sort(int *b,int n){
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
			if(b[j]>b[j+1])
				swap(&b[j],&b[j+1]);
	
}

bool binary_search(int *a,int n,int g){
	
	int first=0,last=n;

	bool found=false;
	
	while((first<=last)&&!found){
		int mid =(first+last)/2;
		
		if(a[mid]==g)
			found=true;
		else if(a[mid]>g)
			last=mid-1;
		else
			first=mid+1;
	}
	if(found)
		printf("found\n");
	else
		printf("not found\n");
	return found;
	
}


int main(){
	int a[15]={10,20,30,222,33,1,5,3000,800,4,333,7890,19283,445,5542};
	
	int b[15]={10,20,30,222,33,1,5,3000,800,4,333,7890,19283,445,5542};
	
	selection_sort(a,15);
	
	for(int i=0;i<15;i++)
		printf("%d\n",a[i]);
	
	printf("\n");
	
	bubble_sort(b,15);	
	
	for(int i=0;i<15;i++)
		printf("%d\n",b[i]);
		
	int g=0;		
	do{
		printf("input g:");
		scanf("%d",&g);
	}
	while(!binary_search(a,15,g));
		
	return 0;
	
}
