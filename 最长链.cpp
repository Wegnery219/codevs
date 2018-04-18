#include<iostream>
#include<vector>
#include<cstdlib>
#include<cstring>
#define N 100001
#define MAX 0x7fffffff
using namespace std;
int n;
vector<int> g[N];
bool isVis[N];
int d[N];
int maxx=0;
int flag=0;
void dfs(int f){
	isVis[f]=true;
	for(int i=0;i<g[f].size();i++){
		int t=g[f][i];
		if(!isVis[t]){
			d[t]=d[f]+1;
			if(d[t]>maxx) maxx=d[t],flag=t;
			dfs(t);
		}
	}
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		
		int l,r;
		cin>>l>>r;
		if(l!=0){
			g[i].push_back(l);
			g[l].push_back(i);
		}
		if(r!=0){
			g[r].push_back(i);
			g[i].push_back(r);
		}
	}
	memset(isVis,false,sizeof(isVis));
	d[1]=0;
	dfs(1);
	memset(d,0,sizeof(d));
	memset(isVis,false,sizeof(isVis));
	d[flag]=0,maxx=0;
	dfs(flag);
	cout<<maxx; 
}
