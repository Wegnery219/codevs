#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAXN 101
using namespace std;

int main(){
	int d1[MAXN],d2[MAXN];//存长度 
	int a[MAXN],b[MAXN];//正向反向存数组 
	int n;
	int maxx=0;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		b[n-i-1]=a[i];
	} 
	for(int i=0;i<n;i++){
		d1[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				d1[i]=max(d1[i],d1[j]+1);
			}
		}
	}
	for(int i=0;i<n;i++){
		d2[i]=1;
		for(int j=0;j<i;j++){
			if(b[j]<b[i]){
				d2[i]=max(d2[i],d2[j]+1);
			}
		}
	}
	for(int i=0;i<n;i++){
		if(d1[i]+d2[n-1-i]>maxx){
			maxx=d1[i]+d2[n-1-i];
		}
	}
	cout<<n-maxx+1;
} 
