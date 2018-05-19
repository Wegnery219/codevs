#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define MAXN 10001
using namespace std;
int n,m;//n city m road
struct road{
	int from;
	int to;
	int cost;
}r[MAXN]; 
int father[MAXN],ask[MAXN],vis[MAXN];
bool isInq[MAXN];
vector<road> maxroad[MAXN];

void addedge(int from,int to,int cost){
	road r1;
	r1.from=from,r1.to=to,r1.cost=cost;
	maxroad[from].push_back(r1);
	road r2;
	r2.from=to,r2.to=from,r2.cost=cost;
	maxroad[to].push_back(r2);
}
bool cmp(const road &a,const road &b){
	return a.cost>b.cost;
}

int find(int u){
	if(father[u]==u) return u;
	else father[u]=find(father[u]);
	return father[u];
}

void kruscal(){
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=0;i<m;i++){
		if(find(r[i].from)!=find(r[i].to)){
			addedge(r[i].from,r[i].to,r[i].cost);
			father[find(r[i].from)]=find(r[i].to);
		}
	}
}

void build(int u){
	isInq[u]=true;
	int flag=1;//to mark whether there is other sub node
	for(int i=0;i<maxroad[u].size();i++){
		int to=maxroad[u][i].to;
		if(isInq[to]!=true) {father[to]=u;build(to);flag=0;}
	}
	if(flag==1){//u no sub node,searching for whether there is an ask
		if(ask[u]!=0&&vis[ask[u]]==1){
			int lca=find(ask[u]);
			min()
		}
	}
	vis[u]=1;
}
 
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>r[i].from>>r[i].to>>r[i].cost;
	}
	sort(r,r+m,cmp);
	kruscal();
	int q;
	cin>>q;
	memset(ask,0,sizeof(ask));
	memset(isInq,false,sizeof(isInq));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=0;i<q;i++){
		int a1,a2;
		cin>>a1>>a2;
		ask[a1]=a2;
		ask[a2]=a1;
	}
	build(1);
}
