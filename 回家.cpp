#include<iostream>
#include<vector>
#include<cctype>
#include<queue>
#include<cstring>
#include<algorithm>
#define MAXN 60
#define MAXCOST 0x7fffffff
using namespace std;
int n;
struct edge{
	int to;
	int cost;
};
vector<edge> g[MAXN];
int d[MAXN];
bool isInq[MAXN];
queue<int> q;

bool cmp(const int &a,const int &b){
	return a<b;
}
int exchange(char a){
	int x=0;
	if(!islower(a)){
		x=a-64;
	}
	else x=a-70;
	return x;
}
void addedge(int from,int to,int cost){
	edge e;
	e.to=to;
	e.cost=cost;
	g[from].push_back(e);
}
void spfa(int s){
	d[s]=0;
	q.push(s);isInq[s]=true;
	while(!q.empty()){
		int u=q.front();
		q.pop();isInq[u]=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			int co=g[u][i].cost;
			if(d[v]>d[u]+co){
				d[v]=d[u]+co;
				q.push(v);
				isInq[v]=true;
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char lettera,letterb;
		int cost;
//		scanf("%c %c %d",&lettera,&letterb,&cost);
		cin>>lettera>>letterb>>cost;
//		cout<<letterb<<endl;
		int la=exchange(lettera);
		int lb=exchange(letterb);
//		cout<<la<<endl;
//		cout<<lb; 
		addedge(la,lb,cost);
		addedge(lb,la,cost);
	}
	memset(d,MAXCOST,sizeof(d));
	for(int i=0;i<MAXN;i++) d[i]=MAXCOST;
	memset(isInq,false,sizeof(isInq));
	spfa(26);
	int minn=MAXCOST;
	int mark=0;
	for(int i=1;i<=25;i++){
		if(d[i]<minn){
			minn=d[i];
			mark=i;
		}
	}
//	sort(d,d+25,cmp);
	char c=mark+64;
	cout<<c<<' '<<minn<<endl;
}
