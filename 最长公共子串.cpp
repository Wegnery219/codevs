#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
//	int a[2];
//	a[0]=0;
//	a[1]=1;
//	a[2]=2;
	int n;
	cin>>n;
	string str[n];
	int min_len=0x7fffffff;
	for(int i=0;i<n;i++){
		string a;
		cin>>a;
		str[i]=a;
		int length=a.length();
		if(length<min_len) min_len=length;
	}
	for(int j=min_len;j>0;j--){
		for(int i=0;i<str[0].length()-j;i++){
			int flag=1;
			for(int k=1;k<n;k++){
				if(str[k].find(str[0].substr(i,j))==string::npos) flag=0;
			}
			if(flag){
				cout<<str[0].substr(i,j);
				return 0;
			}
		}
	}
} 
