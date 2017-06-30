/*
#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;
int toe,tog;

void func(int** g, int sr, int sc, int n, int m){
	queue<int> q;
	int** visited=new int*[n];
	for(int i=0;i<n;i++){
		visited[i]=new int[m];
	}
	int xdir[4]={0,0,+1,-1};
	int ydir[4]={+1,-1,0,0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j]=0;
		}
	}
	q.push(sr);
	q.push(sc);
	q.push(1); //denotes the time when the cell is filled with acid
	visited[sr][sc]=1;
	while(q.empty()!=1){
		int x=q.front();
		q.pop();
		int y=q.front();
		q.pop();
		int t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int newx=x+xdir[i];
			int newy=y+ydir[i];
			if(newx>=0 && newx<n && newy>=0 && newy<m && g[newx][newy]!=0){
				if(g[newx][newy]==1 && visited[newx][newy]==0){
					q.push(newx);
					q.push(newy);
					q.push(t+1);
					visited[newx][newy]=1;
					tog=t+1;
				}
				if(g[newx][newy]==2 && visited[newx][newy]!=4){
					visited[newx][newy]++;
					toe=t+1;
				}
			}
		}
	}
	int flag1=1,flag2=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]==1 && visited[i][j]==0){
				flag1=0;
			}
			if(g[i][j]==2 && visited[i][j]!=4){
				flag2=0;	
			}
		}
	}
	if(flag2==0){
		toe=-1;
		tog=-1;
	}
	if(flag1==0){
		tog=-1;
	}
	if(flag1==1 && flag2==1){
		toe--;
		tog=max(tog,toe);
	}
	return ;
}

int main(){
	ifstream in;
	ofstream out;
	in.open("file1.txt");
	int t;
	in>>t;
	for(int k=0;k<t;k++){
		int n,m;
		in>>n>>m;
		int** g=new int*[n];
		for(int i=0;i<m;i++){
			g[i]=new int[m];
		}
		int sr,sc;
		in>>sr>>sc;
		int dummy;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				in>>dummy;
				if(dummy==2){
					if(i==0 || j==0 || i==n-1|| j==m-1){
						cout<<k<<" "<<-1<<" "<<-1<<endl;
						continue;
					}
				}
				g[i][j]=dummy;
				//cout<<g[i][j]<<" ";
			}
		}
		toe=tog=0;
		func(g,sr-1,sc-1,n,m);
		cout<<k<<" "<<toe<<" "<<tog<<endl;
	}
	getchar();
	return 0;
}
*/