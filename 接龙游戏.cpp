#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
vector<string> g;

stack<string> s;
int n;
bool cmp(string a,string b){
	return a<b;
}
int judge(){
	string p;
	int ans=0;
	int max=0;
	for(int i=0;i<n;i++){
		if(s.empty()||s.top()==p.assign(g[i],0,s.top().length())){
			if(!s.empty()&&s.top()==g[i]) continue;
			ans+=1;
			s.push(g[i]);
		}
		else{
//			string a,b;
//			if(a.assign(g[i],0,1)==b.assign(s.top(),0,1)) continue;
			string a;
			while(!s.empty()&&s.top()!=a.assign(g[i],0,s.top().length())) {
				
				if(max<ans) max=ans;
				s.pop();
				ans-=1;
			}
//			if(s.empty()){
//				s.push(g[i]);
//				ans=1;
//			}
//			else if(s.top()==a.assign(g[i],0,s.top().length())){
				s.push(g[i]);
				ans+=1;
//			else{
//				if(max<ans){
//				max=ans;
//				}
//				ans=0;
//				while(!s.empty()) s.pop();
//				s.push(g[i]);
//				ans+=1;
//			}
			
			
		}
	}
	if(max<ans) max=ans;
	return max;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		g.push_back(str);
	}
	sort(g.begin(),g.begin()+n,cmp);
	cout<<judge();
}
