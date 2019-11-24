#include<iostream>
using namespace std;


struct node{
	int data;
	node *next;
}; 

node* removeAll(node *p){
	if(p==NULL){
		return NULL;
	}
	node *tmp=p->next;
	cout<<"delete :"<<p->data<<endl;
	delete p;
	return removeAll(tmp);
}

int main(){
	
	//stack
	node *head=NULL,*p;
	node *ptr;
	for(int i=0;i<10;i++){
		p=new node;
		p->data=i;
		p->next=head;
		head=p;
	}
	
	ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
	removeAll(head);	
	cout<<endl;
	
	//queue
	head=new node;
	node *tail=head;
	
	for(int i=0;i<10;i++){
		p=new node;
		p->data=i;
		p->next=NULL;
		tail->next=p;
		tail=p;
	}
	p=head;
	head=head->next;
	delete p;
	
	ptr=head;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<endl;
	removeAll(head);	
	cout<<endl;
	

	return 0;
	
	
	
}
