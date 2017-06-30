#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#define MAX 1000
using namespace std;

/*
void print(int** arr){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

int dig(int x){
	if(x==0)
		return 1;
	int count=0;
	while(x>0){
		count++;
		x=x/10;
	}
	return count;
}

int func(int** arr,  int city){
	int c[MAX]={0};
	int g[5][5][MAX]={0};
	int d[5][5]={0};
	//int mnod=-1;
	//int oldmnod=-2;
	bool found=false;
	//while(found!=true){
		//memset(c,0,sizeof(c));
		int mnod=-1;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(arr[i][j]!=0){
					d[i][j]=dig(arr[i][j]);
					//if(oldmnod!=d[i][j] && mnod<d[i][j]){
					if(mnod<d[i][j]){
						mnod=d[i][j];
					}
				}
			}
		}
		//oldmnod=mnod;
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				if(d[i][j]==mnod){
					int x=arr[i][j];
					while(x>0){
						c[x%10]++;
						x=x/10;
					}
				}
			}
		}

		int max=-1;
		int mc=-1;
		int nocwm=0;
		for(int i=1;i<=city;i++){
			if(c[i]>max){
				nocwm=1;
				max=c[i];
				mc=i;
			}
			else if(c[i]==max){
				nocwm++;
				mc=i;
			}
		}

		return mc;
		
		//if(nocwm==1){
			//found=true;
			//return mc;
		//}
		
}
*/
/*
int main(){
	int** arr=new int*[5];
	for(int i=0;i<5;i++){
		arr[i]=new int[5];
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			arr[i][j]=0;
		}
	}
	ifstream in;
	ofstream out;
	in.open("file1.txt");
	map<char,int> mm;
	mm['r']=0;
	mm['o']=1;
	mm['y']=2;
	mm['g']=3;
	mm['b']=4;
	mm['P']=0;
	mm['G']=1;
	mm['S']=2;
	mm['A']=3;
	mm['N']=4;
	char a;
	int city=1;
	//cin>>a;
	cin>>a;
	char dump,b;
	//cout<<"hello"<<endl;
	while(a!='#'){
		//cout<<a<<endl;
		int count=0;
		while(count!=5){
			//cin>>dump; //slash
			cin>>dump;
			//cin>>b;    //waste
			cin>>b;
			arr[mm[a]][mm[b]]=arr[mm[a]][mm[b]]*10+city;
			count++;
			if(count!=5){
				//cin>>dump; //,
				cin>>dump;
				//cin>>a;   //color
				cin>>a;
			}
		}
		city++;
		//cin>>a;
		cin>>a;
		//cout<<"2 "<<a<<endl;
		if(a=='e'){
			//print(arr);
			if(city-1==1)
				cout<<1<<endl;
			else{
				int x=func(arr,city-1);
				cout<<x<<endl;
			}
			do{
					//cin>>a;
				cin>>a;
				}while((a!='#' && a!='r' && a!='o' && a!='y' && a!='g' && a!='b'));
			if(a=='r' || a=='o' || a=='y' || a=='g' || a=='b'){
				city=1;
				for(int i=0;i<5;i++){
					for(int j=0;j<5;j++){
						arr[i][j]=0;
						}
					}
			}
		}
	}
	

	getchar();
	getchar();
	return 0;
}
*/