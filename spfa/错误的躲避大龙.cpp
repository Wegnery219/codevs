#include<iostream>
#include<vector>
#include<queue>
#include<cstring> 
#include<cstdio>
#define N 7001
#define MAXINT 0x7fffffff
using namespace std;
//这条路的秒数之和要最小
int n,m;
struct edge{
	int to;
	int cost;
}; 
vector<edge> g[N];
queue<int> q;
int d[N];//到达n需要的秒数
int f[N];//到达n需要的秒数取余60 ,初始化很大 
bool isInq[N];

void init(){
	memset(d,0,sizeof(d));
	for(int i=0;i<=n;i++) f[i]=MAXINT;
	memset(isInq,false,sizeof(isInq));
}

void addedge(int s,int t,int time){
	edge e;
	e.to=t;
	e.cost=time;
	g[s].push_back(e);
} 

void SPFA(int s){
	while(!q.empty()) q.pop();
	d[s]=0;q.push(s);isInq[s]=true;
	while(!q.empty()){
		int u=q.front();q.pop();isInq[u]=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			int cost=g[u][i].cost;
			int asdas=(d[u]+cost)%60;
			if((d[u]+cost)%60<f[v]){
				f[v]=(d[u]+cost)%60;
				d[v]=d[u]+cost;
				if(!isInq[v]){
					q.push(v);
					isInq[v]=true;
				}
			}
		}
	}
} 
int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=0;i<m;i++){
		int start,end,time;
		scanf("%d%d%d",&start,&end,&time);
		addedge(start,end,time);
		addedge(end,start,time);
	}
	SPFA(1);
	if(f[2]==MAXINT) printf("60");
	else printf("%d",f[2]);
} 
