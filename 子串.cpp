#include<iostream>
using namespace std;
int find(int i,string a,string b){
	int flag=1;
	for(int j=0;j<=i;){
		if(a[j]==b[0]){
			int m=j+1;
			for(int p=1;p<b.size();p++){
				if(a[m]==b[p]){m++;}
				else {flag=0;break;}
			}
			if(flag!=0){cout<<(j+1);return 0;}
			else j=m-1;
			flag=1;
		}
		
		j=j+1;
	}
}
int main(){
	string a,b;
	cin>>a>>b;
	int l;
	int la=a.size();
	int lb=b.size();
	if(la>lb){l=la-lb;find(l,a,b);return 0;}
	else if(la<lb){l=lb-la;find(l,b,a);return 0;}
	else {cout<<1;return 0;}
	
}
