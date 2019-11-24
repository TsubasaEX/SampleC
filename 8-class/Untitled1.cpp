#include<iostream>
using namespace std;

class Complex{
	public:
		Complex();
		Complex(int r,int i);
		Complex(const Complex &); //copy constructor
		Complex operator+(const Complex&);
		Complex operator-(const Complex&);
	 	void operator+=(const Complex&);
	 	void operator-=(const Complex&);
		void print();
		void set(int r,int i);
		bool operator==(const Complex&);
		~Complex(){
			cout<<"destructor"<<endl;
		}
		void printSI(){
			cout<<"si : "<<si<<endl;
		}
		static void printsSI(){
			cout<<"si : "<<si<<endl;
//			cout<<"real : "<<real<<endl;//error
		}
		static int psi;
	private:
		static int si;
		int real;
		int image;
};

int Complex::si=100;
int Complex::psi=200;

Complex::Complex(){
	real=0;
	image=0;
}

Complex::Complex(int r,int i){
	real=r;
	image=i;
}

Complex::Complex(const Complex &c){
	cout<<"copy constructor!!"<<endl;
	real=c.real;
	image=c.image;
}

Complex Complex::operator+(const Complex&c){
	Complex x;
	x.real=real+c.real;
	x.image=image+c.image;
	return x;
}

Complex Complex::operator-(const Complex&c){
	Complex x;
	x.real=real-c.real;
	x.image=image-c.image;
	return x;
}

void Complex::operator+=(const Complex&c){
	real+=c.real;
	image+=c.image;
}

void Complex::operator-=(const Complex&c){
	real-=c.real;
	image-=c.image;
}

bool Complex::operator==(const Complex&c){
	if(real==c.real && image==c.image){
		return true;
	}
	return false;
}

void Complex::print(){
	cout<<real<<" "<<image<<endl;
}

void Complex::set(int r,int i){
	real=r;
	image=i;
}


int main(){
	
	Complex c1;
	Complex c2(5,10);
	Complex c3;
	c1.print();
	c2.print();
	
	c3=c1+c2;
	c3.print();
	
	c2+=c3;
	c2.print();
	
	c3-=c2;
	c3.print();
	
	c3.set(11,22);
	c3.print();
	if(c3==c1){
		cout<<"equal"<<endl;
	}else{
		cout<<"unequal"<<endl;
	}
	
	c1=c3;
	c1.print();
	if(c3==c1){
		cout<<"equal"<<endl;
	}else{
		cout<<"unequal"<<endl;
	}
	
	Complex c4=c1;
	Complex c5(c1);
	
	c5.printSI();
	c5.printsSI();
	cout<<"psi : "<<c5.psi<<endl;
	return 0;
}
