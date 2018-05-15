#include<iostream>
using namespace std;
int a(string x){
	string &m=x;
	m[0]='b';
	return 0;
}
int main(){
	string x;
	cin>>x;
	a(x);
	cout<<x;
	int t;
	t=2147484647;
	cout<<t;
}
