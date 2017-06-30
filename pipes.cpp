
#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int func(int** g, int n, int m, int sr, int sc, int len){
	int** visited=new int*[n];
	for(int i=0;i<n;i++){
		visited[i]=new int[m];
	}
	int** level=new int*[n];
	for(int i=0;i<n;i++){
		level[i]=new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j]=0;
			level[i][j]=-1;
		}
	}
	queue<int> q;
	int adj[8][4]={0};
	adj[1][0]=adj[1][1]=adj[1][2]=adj[1][3]=1;
	adj[2][0]=adj[2][1]=1;
	adj[3][2]=adj[3][3]=1;
	adj[4][1]=adj[4][2]=1;
	adj[5][0]=adj[5][2]=1;
	adj[6][0]=adj[6][3]=1;
	adj[7][1]=adj[7][3]=1;
	q.push(sr);
	q.push(sc);
	visited[sr][sc]=1;
	level[sr][sc]=0;
	int xdir[4]={+1,-1,0,0};
	int ydir[4]={0,0,+1,-1};
	while(q.empty()!=1){
		int x=q.front();
		q.pop();
		int y=q.front();
		q.pop();
		if(g[x][y]!=0){
			for(int i=0;i<4;i++){
				if(adj[g[x][y]][i]==1){
					int j=-1;
					if(i==0) j=1;
					else if(i==1) j=0;
					else if(i==2) j=3;
					else j=2;
					int newx=x+xdir[i];
					int newy=y+ydir[i];
					if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==0 && adj[g[newx][newy]][j]==1){
						q.push(newx);
						q.push(newy);
						visited[newx][newy]=1;
						level[newx][newy]=level[x][y]+1;
					}
				}
			}
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(level[i][j]!=-1 && level[i][j]!=0 && level[i][j]<=len){
				count++;
				cout<<i<<" "<<j<<endl;
			}
		}
	}
	return count;
}

int main(){
	ifstream in;
	in.open("file1.txt");
	int n,m;
	in>>n>>m;
	int** g=new int*[n];
	for(int i=0;i<n;i++){
		g[i]=new int[m];
	}
	int sr,sc,len;
	in>>sr>>sc>>len;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			in>>g[i][j];
		}
	}
	cout<<func(g,n,m,sr,sc,len)<<endl;
	getchar();
	return 0;
}
