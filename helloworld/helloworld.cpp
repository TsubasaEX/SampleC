#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
using namespace std;

#define MYPI 3.145
#define sum(x,y) (x)+(y)

int main(){
//	printf("hello world\n");
//	cout<<"input str:";
//	
//	char str[100];
//	cin>>str;
//	cout<<str<<endl;
//	
//	printf("input str:");
//	scanf("%s",str);
//	printf("%s\n",str);
//	
//	int in;
//	printf("input int:");
//	scanf("%d",&in);
//	printf("%d\n",in);
//	
//	const float ci = 3.2;
//	cout<<ci<<endl;
//	cout<<MYPI<<endl;
//	
//	float max = (ci>MYPI) ? ci:MYPI;
//	cout<<max<<endl;
//	
//	printf("%x\n",0x1f);
//	printf("%d\n",0x1f);
//	printf("%o\n",0x1f);
//	
//	for(int i=0;i<10;i++){
//		int f =1;
//		printf("%d\n",f<<i);
//	}
//	int a,b;
//	scanf("%d %d",&a,&b);
//	printf("%d %d\n",a,b);
//
//	int count=0;
//	printf("press any key until press return: ");
//	while(getche()!='\r')
//		count++;;
//	printf("\ncount: %d\n",count);

	printf("%d\n",sum(10,11));
	printf("%lf\n",sqrt(1.44));
	printf("%lf\n",pow(2,5));
	printf("%lf\n",log(10));
	printf("%c\n",tolower('C'));
	printf("%lf\n",atof("123.456"));
//	char *s=(char *)malloc(sizeof(char)*10);
	char *s=(char *)calloc(10,sizeof(char));
	itoa(32767,s,16);
	printf("%s\n",s);
	free(s);
	srand(time(NULL));
	for(int i=0;i<10;i++){
		int x=rand()%6+1;
		printf("%3d",x);
	}
	//	system("pause");
	return 0;
}
