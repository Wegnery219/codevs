#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAXINT 0x7fffffff
#define MAX 100010
using namespace std;
struct edge{
	int to;
};
vector<edge> g[MAX];
int n,m;
int price[MAX];
int d[MAX],f[MAX];//d是最低价，f是利润最大值 
queue<int> q;
bool isInq[MAX];
//int nev[MAX];

void addedge(int s,int t){
	edge e;
	e.to=t;
	g[s].push_back(e);
}

void init(){
	memset(isInq,false,sizeof(isInq));
	memset(f,-1,sizeof(f));
//	memset(d,-1,sizeof(d));
	for(int i=0;i<=n;i++) d[i]=MAXINT;
	memset(price,0,sizeof(price));
//	memset(nev,0,sizeof(nev));
}

void SPFA(int s){
	d[s]=price[s];f[s]=0;
	while(!q.empty()) q.pop();
	q.push(s);isInq[s]=true;

	while(!q.empty()){
		int u=q.front();q.pop();
		isInq[u]=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			if(min(price[v],d[u])<d[v]) {//wrong first time
				d[v]=min(price[v],d[u]);
				if(isInq[v]==false){q.push(v);isInq[v]=true;}
			}
			
			
			if(max(price[v]-d[u],f[u])>f[v]) {//有=号会导致死循环 
				f[v]=max(price[v]-d[u],f[u]);
				if(isInq[v]==false){q.push(v);isInq[v]=true;}
			}
//			else f[v]=f[u];
//			if(nev[v]==0){q.push(v);isInq[v]=true;nev[v]=1;}
		}
		
	}
} 
int main(){
	
	scanf("%d%d",&n,&m);
	init();
	price[0]=0;
	for(int i=1;i<=n;i++){scanf("%d",&price[i]);}
	for(int i=1;i<=m;i++){
		int fangx,start,end;
		scanf("%d%d%d",&start,&end,&fangx);
		addedge(start,end);
		if(fangx==2) addedge(end,start);
	}
	SPFA(1);
	printf("%d",f[n]);
} 
