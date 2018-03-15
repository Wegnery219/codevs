#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1315
#define MAXINT 0x7fffffff
using namespace std;
//L-1 O-2 V-3 E-4
int n,m;
int marke=0;
int trial=0;
struct edge{
	int to;
	int cost;
	int letter;
}; 
struct mark{
	int x;//点位置
	int letter;//这个点可以到达字母letter ,啥都到不了是0 
};
vector<edge> g[N];
queue<mark> q; 
int times[N][5];//能走一步就加1 ,全初始化成0 
bool isInq[N][5];
int d[N][5];
int nobreak=1;

void init(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<5;j++){
			d[i][j]=MAXINT;
		}
	}
	memset(times,0,sizeof(times));
	memset(isInq,false,sizeof(isInq));
}
void addedge(int start,int end,int cost,char letter){
	edge e;
	e.to=end;e.cost=cost;
	switch(letter){
		case 'L':
			e.letter=1;
			break;
		case 'O':
			e.letter=2;
			break;
		case 'V':
			e.letter=3;
			break;
		case 'E':
			e.letter=4;
			break;
	}
	g[start].push_back(e);
}

void SPFA(int s){
	while(!q.empty()) q.pop();
	mark m;m.x=s;m.letter=4;d[s][4]=0;
	q.push(m);
	bool flag=false;
//	int nobreak=1;
	while(!q.empty()){
		mark u=q.front();q.pop();
		int pos=u.x;int uletter=u.letter;isInq[pos][uletter]=false;
		for(int i=0;i<g[pos].size();i++){
			
			int v=g[pos][i].to;
			int vletter=g[pos][i].letter;
			int cost=g[pos][i].cost;
			if(!((uletter==4&&vletter==1)||(vletter==uletter+1))) continue;
			if(d[pos][uletter]+cost<=d[v][vletter]){
				d[v][vletter]=d[pos][uletter]+cost;
				if(vletter==4){
					times[v][vletter]=max(times[v][vletter],times[pos][uletter]+1);
				}
				else times[v][vletter]=max(times[v][vletter],times[pos][uletter]);
			    
				if(!isInq[v][vletter]){
					mark vm;vm.x=v;vm.letter=vletter;
					q.push(vm);
					isInq[v][vletter]=true; 
				}
			
		}
	}
	if(n==1&&!flag){
		d[n][4]=MAXINT;
		flag=true;
	} 
}
}

int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=0;i<m;i++){
		int start,end,cost;
		char letter;
		scanf("%d%d%d %c",&start,&end,&cost,&letter);
//		scanf("%c",&letter);
		addedge(start,end,cost,letter);
		addedge(end,start,cost,letter);
	}

	SPFA(1);
	int ans=d[n][4];
	int sum=times[n][4];
	if(ans==MAXINT) cout<<"HOLY SHIT!";
	else cout<<ans<<' '<<sum;
}
