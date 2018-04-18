#include<iostream>
#include<stack>
using namespace std;
int main(){
	int n;
	stack<int> s;
	cin>>n;
	for(int i=0;i<n;i++){
		int mark;
		int num;
		cin>>mark;
		if(mark==1) {
			cin>>num;
			s.push(num);
		}
		else s.pop();
	}
	if(!s.empty()){
		int u=s.top();
		cout<<u; 
	}
	else cout<<"impossible";
} 
