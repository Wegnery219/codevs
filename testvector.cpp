#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> a;
	for(int i=1;i<10;i++) a.push_back(i);
	cout<<a.at(a.size()-1)<<endl;
	vector<int> b=a;
	
	a.resize(a.size()-1);
	cout<<a.size();
	cout<<a.at(a.size()-1);
	cout<<b.size();
	cout<<b.at(b.size()-1);
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> in;

int minabs(int a,int b){
	if(a>=0&&b>=0) return min(a,b);
	else if(a>=0&&b<0) return min(a,-b);
	else if(a<0&&b>=0) return min(-a,b);
	else if(a<0&&b<0) return min(-a,-b);
}

int f(int length,int goal){
	if(length==-1){
		if(goal<0) return 0-goal;
		else return goal;
	}
	else{
		return minabs(f(length-1,goal),f(length-1,goal-in.at(length))); 
		//最后一个元素放不放在集合中 
	}
}
int main(){
	int n,t;
	cin>>n>>t;
	
	for(int i=0;i<n;i++){
		int m;
		cin>>m;
		in.push_back(m);
	}
	int l=in.size();
	cout<<f(l-1,t);
} 

