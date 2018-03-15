#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXM 10010
#define MAXN 110
using namespace std;
int n;
struct NODE{
	int from;
	int to;
	int cost;
};
vector<NODE> g;
int father[MAXN];

bool cmp(const NODE &a,const NODE &b){
	return a.cost<b.cost;
}

int find(int u){
	if(father[u]==u) return u;
	else father[u]=find(father[u]);
	return father[u];
}
int kruscal(){
	int ret=0;
	int m=g.size(); 
	sort(g.begin(),g.begin()+m,cmp);
	for(int i=0;i<=n;i++) father[i]=i;
	for(int j=0;j<int(g.size());j++){
		if(find(g[j].from)!=find(g[j].to)){
			father[find(g[j].from)]=find(g[j].to);
			ret+=g[j].cost;
		}
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i>j){
				NODE n;
				n.from=i;n.to=j;
				scanf("%d",&n.cost);
				g.push_back(n);
			}
			else{
				int u;
				scanf("%d",&u);
			}
		}
	}
	cout<<kruscal()<<endl;
	
} 
