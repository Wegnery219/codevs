#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
#define N 101
using namespace std;
int n;//小区数
struct edge{
	int length;
	int time;
}e[N][N]; 
vector<edge> g[N];
float d[N];
int d_length[N];
int d_time[N];
bool isInq[N];//一开始都不在 

queue<int> q;
void spfa(int s){
	d[s]=0;d_length[s]=0;d_time[s]=0;isInq[s]=true;q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		isInq[u]=false;
		for(int v=1;v<=n;v++){
			if(v!=u){
				if((float(d_length[u]+e[u][v].length)/(d_time[u]+e[u][v].time))>d[v]){
					d[v]=float(d_length[u]+e[u][v].length)/(d_time[u]+e[u][v].time);
					d_length[v]=d_length[u]+e[u][v].length;
					d_time[v]=d_time[u]+e[u][v].time;
					if(isInq[v]!=true){
					q.push(v);
					isInq[v]=true; 
					}
				}
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int l;
			cin>>l;
			if(l==0){
				continue;
			}
			edge etr;
			etr.length=l;
			e[i][j]=etr;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int t;
			cin>>t;
			if(t==0) continue;
			e[i][j].time=t;
		}
	}
	
	memset(d,0,sizeof(d));
	memset(d_length,0,sizeof(d_length));
	memset(d_time,0,sizeof(d_time));
	memset(isInq,false,sizeof(isInq)); 
	spfa(1);
	
//	cout<<prev;
	printf("%.3lf",d[n]);
}
