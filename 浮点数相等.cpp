#include<iostream>
using namespace std;
//����ֱ�Ӷ����float 
int main(){
	double a1,a2;
	cin>>a1>>a2;
	double standard=1e-8;
	double x;
	if(a1<a2) x=a2-a1;
	else x=a1-a2;
	if(x>standard) cout<<"no";
	else cout<<"yes";
	
} 
