#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<typeinfo>
//#include<ostream> 
using namespace std;

namespace myspace{
	int myi;
	double myd;
}

class Department
{
	public:
		Department(){
			dname=(char *)malloc(strlen("dep")+1);
			strcpy(dname,"dep");
		}
		Department(char *str){
			dname=(char *)malloc(strlen(str)+1);
			strcpy(dname,str);
		}
		virtual ~Department(){
			if(dname!=NULL){
				free(dname);
			}
		}
		char *dname;
};

class Basic{
	public:
		virtual int getPay()=0;
};

class Employee:public Basic{
	public:
		Employee(){
			boss=(char *)malloc(strlen("boss")+1);
			strcpy(boss,"boss");
		}
		Employee(char *str,Department dp){
			boss=(char *)malloc(strlen(str)+1);
			strcpy(boss,str);
			dep=dp;
		}
		~Employee(){
			if(boss!=NULL){
				free(boss);
			}
		}
		char * getBoss();
		int getPay(){
			return 200;
		}
		Department getDepartment();
	private:
		char *boss;
		Department dep;
};

class Worker: public Employee{
	public:
		Worker(){
		}
		Worker(int yr,char *boss,Department dep):Employee(boss,dep){
			year = yr;
		}
		~Worker(){
		}
		int getPay(){
			return 100;
		}
	protected:
		int year;
};

class Man: public Worker{
	public:
		Man(){
			name=NULL;
		}
		Man(char *str,int yr,char *boss,Department dep);
		friend ostream& operator<<(ostream& ost, Man& man);
		friend istream& operator>>(istream& ist,Man& man);
		~Man(){
			if(name!=NULL){
				free(name);
			}
		}
		int getPay(){
			return 10;
		}
	private:
		char *name;
};

template <class t1,class t2>
class TempClass{
	public:
		t1 a;
		t2 b;
		TempClass();
		TempClass(t1 i,t2 j);
};

char* Employee::getBoss(){
	return boss;
}

Department Employee::getDepartment(){
	return dep;
}

Man::Man(char *str,int yr,char *boss,Department dep):Worker(yr,boss,dep){
	name=(char *)malloc(strlen(str)+1);
	strcpy(name,str);
}

ostream& operator<<(ostream& ost, Man& man){
			ost<<man.name<<endl;
				ost<<man.year<<endl;
					ost<<man.getBoss()<<endl;
						ost<<man.getDepartment().dname<<endl;
			return ost;
}

istream& operator>>(istream& ist, Man& man){
		char str[10];
		cout<<"input name"<<endl;
		ist>>str;
		man.name=new char[strlen(str)+1];
		strcpy(man.name,str);
		return ist;
}

template <class t1,class t2>
TempClass<t1,t2>::TempClass(){
	a=55.5;
	b=66;
}

template <class t1,class t2>
TempClass<t1,t2>::TempClass(t1 i, t2 j){
	a=i;
	b=j;
}

template<class t1>
t1 sum(t1 a,t1 b){
	return a+b;
}

int main(){
	
	Department dep("ABC");
	Man man("Zach",10,"Alita",dep);
	cout<<man;
	
	Basic *b;
	Worker worker;
	Employee emp;
	b=&man;
	cout<<b->getPay()<<endl;
	b=&worker;
	cout<<b->getPay()<<endl;
	b=&emp;
	cout<<b->getPay()<<endl;
	
	b=&worker;
	Worker *wp=dynamic_cast<Worker *>(b);
	if(wp){
			cout<<wp->getPay()<<endl;
	}else{
		cout<<"cast error"<<endl;
	}
	
	Man man2;
	cin>>man2;
	cout<<man2;
	cout<<"--------------------------------"<<endl;
	
	TempClass<int, double> tc(10,11.11);
	TempClass<double,float> tc2;
	cout<<tc.a<<endl;
	cout<<tc.b<<endl;
	cout<<tc2.a<<endl;
	cout<<tc2.b<<endl;	
	if(typeid(tc.b)==typeid(float)){
		cout<<"float"<<endl;
	}else if(typeid(tc.b)==typeid(double)){
		cout<<"double"<<endl;
	}
	if(typeid(tc2.b)==typeid(float)){
		cout<<"float"<<endl;
	}else if(typeid(tc2.b)==typeid(double)){
		cout<<"double"<<endl;
	}
	
	myspace::myi=10;
	myspace::myd=20.2;
	cout<<myspace::myi<<endl;
	cout<<myspace::myd<<endl;

	using namespace myspace;
	cout<<myi<<endl;
	cout<<myd<<endl;
	
	cout<<sum(1,10)<<endl;
	cout<<sum(1.1,2.2)<<endl;
//	cout<<sum(1.1,10)<<endl;//error
	return 0;
	
}
 
