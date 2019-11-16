#include<string.h>
#include<stdio.h>

struct Man{
	char name[10];
	int age;
};

struct Girl{
	char name[10];
	int age;
};

union Teacher{
	char name[10];
	int age;
};

double sum(double a, double b){
	return a+b;
}

int main(){
	
	char *s1="abcdef";
	char *s4="ABCDEF";
	char *s2= new char[5];
	char *s3=new char[5];
	printf("%s\n",s1); 
	scanf("%s",s2);
	printf("%s\n",s2); 
	strncpy(s3,s2,2);
	s3[2]='\0';
	printf("%s\n",s3); 
	
	if(!stricmp(s1,s4)){
		printf("same\n");
	}
	char *s5=strchr(s1,'d');
	printf("%s\n",s5);
	
	char *s6=strstr(s1,"cd");
	printf("%s\n",s6);
	
	delete []s2;
	delete []s3;
	Man man;
	man.age=20;
	strcpy(man.name,"zach");
	printf("len:%d %s %d\n",strlen(man.name),man.name,man.age);
	
	char *s7;
	strcpy(s7,"Zach,is,pretty#fucking^Cute !");
	
	char *par=strtok(s7,",#^ ");
	while(par!=NULL){
		printf("%s ",par);
		par=strtok(NULL,",#^ ");
	}
	printf("\n");
	double (*dp)(double,double);
	dp=sum;
	printf("%lf\n",(*dp)(1.1,2.2));
	
	Girl girl={"Amy",15};
	printf("%s %d\n",girl.name,girl.age);
	
	Teacher te;
	strcpy(te.name,"Ashley");
	printf("%s\n",te.name);
	te.age=35;
	printf("%d\n",te.age);
	
}
