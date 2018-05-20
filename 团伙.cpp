#include<iostream>
#include<cstring> 
#include<algorithm>
#define MAXN 1010
using namespace std;
int f[MAXN*2];

int find(int x){
	if(f[x]==x) return x;
	else f[x]=find(f[x]);
	return f[x];
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=2*n;i++) f[i]=i;
	int m;
	cin>>m;
	for(int j=1;j<=m;j++){
		char a;
		int b;int c;
		cin>>a;
		cin>>b>>c;
		if(a=='F') f[find(b)]=find(c);
		else{
			f[find(b)]=find(c+n);
			f[find(c)]=find(b+n);
		}
	}
	for(int i=1;i<=n;i++){
		f[i]=find(i);
	}
	sort(f+1,f+n+1);
	int flag=1;
	for(int i=2;i<=n;i++){
		if(f[i]!=f[i-1]) flag+=1;
	}
	cout<<flag;
} 

