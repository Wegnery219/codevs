#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define N 100010
#define MAXINT 0x7fffffff
using namespace std;
int n,m;
struct edge{
	int to;
	int cost;
};
vector<edge> g[N];
queue<int> q;
int d[N];
int path[N];
int c[N];
bool isInq[N];
void SPFA(int v0){
	for(int i=0;i<=n;i++){
		d[i]=MAXINT;
	}
	memset(c,-1,sizeof(c));
	memset(isInq,false,sizeof(isInq));
	memset(path,-1,sizeof(path));
	d[v0]=0;
	q.push(v0);
	isInq[v0]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		isInq[u]=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			if(d[v]>d[u]+g[u][i].cost){
				if(isInq[v]==false){
					q.push(v);
					isInq[v]=true;
				}
				d[v]=d[u]+g[u][i].cost;
				if(g[u][i].cost>c[v]) c[v]=g[u][i].cost;
				path[v]=u;
			}
		}
	}
} 
int main(){
	vector<int> result; 
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u;
		cin>>u;
		edge e;
		cin>>e.to>>e.cost;
		g[u].push_back(e);
		int m=e.to;
		e.to=u;
		u=m;
		g[u].push_back(e);
	}
	int times;
	cin>>times;
	for(int i=0;i<times;i++){
		int start,end;
		cin>>start>>end;
		SPFA(start);
//		int max=0;
//		int p=end;
//		while(path[p]!=-1){
//			int s=path[p];
//			for(int i=0;i<g[s].size();i++){
//				if(g[s][i].to==p){
//					if(g[s][i].cost>max){
//						max=g[s][i].cost;
//					}
//				p=path[p];
//				break;
//				}
//			}
//			
//		}
		int max=c[end];
		result.push_back(max);
	}
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<endl;
	}
}

