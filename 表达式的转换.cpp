#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
#include<cctype>
using namespace std;
int main(){
	stack<char> s;
	vector<char> back;
	char a[256];
	char
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(isdigit(a[i])) back.push_back(a[i]);
		else if(!s.empty()){
			char u=s.top();
			if((a[i]=='+'||a[i]=='-')&&(u=='*')
		}
	} 
}
