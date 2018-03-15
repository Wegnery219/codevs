#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 101
#define MAXCOST 10001
using namespace std;
int n=0;
struct edge{
	int from;
	int to;
};
struct mark{
	int from;
	int cost;
};
int g[N][N];
mark d[N];
bool isInq[N];
vector<edge> path;
int totalcost=0;

void init(){
	for(int j=0;j<=n;j++) isInq[j]=true;
	for(int i=0;i<=n;i++){
		d[i].from=0;
		d[i].cost=MAXCOST;
	}
	memset(g,0,sizeof(g));
}
int extract_min(){
	int min=MAXCOST;
	int index=0;
	for(int i=1;i<=n;i++){
		if(d[i].cost<min&&isInq[i]==true){
			min=d[i].cost;
			index=i;
		}
	}
	return index;
}

void prim(int s){
	d[s].cost=0;d[s].from=0;
	for(int j=1;j<=n;j++){	//最小生成树最多n个边 
	int u=extract_min();isInq[u]=false; 
	if(u==0) break;
    
	
	//松弛 
	for(int i=1;i<=n;i++){
		if(g[u][i]<d[i].cost&&isInq[i]==true){
			d[i].cost=g[u][i];
			d[i].from=u;
		} 
	}
	
	if(d[u].from!=0&&d[u].cost!=0){
    	edge e;
    	e.from=d[u].from;
    	e.to=u;
    	path.push_back(e);
    	totalcost=totalcost+d[u].cost;
    }
	} 
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int cost=0;
			scanf("%d",&cost);
			g[i][j]=cost;
			}
	}
	prim(1);
	cout<<path.size()<<endl;
	for(int j=0;j<path.size();j++){
		edge e=path[j];
		int from=e.from;
		int to=e.to;
		
		cout<<min(from,to)<<' '<<max(from,to)<<endl;
	}
	cout<<totalcost;
}
