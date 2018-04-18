#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#define N 7001
using namespace std;
struct item{
	int vi;//体积
	int wi;//价值
	int num;//件数 
}item[N];
int Maxvalue[N][N];
int f(int i,int retV){
	if(Maxvalue[i][retV]!=-1) return Maxvalue[i][retV];
	if(i==0){
		int r=retV/(item[i].vi);
		if(r<=item[i].num) Maxvalue[i][retV]=r*(item[i].wi);
		else Maxvalue[i][retV]=0;
	}
	else{
		if(retV<item[i].vi){
			Maxvalue[i][retV]=f(i-1,retV);
		}
		else{
			if(item[i].num!=0){
				int vv=item[i].vi;
				int ww=item[i].wi;
				int in=max(f(i,retV-vv)+ww,f(i-1,retV-vv)+ww) ;
				int notin=f(i-1,retV);
				if(in>=notin){
					item[i].num-=1;
					Maxvalue[i][retV]=in;
				}
				else Maxvalue[i][retV]=notin;
			}
			else Maxvalue[i][retV]=f(i-1,retV);
		}
	}
	return Maxvalue[i][retV];
}
int main(){
	int n,m;
	cin>>n>>m;//n种物品，背包容量为m
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&item[i].vi,&item[i].wi,&item[i].num);
	} 
	memset(Maxvalue,-1,sizeof(Maxvalue));
	cout<<f(n-1,m);
}
