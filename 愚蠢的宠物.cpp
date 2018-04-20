#include<iostream>
#include<vector>
#include<cstring>
#define N 1000001
using namespace std;
int par[N];
int flag[N];
void finda(int x){
	if(x==0) return;
	else{
		flag[x]=1;
		finda(par[x]);
	}
}
int findb(int y){
	if(flag[y]==1) return y;
	else findb(par[y]);
}
//int k(int x,int y){
//	if(x==y) return x;
//	else if(height[x]>height[y])  k(x,par[y]);
//	else if(height[x]<height[y])  k(par[x],y);
//	else return k(par[x],par[y]);
//}
int main(){
	int n;
	cin>>n;
	memset(flag,0,sizeof(flag));
	memset(par,0,sizeof(par));
	for(int i=1;i<n;i++){
		int s;
		int t;
		cin>>s>>t;
		par[t]=s;
	}
	int m,p;
	cin>>m>>p;
	finda(m);
	
	cout<<findb(p);
}
