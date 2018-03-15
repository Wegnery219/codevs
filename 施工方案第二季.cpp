#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#define MAXN 100010
#define MAXM 200010
using namespace std;
int n,m;
 struct edge{
 	int to;
 	long long cost;//类型一开始写错 
 };
 struct NODE{
 	int u;int v;
 	long long co;
 }e[MAXM];
 int father[MAXN];
 long long dis[MAXN];//距离源点距离 
 long long dis1[MAXN];
 bool isVis[MAXN];
 vector<edge> g[MAXN];
 
 bool cmp(const NODE &a,const NODE &b){
 	return a.co<b.co;
 }
 
 void addedge(int start,int end,long long cost){
	edge ee;
	ee.to=end;
	ee.cost=cost;
	g[start].push_back(ee);
}

 int find(int u){
 	if(father[u]==u) return u;
 	else father[u]=find(father[u]);
 	return father[u];
 }
 
 long long kruscal(){
 	long long ret=0;
 	sort(e,e+m,cmp);
 	for(int i=1;i<=n;++i) father[i]=i;
 	for(int i=0;i<m;++i){
 		if(find(e[i].u)!=find(e[i].v)){
 			father[find(e[i].u)]=find(e[i].v);
 			addedge(e[i].u,e[i].v,e[i].co);
 			addedge(e[i].v,e[i].u,e[i].co);
 			ret+=e[i].co;
 		}
 	}
 	return ret;
 }
 long long maxx;
 int ret;
 void dfs(int s){
 	isVis[s]=1;
 	for(int i=0;i<g[s].size();i++){
 		int v=g[s][i].to;
 		if(isVis[v]==0){//if(dis[v]<dis[u]+g[s][v].cost&&isVis[v]==0){这和spfa不一样 
 			dis[v]=dis[s]+g[s][i].cost;//这里写成了g[s][v]=.= 
 			//isVis[v]=1;
 			if(dis[v]>maxx) {maxx=dis[v];ret=v;}
 			dfs(v);
 		}
 	}
 }
 int main(){
 	cin>>n>>m;
 	for(int i=0;i<=n+5;i++) g[i].clear(); 
 	for(int i=0;i<m;i++){
 		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].co);
 	}
 	cout<<kruscal()<<endl;
 	
 	memset(isVis,0,sizeof(isVis));
 	memset(dis,0,sizeof(dis));ret=0;maxx=0;
 	dfs(1);
 	
 	memset(isVis,0,sizeof(isVis));
 	memset(dis,0,sizeof(dis));
 	maxx=0;dfs(ret);
 	
 	for(int i=1;i<=n;i++) dis1[i]=dis[i];
 	memset(isVis,0,sizeof(isVis));
 	memset(dis,0,sizeof(dis));
 	maxx=0;dfs(ret);
 	long long min=maxx+1;
 	for(int i=1;i<=n;i++){
 		if(max(dis[i],dis1[i])<min) min=max(dis[i],dis1[i]);
 	}
 	cout<<min<<endl;
 }
 
