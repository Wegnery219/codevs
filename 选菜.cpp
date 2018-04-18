#include<iostream>
#include<vector>
#include<cstring>
#define MAXN 101
#define MAXM 1001
using namespace std;
struct food{
	float price;
	int tasty;
};
struct maxtas{
};

int maxx=0;
float X;
food g[MAXN];
int Maxtasty[MAXN][MAXM];
int f(int foodnum,float m){//foodnum从大到小 
	int money=m*10;
	if(Maxtasty[foodnum][money]!=-1)
		return Maxtasty[foodnum][money];
	if(foodnum==1&&m>g[foodnum].price){
		Maxtasty[foodnum][money]=g[foodnum].tasty;
	}
	else if(foodnum==1&&m<g[foodnum].price){
		Maxtasty[foodnum][money]=0;
	}
	else{
		if(g[foodnum].price<m){
			Maxtasty[foodnum][money]=max(f(foodnum-1,m),f(foodnum-1,m-g[foodnum].price)+g[foodnum].tasty);
		}
		else if(g[foodnum].price>m){
			Maxtasty[foodnum][money]=f(foodnum-1,m);
		}
	}
	return Maxtasty[foodnum][money];
}
int main(){
	int n,k;//X元，n个菜式,k种菜必选 
	cin>>n>>k>>X;
 	int final=0;
	//价格 
	float price_ar[n];
	for(int i=0;i<n;i++){
		scanf("%f",&price_ar[i]);
	} 
	//美味价值
	int tasty_ar[n];
	for(int i=0;i<n;i++){
		scanf("%d",&tasty_ar[i]);
	} 
	//菜编号
	
	
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(num>maxx){
			maxx=num;
		}
		g[num].price=price_ar[i];
		g[num].tasty=tasty_ar[i];
	}
	for(int i=0;i<k;i++){
		int bixuan;
		cin>>bixuan;
		X=X-g[bixuan].price;
		final=final+g[bixuan].tasty;
		g[bixuan].price=0;
		g[bixuan].tasty=0;
	}
	memset(Maxtasty,-1,sizeof(Maxtasty));
	final=final+f(maxx,X);
	cout<<final;
} 
