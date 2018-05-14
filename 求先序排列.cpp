#include<iostream>
#include<cstring>
#define N 9
using namespace std;
void buildtree(string mid,string last){
	cout<<last[last.size()-1];
	int p=mid.find(last[last.size()-1]);
	if(p>0)buildtree(mid.substr(0,p),last.substr(0,p));//substr第二个参数是长度 
	if(p+1<mid.size())buildtree(mid.substr(p+1,mid.size()-p),last.substr(p,last.size()-1-p));
}
int main(){
	string a,b;
	cin>>a>>b;
	buildtree(a,b);
	
}
