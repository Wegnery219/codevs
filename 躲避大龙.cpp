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
struct xt{
	int x;int t;
}; 
vector<edge> g[N];
queue<xt> q;
//int d[N];//到达n需要的秒数
//int f[N];//到达n需要的秒数取余60 ,初始化很大 
bool isInq[N][60];//第二维是t 

void init(){
//	memset(d,0,sizeof(d));
//	for(int i=0;i<=n;i++) f[i]=MAXINT;
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
	xt sxt;sxt.x=s;sxt.t=0;
	q.push(sxt);isInq[s][0]=true;
	while(!q.empty()){
		xt u=q.front();q.pop();int pos=u.x;int time=u.t;
		//isInq[pos][time]=false;
		for(int i=0;i<g[pos].size();i++){
			int v=g[pos][i].to;
			xt vxt;
			vxt.x=v;
			int cost=g[pos][i].cost;
			int t=(time+cost)%60;
			while(t<0) t+=60;
			vxt.t=t;
			if(!isInq[v][t]){
				q.push(vxt);
				isInq[v][t]=true;
			}
//			if(t<f[v]){
//				
//				f[v]=t;
////				d[v]=d[u]+cost;
//				if(!isInq[v]){
//					q.push(v);
//					isInq[v]=true;
//				}
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
//	if(f[2]==MAXINT) printf("60");
//	else printf("%d",f[2]);
	int ans;
    for(ans=0;ans<=59;ans++)
        if(isInq[2][ans])
            break;
    if(ans<10)
        printf("0");
    printf("%d",ans);
} 
