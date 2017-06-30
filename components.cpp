/*
#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int models=0;

void func(int D, int E, int F, int d, int e, int N, int** arr, int* visited, int models, int profit, vector<int>& v){
	
	if(D==0 && E==0 && F==0){
		v.push_back(profit);
		return ;
	}
	
	if(models==3){
		for(int i=0;i<N;i++){
			if(visited[i]==1){
				if(D-arr[i][0]>=0 && E-arr[i][1]>=0 && F-arr[i][2]>=0){
					int x=arr[i][3];
					int y=d*(D-arr[i][0])+e*(E-arr[i][1]);
					func(0,0,0,d,e,N,arr,visited,models,profit+x+y,v);
					//backtrack
					func(D-arr[i][0],E-arr[i][1],F-arr[i][2],d,e,N,arr,visited,models,profit+x,v);
				}
			}
		}

	}
	else{
		for(int i=0;i<N;i++){
			if(visited[i]==0){
				visited[i]=1;
				models++;

				if(D-arr[i][0]>=0 && E-arr[i][1]>=0 && F-arr[i][2]>=0){
					int x=arr[i][3];
					int y=d*(D-arr[i][0])+e*(E-arr[i][1]);
					func(0,0,0,d,e,N,arr,visited,models,profit+x+y,v);
					//backtrack
					func(D-arr[i][0],E-arr[i][1],F-arr[i][2],d,e,N,arr,visited,models,profit+x,v);					
				}

				visited[i]=0;
				models--;
			}
			else{
				if(D-arr[i][0]>=0 && E-arr[i][1]>=0 && F-arr[i][2]>=0){
					int x=arr[i][3];
					int y=d*(D-arr[i][0])+e*(E-arr[i][1]);
					func(0,0,0,d,e,N,arr,visited,models,profit+x+y,v);
					//backtrack
					func(D-arr[i][0],E-arr[i][1],F-arr[i][2],d,e,N,arr,visited,models,profit+x,v);					
				}
			}
		}
	}
	return ;
}

int main(){
	ifstream in;
	in.open("file1.txt");
	int t;
	in>>t;
	for(int q=0;q<t;q++){
		int D,E,F,d,e;
		in>>D>>E>>F>>d>>e;
		int N;
		in>>N;
		int** arr=new int*[N];
		for(int i=0;i<N;i++){
			arr[i]=new int[4];
		}
		int x,y,z,w;
		int i=0;
		int j=0;
		while(i<N){
		//for(i=0;i<N;i++){
			//for(int j=0;j<4;j++){
				in>>x;
				in>>y;
				in>>z;
				in>>w;
				if(d*x+e*y<=w){
					arr[j][0]=x;
					arr[j][1]=y;
					arr[j][2]=z;
					arr[j][3]=w;
					j++;
				}
				i++;
			//}
		}
		vector<int> v;
		v.clear();
		int* visited=new int[j];
		for(int i=0;i<j;i++){
			visited[i]=0;
		}
		models=0;
		int profit=0;
		int flag=0;
		func(D,E,F,d,e,j,arr,visited,models,profit,v);
		int max=D*d+E*e;
		for(int i=0;i<v.size();i++){
			if(max<v[i])
				max=v[i];
		}
		cout<<q<<" "<<max<<" "<<endl;
	}
	getchar();
	return 0;
}
*/