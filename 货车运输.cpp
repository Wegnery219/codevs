#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstring>
#include<queue>
#define MAXN 10001
#define MAXM 50001
using namespace std;
int n,m;
int father[MAXN];

queue<int> q;
int d[MAXN];
bool isInq[MAXN];
struct edge{
	int from;
	int to;
	int cost;
}e[MAXM];
vector<edge> g[MAXN];
bool cmp(const edge &a,const edge &b){
	return a.cost>b.cost;
}
int find(int u){
	if(father[u]==u) return u;
	else father[u]=find(father[u]);
	return father[u];
}

void kruscal(){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	for(int j=0;j<m;j++){
		if(find(e[j].from)!=find(e[j].to)){
			father[find(e[j].from)]=find(e[j].to);
			g[e[j].from].push_back(e[j]);
			edge a;
			a.from=e[j].to;a.to=e[j].from;a.cost=e[j].cost;
			g[e[j].to].push_back(a);
		}
	}
}

void SPFA(int start){
	while(!q.empty()) q.pop();
	d[start]=0;
	q.push(start);
	isInq[start]=true;
	while(!q.empty()){
		int u=q.front();q.pop();isInq[u]=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			if(d[v]<d[u]){//d³õÊ¼»¯³É-1 
				if(d[u]==0) d[v]=g[u][i].cost;
				else if(g[u][i].cost<d[u]) d[v]=g[u][i].cost;
				else if(g[u][i].cost>=d[u]) d[v]=d[u];
				
				if(isInq[v]==false){
				q.push(v);
				isInq[v]=true;
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].cost);
	}
	sort(e,e+m,cmp);
	kruscal();
	int times;
	vector<int> maxlimit;
	cin>>times;
	for(int i=0;i<times;i++){
		int s,t;
		scanf("%d %d",&s,&t);
		memset(d,-1,sizeof(d));
		memset(isInq,false,sizeof(isInq));
		SPFA(s);
		maxlimit.push_back(d[t]);
	}
	for(int i=0;i<times;i++){
		cout<<maxlimit[i]<<endl;
	}
	
}
