#include<iostream>
#include<cstring>
#include<algorithm>
#define MAXN 31
#define MAX 20001
using namespace std;

int d[MAXN];
int t[MAX];
int main(){
	int total;cin>>total;
	int n;cin>>n;
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		cin>>d[i];
		for(int j=total;j>=d[i];j--){
			t[j]=max(t[j-d[i]]+d[i],t[j]);
		}
	}
	cout<<total-t[total];
}

