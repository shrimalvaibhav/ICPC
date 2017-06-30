/*
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>
using namespace std;

void func(int A, int* col, vector<int>& queenpos, vector<vector<string> > &ans, vector<vector<string> >& curr, int qp){
    if(qp==A){
        ans.push_back(curr);
        return ;
    }
    for(int j=0;j<A;j++){
        
            if(col[j]==0){
                int flag=1; //assume queen can be put at i,j
                for(int k=0;k<queenpos.size();k=k+2){
                    if(abs(qp-queenpos[k])==abs(j=queenpos[k+1])){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    //cout<<qp<<" "<<j<<endl; 
                    
                    col[j]=1;
                    queenpos.push_back(qp);
                    queenpos.push_back(j);
                    string x="";
					for(int q=0;q<A;q++){
						if(q!=j){
							x=x+".";
						}
						else{
							x=x+"Q";
						}
					}
					curr.push_back(x);
                    func(A,col,queenpos,ans,curr,qp+1);
  
					
                    col[j]=0;
                    queenpos.pop_back();
                    queenpos.pop_back();
					curr.pop_back();
					
                }
            }
        
    }
    return ;
}

vector<vector<string> > solveNQueens(int A) {
    //int* row=new int[A];
    int* col=new int[A];
    vector<int> queenpos;
    for(int i=0;i<A;i++){
       // row[i]=0;
        col[i]=0;
    }
//    for(int i=0;i<2*A;i++){
//       queenpos[i]=0;
//    }
    vector<vector<string> > ans;
    vector<vector<string> > curr;
	//cout<<"H1"<<endl;
    func(A,col,queenpos,ans,curr,0);
    return ans;
}


int main(){
	vector<vector<string> > ans;
	ans=solveNQueens(4);
	/*
	for(int i=0;i<ans.size();i++){
		for(int j=0;j<ans[0].size();i++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
    /*
	cout<<ans[0][0][0]<<endl;
	getchar();
	getchar();
	return 0;
}
*/