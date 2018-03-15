#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define N 101 
#define MAXCOST 1000001
using namespace std;
int n;
vector<int> g[N];
long long totalcost=0;
int notInq[N];//不在是1，在是0，一开始都在
struct edge{
	int from;
	int cost;
}; 
edge d[N];

int init(){
	for(int i=0;i<=n;i++){
		d[i].from=0;
		d[i].cost=MAXCOST;
	}
	memset(notInq,0,sizeof(notInq));
}
int extract_min(){
	int min=MAXCOST;
	int index=0;
	for(int i=1;i<=n;i++){
		if(d[i].cost<min&&notInq[i]==0){
			min=d[i].cost;
			index=i;
		}
	}
	return index;
}
void prim(int s){
	d[s].from=0;d[s].cost=0;
	for(int j=1;j<=n;j++){
		int u=extract_min();notInq[u]=1;
		if(u==0) break;
		//松弛
		for(int f=0;f<n;f++){
			if(g[u][f]<d[f+1].cost&&notInq[f+1]==0){
				d[f+1].cost=g[u][f];
				d[f+1].from=u;//这里一开始错了，f+1 
			}  
		}
		if(d[u].from!=0){
			totalcost=totalcost+d[u].cost;
		}
	}
}
int main(){
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			int now;
			cin>>now;
			g[i].push_back(now);
		}
	}
	prim(1);
	cout<<totalcost; 
}

