#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 16
#define MAXINT 0x7fffffff
using namespace std;
int n;
int g[MAXN][MAXN];
int ans=MAXINT;
int x=0;
int vis[MAXN];

int dfs(int node,int now){
	if(x>=ans) return 0;
	if(now==n){
		if(x+g[node][1]<ans) ans=x+g[node][1];
	}
	else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				x=x+g[node][i];
				vis[i]=1;
				dfs(i,now+1);
				x=x-g[node][i];
				vis[i]=0; 
			}	
		}
		
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	dfs(1,1);
	cout<<ans;
}
