#include<iostream>
#include<cstring>
#include<map>
#include<string>
#include<queue>
#define MAXN 2009
using namespace std;
int n;
int par[MAXN];
int result[MAXN];

map<string,int> key;


int find(int x){
	if(par[x]==x) return x;
	else par[x]=find(par[x]);
	return par[x];
}

int uni(int x,int y){
	if(par[x]!=x) uni(par[x],y);
	par[x]=y;
	return 0;
}

int main(){
	int m,p;
	cin>>n>>m>>p;
	for(int i=0;i<n;i++){
		string s;
		cin>>s; 
		key[s]=i;

	}
	for(int i=0;i<n;i++) par[i]=i;
	for(int i=0;i<m;i++){
		string a;string b;
		cin>>a>>b;
		int x=find(key[a]);
		int y=find(key[b]);
		if(x!=y) uni(x,y);
	}
	
	for(int i=0;i<p;i++){
		string c,d;
		cin>>c>>d;
		if(find(key[c])!=find(key[d])) cout<<"cc cry\n";
		else cout<<"safe\n";
	}
} 
