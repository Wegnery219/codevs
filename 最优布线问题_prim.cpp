#include<iostream>
#include<vector>
#include<cstring>
#define MAXN 100001
#define MAXCOST 0x7fffffff
using namespace std;
int m,n;
struct edge{
	int to;
	int cost;
};
vector<edge> g[MAXN];
int d[MAXN];
bool isInq[MAXN];//在是true，不在是false 
long long total=0;

void addedge(int from,int to,int cost){
	edge e;
	e.to=to;
	e.cost=cost;
	g[from].push_back(e);
}


int extract_min(){
	int min=MAXCOST;
	int index=0;
	for(int i=1;i<=n;i++){
		if(d[i]<min&&isInq[i]==false){
			min=d[i];
			index=i;
		}
	}
	return index;
} 

void prim(int s){
	d[s]=0;
	for(int j=1;j<=n;j++){
		int u=extract_min();isInq[u]=true;
		if(u==0) break; 
		for(int f=0;f<g[u].size();f++){
			if(g[u][f].cost<d[g[u][f].to]&&isInq[g[u][f].to]==false){
				d[g[u][f].to]=g[u][f].cost;
			}
		}
		total+=d[u];
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int from,to,cost;
		cin>>from>>to>>cost;
		addedge(from,to,cost);
		addedge(to,from,cost);
	}
	for(int i=0;i<=n;i++){
		d[i]=MAXCOST;
	}
	memset(isInq,false,sizeof(isInq));
	prim(1);
	cout<<total;
}
