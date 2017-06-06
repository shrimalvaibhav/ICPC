#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

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

int isSafe(int curr_x, int curr_y, int r, int c, int** g, int x, int y){
	if(!(curr_x>=0 && curr_x<r && curr_y>=0 && curr_y<c))
		return 0;
	for(int i=x;i<=curr_x;i++){
		for(int j=y;j<=curr_y;j++){
			if(g[i][j]==0)
				return 0;
		}
	}	
	return 1;
}

int et(int** g,int r, int c,int sr,int sc,int er,int ec){
	cout<<sr<<sc<<er<<ec<<endl;
	//int steps=1;
	queue* q=createQueue(r*c);
	// queue*** qq;
	// qq=(queue***)malloc(sizeof(queue**)*r);
	// for(int i=0;i<c;i++){
	// 	qq[i]=(queue**)malloc(sizeof(queue*)*c);
	// }
	queue* qq[r][c];
	queue* qqq[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			qq[i][j]=createQueue(10);
			qqq[i][j]=createQueue(10);
			push(qqq[i][j], 0);
		}
	}
	push(q,sr);
	push(q,sc);
	int visited[r][c][3];
	int dist[r][c][3];
	int steps[r][c];
	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	memset(steps, 0, sizeof(steps));
	visited[sr][sc][0]=1;
	//dist[sr][sc]=0;
	push(qqq[sr][sc],0);
	//steps[sr][sc]=0;
	push(qq[sr][sc], 0);
	int inc=0;
	int flag=0;
	while(isEmpty(q)!=1){
		cout<<"hello"<<endl;
		int x,y;
		x=pop(q);
		y=pop(q);
		if(x==er && y==ec){
			break;
		}
		//inc=steps[x][y]+1;
		int d=pop(qq[x][y]);
		inc=d+1;
		if(inc==4)
			inc=1;
		int x_move[4]={+1,-1,0,0};
		int y_move[4]={0,0,+1,-1};
		//inc-1 is the third index in visited i.e. 0,1,2
		for(int i=0;i<4;i++){
			int curr_x=x+x_move[i]*inc;
			int curr_y=y+y_move[i]*inc;
			cout<<"Condition values "<<isSafe(x+x_move[i]*inc,y+y_move[i]*inc, r, c, g,x,y)<<visited[x+x_move[i]*inc][y+y_move[i]*inc][inc-1]<<endl;
			if(isSafe(x+x_move[i]*inc,y+y_move[i]*inc, r, c, g,x,y) && visited[x+x_move[i]*inc][y+y_move[i]*inc][inc-1]==0){
				if(pop(qqq[curr_x][curr_y])==0 || (pop(qqq[curr_x][curr_y])!=0 && pop(qqq[curr_x][curr_y])>pop(qqq[x][y])+1)){
					//dist[curr_x][curr_y]=dist[x][y]+1;
					push(qqq[curr_x][curr_y], d+1);
				}
				visited[curr_x][curr_y][inc-1]=1;
				//steps[curr_x][curr_y]=inc;
				push(qq[curr_x][curr_y], inc);
				push(q,curr_x);
				push(q,curr_y);
				cout<<x<<":"<<y<<":"<<curr_x<<":"<<curr_y<<":"<<visited[curr_x][curr_y][inc-1]<<":"<<steps[curr_x][curr_y]<<dist[curr_x][curr_y]<<endl;
				if(curr_x==er && curr_y==ec){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			break;
		}
	}
	return pop(qqq[er][ec]);
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		int r=0,c=0;
		char a;
		cin>>r>>c;
		int** g=(int**)malloc(sizeof(int*)*r);
		for(int i=0;i<r;i++){
			g[i]=(int*)malloc(sizeof(int)*c);
		}
		//int g[r][c];
		int sr=0,sc=0,er=0,ec=0;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				cin>>a;
				if(a=='S'){
					sr=i;
					sc=j;
					g[i][j]=1;
				}
				else if(a=='E'){
					er=i;
					ec=j;
					g[i][j]=1;
				}
				else if(a=='.'){
					g[i][j]=1;
				}
				else{
					g[i][j]=0;
				}
			}
		}
		cout<<"Check g[1][1]"<<g[1][1]<<endl;
		int move=et(g,r,c,sr,sc,er,ec);
		cout<<move<<endl;
	}
	return 0;
}
