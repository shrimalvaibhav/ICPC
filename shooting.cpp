/*
#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
vector<int> v;
*/
/*
void func(int n, int* arr, int nob, int score,int* visited){
	if(nob==n){
		v.push_back(score);
		return ;
	}
	*/
	/*
	if(start==n){
		start=0;
	}
	*/
    /*
	for(int i=0;i<n;i++){
		if(visited[i]==0){
			visited[i]=1;

			//flag1==1 means nothing to left
			int flag1=1,flag2=1,idx1=-1,idx2=-1;
			//check left
			for(int j=0;j<i;j++){
				if(visited[j]==0){
					flag1=0;
					idx1=j;
				}
			}
			//check right
			for(int j=n-1;j>i;j--){
				if(visited[j]==0){
					flag2=0;
					idx2=j;
				}
			}
			int x=0;
			if(flag1==1 && flag2==1){
				x=arr[i];
			}
			else if(flag1==0 && flag2==1){
				x=arr[idx1];
			}
			else if(flag1==1 && flag2==0){
				x=arr[idx2];
			}
			else{
				x=arr[idx1]*arr[idx2];
			}
			
			func(n,arr,nob+1,score+x,visited);
			visited[i]=0;
		}
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
		int n;
		in>>n;
		//cout<<"n is "<<n<<endl;
		int* arr=new int[n];
		int* visited=new int[n];
		for(int i=0;i<n;i++){
			visited[i]=0;
		}
		v.clear();
		for(int i=0;i<n;i++){
			in>>arr[i];
		}
		//for(int i=0;i<n;i++){
		//	cout<<arr[i]<<" ";
		//}
		//cout<<endl;
		func(n,arr,0,0,visited);
		int max=INT_MIN;
		for(int i=0;i<v.size();i++){
			if(max<v[i]){
				max=v[i];
			}
		}
        cout<<k<<" "<<max<<endl;
	}
	getchar();
	return 0;
}
*/