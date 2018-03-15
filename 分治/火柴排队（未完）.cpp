#include<iostream>
#include<vector>
using namespace std;
#define LL long long
int main(){
	LL num;
	cin>>num;
	vector<LL> a;
	vector<LL> b;
	LL n=0;
	while(n<num){
		LL tr;
		cin>>tr;
		a.push_back(tr);
		n++;
	}
	n=0;
	while(n<num){
		LL tr;
		cin>>tr;
		b.push_back(tr);
		n++;
	}
}              
