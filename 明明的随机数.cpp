#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int flag=n;
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]) flag-=1;
	}
	cout<<flag<<endl;
	cout<<a[0]<<' ';
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]) cout<<a[i]<<' ';
	}
}
