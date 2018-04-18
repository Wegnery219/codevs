#include<iostream>
using namespace  std;
int main(){
	int n;
	cin>>n;
	int a[n];
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=1;(2*i+1)<=n;i++){
		if(a[2*i]>a[i]||a[2*i+1]>a[i]){
			flag=1;
			break;
		}
	}
	if(flag==1) cout<<"No";
	else cout<<"Yes";
}
