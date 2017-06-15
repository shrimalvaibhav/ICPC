#include <iostream>
#include <queue>
using namespace std;

int func(int* start, int* end, int** f, int forbd){
    queue<int> q;
    int visited[10][10][10][10]={0};
    q.push(start[0]);
    q.push(start[1]);
    q.push(start[2]);
    q.push(start[3]);
    q.push(0);
    visited[start[0]][start[1]][start[2]][start[3]]=1;
    while(q.empty()!=1){
        int x=front(q);
        pop(q);
        int y=front(q);
        pop(q);    
        int z=front(q);
        pop(q);    
        int w=front(q);
        pop(q);
        int level=front(q);
        pop(q);
        int count=0;
        int old=-1;
        int a[8][4]={{+1,0,0,0},{-1,0,0,0},{0,+1,0,0},{0,-1,0,0},{0,0,+1,0},{0,0,-1,0},{0,0,0,+1},{0,0,0,-1}};
        for(int i=0;i<8;i++){
            int newx=x+a[i][0];
            int newy=y+a[i][1];
            int newz=z+a[i][2];
            int neww=w+a[i][3];
            if(isSafe(newx,newy,newz,neww,f,forbd)==1 && visited[newx][newy][newz][neww]==0){
                if(old!=level){
                    count++;
                    old=level;
                }
                if(newx==end[0] && newy==end[1] && newz==end[2] && neww==end[3]){
                    return count;
                }
                q.push(newx);
                q.push(newy);
                q.push(newz);
                q.push(neww);
                visited[newx][newy][newz][neww]=1;
            }
        }
    }
    return -1;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		int start[4];
		int end[4];
		for(int i=0;i<4;i++){
			cin>>start[i];
		}
		for(int i=0;i<4;i++){
			cin>>end[i];
		}
		int forbd;
		cin>>forbd;
		int f[forbd][4];
		for(int i=0;i<forbd;i++){
		    for(int j=0;j<4;j++){
		        cin>>f[i][j];
		    }
		}
		int x=func(start, end, (int**)f, forbd);
		cout<<x<<endl;
	}
	return 0;
}
