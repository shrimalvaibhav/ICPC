#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

/*
struct Node{
	int data;
	struct Node* next;
};
typedef struct Node node;

node* createNode(int x){
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	return temp;
}

struct Stack{
	node* top;
};
typedef struct Stack stack;

stack* createStack(){
	stack* s=(stack*)malloc(sizeof(stack));
	s->top=NULL;
	return s;
}

void push(stack* s, int x){
	node* temp=createNode(x);
	temp->next=s->top;
	s->top=temp;
}

int pop(stack* s){
	node* temp=s->top;
	int x=temp->data;
	s->top=temp->next;
	free(temp);
	return x;
}

int isEmpty(stack* s){
	if(s->top==NULL)
		return 1;
	return 0;
}



int main(){
	ifstream in;
	ofstream out;
	in.open("file1.txt");
	out.open("output.txt");

	int a;
	stack* s=createStack();
	//in>>a;
	//out<<a;
	//out<<a;
	
	//int i=0;
	while(in>>a){
		//out<<"In"<<endl;
		push(s,a);
	}
	
	while(isEmpty(s)!=1){
		out<< pop(s)<<endl;
	}
	
	//getchar();



	return 0;
}
*/