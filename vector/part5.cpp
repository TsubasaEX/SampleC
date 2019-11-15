#include<iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;


int main(){
	
	vector<int> vint;
	
	srand(time(NULL));
	for(int i=0;i<10;i++)
		vint.push_back(rand()%100+1);
	
		
	for(int i=0;i<vint.size();i++)
		cout<<vint[i]<<endl;
	
	cout<<"-------"<<endl;
	sort(vint.begin(),vint.end());
	for(int i=0;i<vint.size();i++)
		cout<<vint[i]<<endl;
	cout<<"-------"<<endl;
	sort(vint.begin(), vint.end(), greater<int>());
	for(int i=0;i<vint.size();i++)
		cout<<vint[i]<<endl;	
	cout<<"-------"<<endl;
	vint.erase(vint.begin()+2);
	vint.insert(vint.begin()+2,777);
	
	for(int i=0;i<vint.size();i++)
		cout<<vint[i]<<endl;
//	
	vector<string> stringVec;
	stringVec.push_back("John");
	stringVec.push_back("Bob");
	stringVec.push_back("Joe");
	stringVec.push_back("Zack");
	stringVec.push_back("Randy");	
	sort(stringVec.begin(), stringVec.end());

    for (int i=0;i<stringVec.size();i++)
       cout << stringVec[i] << " ";
    cout<<endl<<"-------"<<endl; 
    sort(stringVec.begin(), stringVec.end(),greater<string>());

    for (int i=0;i<stringVec.size();i++)
       cout << stringVec[i] << " ";
	return 0;
}
