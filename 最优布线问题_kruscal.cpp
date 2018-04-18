#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 100001
using namespace std;
int n,m;
int father[MAXN];
struct edge{
	int from;
	int to;
	int cost;
}e[MAXN];

bool cmp(const edge &a,const edge &b){
	return a.cost<b.cost;
}

int find(int u){
	if(father[u]==u) return u;
	else father[u]=find(father[u]);
	return father[u];
}
long long kruscal(){
	long long total=0;
	sort(e,e+m,cmp);
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
	for(int i=0;i<m;i++){
		if(find(e[i].from)!=find(e[i].to)){
			father[find(e[i].from)]=find(e[i].to);
			total+=e[i].cost;
		}
	}
	return total;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&e[i].from,&e[i].to,&e[i].cost);
	}
	cout<<kruscal()<<endl;
}
