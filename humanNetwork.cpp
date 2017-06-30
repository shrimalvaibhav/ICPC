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
	if(q->rear==NULL){
		q->front=temp;
		q->rear=temp;
		return;
	}
	q->rear->next = temp;
	q->rear=temp;
}

int dequeue(queue* q){
	if(q->front==NULL) return INT_MIN;
	node* temp=q->front;
	int x=temp->data;
	q->front=temp->next;
	if(q->front==NULL) q->rear=NULL;
	free(temp);
	return x;
}

int isEmpty(queue* q){
	if(q->front==NULL) return 1;
	return 0;
}

int graph[1001][1001];
int visited[1001];
int cc[1001];
ifstream in;
ofstream out;

void print(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//out<<graph[i][j]<<" ";
		}
		//out<<endl;
	}
}
int dist=INT_MIN;
void bfsUtil(int source, int n, int os){
	queue* q=createQueue();
	enqueue(q,source);
	enqueue(q,0);
	visited[source]=1;
	while(isEmpty(q)!=1){
		int x=dequeue(q);
		int level=dequeue(q);
		out<<"Source is "<<x<<endl; 
		for(int i=0;i<n;i++){
			out<<"Checking for "<<i<<endl;
			if(graph[x][i]==1 && visited[i]!=1){
				enqueue(q,i);
				enqueue(q,level+1);
				visited[i]=1;
				cc[os]=cc[os]+level+1;
				//if(level+1>dist){
				//	dist=level+1;
				//}
				//out<<"Dist is "<<level+1<<" and dist is "<<dist<<endl;
				//out<<"It is 1 and cc["<<os<<"] is "<<cc[os]<<endl;
			}
		}
	}
	//out<<"Queue is empty"<<endl;
}

int bfs(int n){
	for(int i=0;i<n;i++){
		//i is the source of bfs
		if(visited[i]!=1){
			//out<<"Calling bfs Util on "<<i<<endl;
			bfsUtil(i,n,i);
		}
		memset(visited,0,sizeof(visited));
	}
	//return dist;
	int min=INT_MAX;
	int minidx=-1;
	for(int i=0;i<n;i++){
		out<<cc[i]<<" "; 
		if(min>cc[i]){
			min=cc[i];
			minidx=i;
		}
	}
	//out<<endl;
	return minidx;
}

int main(){
	in.open("file1.txt");
	out.open("output.txt");
	
	//queue* q=createQueue();
	//enqueue(q,1);
	//enqueue(q,2);
	//enqueue(q,3);
	//while(isEmpty(q)!=1){
		//out<<dequeue(q)<<endl;
	//}
	
	
	int t;
	in>>t;
	for(int q=0;q<t;q++){
		memset(graph,0,sizeof(graph));
		memset(visited,0,sizeof(visited));
		memset(cc,0,sizeof(cc));
		int n;
		in>>n;
		int a;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				in>>a;
				graph[i][j]=a;
			}
		}
		//print(n);
		int r=bfs(n);
		out<<r<<endl;
	}
	

	//getchar();
	return 0;
}
*/