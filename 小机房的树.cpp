#include<iostream>
#include<vector>
#include<cstring> 
#define MAXM 75001
#define MAXN 50001
using namespace std;

struct pair{
	int x1;
	int x2;
}sequence[MAXM];
int n;//±àºÅ0--n-1 
bool isInq[MAXN];
int father[MAXN];

int lca[MAXN];
int dep[MAXN];
struct edge{
	int to;
	int cost;
};
vector<edge> g[MAXN];
vector<int> ask[MAXN];

int find(int u){
	if(father[u]==u) return u;
	else father[u]=find(father[u]);
	return father[u];
}


void build(int s){
	isInq[s]=true;
	
	for(int i=0;i<g[s].size();i++){
		int v=g[s][i].to;
		if (isInq[v]==false){
			dep[v]=dep[s]+g[s][i].cost;
			father[v]=s;
			build(v);
		}
	}
	
	for(int i=0;i<ask[s].size();i++){
		int v=ask[s][i];
		if(isInq[v]&&lca[v]!=-1){
		lca[s]=find(v);
		lca[v]=lca[s];
		}
	}
	
	
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		int from,to,cost;
		cin>>from>>to>>cost;
		edge e;
		e.to=to;e.cost=cost;
		g[from].push_back(e);
		edge e1;
		e1.to=from;e1.cost=cost;
		g[to].push_back(e1);
	}
	memset(isInq,false,sizeof(isInq));
	memset(lca,-1,sizeof(lca));
	for(int i=0;i<=n-1;i++){
		father[i]=i;
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		pair r;
		r.x1=u;r.x2=v;
		sequence[i]=r;
		ask[u].push_back(v);
		ask[v].push_back(u);
	}
	dep[0]=0;
	build(0);
	for(int i=0;i<m;i++){
		
	}
}
