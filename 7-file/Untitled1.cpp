#include<stdio.h>
#include<stdlib.h>

struct Man{
	int id;
	char name[5];
	int age;
};

int main(){
	
	FILE *fp;
	fp=fopen("test.txt","w+");
	for(int i=0;i<5;i++){
		fprintf(fp,"%d %s %d\n",i,"ZACH",i+10);
	}
	rewind(fp);
	Man *man=(Man *)calloc(5,sizeof(Man));

	int c=0;
	while(!feof(fp) && fscanf(fp,"%d %s %d\n",&man[c].id,&man[c].name,&man[c].age)!=EOF){
		printf("%d %s %d\n",man[c].id,man[c].name,man[c].age);
		c++;
	}
	fclose(fp);

	printf("--------------------------------\n");
	FILE *fp2;
	fp2=fopen("test2.txt","w+b");
	for(int i=0;i<5;i++){
		fwrite(&man[i],sizeof(Man),1,fp2);
	}
	rewind(fp);
	Man *man2=(Man *)calloc(5,sizeof(Man));
	for(int i=0;i<5;i++){
		fread(&man2[i],sizeof(Man),1,fp2);
		printf("%d %s %d\n",man2[i].id,man2[i].name,man2[i].age);
	}

	printf("--------------------------------\n");
	
	fseek(fp2,sizeof(Man)*2,SEEK_SET);
	Man man3;
	while(!feof(fp) && fread(&man3,sizeof(Man),1,fp2)){
		printf("%d %s %d\n",man3.id,man3.name,man3.age);
	}
	fclose(fp2);
	return 0;
} 
