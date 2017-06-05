#include <iostream>
#include <stdlib.h>
using namespace std;

int check(int forb[][4], int nf, int i, int start[4], int x, int y){
	if(y==-1)
		y=9;
	if(x==10)
		x=0;
	int flag=0;
	for(int j=0;j<nf;j++){
		for(int k=0;k!=i && k<4;k++){
			if(forb[j][k]==start[k])
				flag++;
		}
		if(flag==3){
			for(int q=x;q<=y;q++){
				if(q<=9){
					if(forb[j][i]==q)
						return 1;
				}
				else{
					int w=q%10;
					if(forb[j][i]==w)
						return 1;
				}
			}
		}
		else{
			flag=0;
		}
	}
	return 0;
}

int wheels(int start[4], int end[4], int forb[][4], int nf){
	int move=0;
	int done[4]={0};
	for(int i=0;i<4;i++){
		if(end[i]!=start[i]){
			if(abs(end[i]-start[i])< 10-abs(end[i]-start[i])){
				if(end[i]>start[i]){
					if(!check(forb, nf, i, start, start[i]+1, end[i]-1)){
						move+=abs(end[i]-start[i]);
						done[i]=1;
					}
				}
				else{
					if(!check(forb, nf, i, start, end[i]+1, start[i]-1)){
						move+=abs(end[i]-start[i]);
						done[i]=1;
					}
				}
			}
			else if(abs(end[i]-start[i])> 10-abs(end[i]-start[i])){
				if(end[i]>start[i]){
					if(!check(forb, nf, i, start, end[i]+1, start[i]-1)){
						move+=abs(end[i]-start[i]);
						done[i]=1;
					}
				}
				else{
					if(!check(forb, nf, i, start, start[i]+1, end[i]-1)){
						move+=abs(end[i]-start[i]);
						done[i]=1;
					}
				}
			}
			else{
				if(!check(forb, nf, i, start, start[i]+1, end[i]-1)){
					move+=abs(end[i]-start[i]);
					done[i]=1;
				}
				else if(!check(forb, nf, i, start, end[i]+1, start[i]-1)){
					move+=10-abs(end[i]-start[i]);
					done[i]=1;	
				}
			}
		}
	}
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		int start[4];
		for(int i=0;i<4;i++){
			cin>>start[i];
		}
		int end[4];
		for(int i=0;i<4;i++){
			cin>>end[i];
		}
		int nf;
		cin>>nf;
		int forb[nf][4];
		for(int i=0;i<nf;i++){
			for(int j=0;j<4;j++){
				cin>>forb[i][j];
			}
		}
		printf("hello\n");
		cout<<start[0]<<end[0]<<forb[nf-1][0]<<endl;
		int move=wheels(start, end, forb, nf);
		cout<<move<<endl;
	}
	return 0;
}
