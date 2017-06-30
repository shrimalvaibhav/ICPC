#include <fstream>
#include <iostream>
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

struct Queue{
	node* front;
	node* rear;
};

typedef struct Queue queue;
queue* createQueue(){
	queue* q=(queue*)malloc(sizeof(queue));
	q->front=NULL;
	q->rear=NULL;
	return q;
}

void enqueue(queue* q, int x){
	node* temp=createNode(x);
	//Can it be q->rear==NULL?
	//It should be q->rear because enqueue is done at rear
	if(q->rear==NULL){
		q->front=temp;
		q->rear=temp;
		return; 
	}
	q->rear->next=temp;
	q->rear=temp;
}

int dequeue(queue* q){
	if(q->front==NULL){
		return INT_MIN;
	}
	node* temp=q->front;
	int x=temp->data;
	q->front=temp->next;
	free(temp);
	if(q->front==NULL)
		q->rear=NULL;
	return x; 
}

int isEmpty(queue* q){
	if(q->front==NULL|| q->rear==NULL)
		return 1;
	return 0;
}

int main(){
	ifstream in;
	ofstream out;
	in.open("file1.txt");
	out.open("output.txt");
	int a;
	queue* q=createQueue();
	while(in>>a){
		//out<<"In"<<endl;
		//cout<<a<<endl;
		enqueue(q,a);
	}
	while(isEmpty(q)!=1){
	out<< dequeue(q)<<endl;
	}
	getchar();
	return 0;
}
*/