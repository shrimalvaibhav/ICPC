#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 13

struct Queue{
	int n;
	int size;
	int front;
	int back;
	int* arr;
};

typedef struct Queue queue;

queue* createQueue(int x){
	queue* temp=(queue*)malloc(sizeof(queue));
	temp->n=x;
	temp->front=0;
	temp->back=temp->n-1;
	temp->size=0;
	temp->arr=(int*)malloc(temp->n*sizeof(int));
	memset(temp->arr,0,temp->n);
	return temp;
}

int isFull(queue* q){
	if(q->n==q->size)
		return 1;
	return 0;	
}

int isEmpty(queue* q){
	if(q->size==0)
		return 1;
	return 0;	
}

void push(queue* q, int a){
	if(!isFull(q)){
		q->back=(q->back+1)%q->n;
		q->arr[q->back]=a;
		q->size++;
	}
	else{
		printf("Can't push\n");
	}
}

int pop(queue* q){
	if(!isEmpty(q)){
		int x=q->arr[q->front];
		q->front=(q->front+1)%q->n;
		q->size--;
		return x;
	}
	else{
		printf("Can't pop\n");
		return -1;
	}
}
int v;
void news(int graph[][v], int source){
	queue* q=createQueue(v);
	int level[v];
	//level[i]==0 signify the node is unvisited
	int news[v];
	for(int k=0;k<v;k++){
		level[k]=news[k]=0;
	}
	push(q,source);
	int neighbours=0;
	int level_base=1;
	level[source]=level_base;
	while(isEmpty(q)!=1){
		neighbours=0;
		int x=pop(q);
		level_base=level[x]+1;
		int i=0;
		for(i=0;i<v;i++){
			if(graph[x][i]==1 && level[i]==0){
				printf("Child is %d of %d\n", i,x);
				neighbours++;
				push(q,i);
				level[i]=level_base;
			}
		}
		news[x]=neighbours;
	}
	int i;
	for(i=0;i<v;i++){
		printf("%d ",level[i]);
		printf("%d ", news[i]);
		printf("\n");
	}
}

int main(void) {
	// your code goes here
	
	scanf("%d", &v);
	int i=0;
	int neighbours=0, friends=0;
	int graph[v][v];
	int j=0;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++)
			graph[i][j]=0;
	}
	for(i=0;i<v;i++){
		scanf("%d", &neighbours);
		for(j=0;j<neighbours;j++){
			scanf("%d", &friends);
			graph[i][friends]=1;
		}
	}
	int t;
	scanf("%d", &t);
	int source=0;
	for(i=0;i<t;i++){
		scanf("%d", &source);
		news(graph, source);
	}
	return 0;
}
