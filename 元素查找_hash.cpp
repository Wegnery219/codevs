#include<iostream>
#include<cmath>
#include<cstddef>
using namespace std;
struct node{
	int value;
	node *next;
	void addNext(int x){
		if(value==0){
			value=x;
			return;
		}
		if(next==NULL){
			next=new node{};
			
		}
		next->addNext(x);
	}
	bool findNext(int y){
		if(value==y) return true;
		else if(next==NULL) return false;
		else
		return next->findNext(y);
	}
	~node(){
		delete next;
	}
};
node a[131072];
int h(int x){
	static const double A = 0.6180339887;
    static const double M = 1 << 17;
    return floor ( M * ( A * x - floor ( A * x ) ) );
}
void h_insert(int x){
	int hhash=h(x);
	a[hhash].addNext(x);
}

bool h_find(int x){
	int n=h(x);
	if(a[n].findNext(x)==true) return true;
	else return false;
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int tr;
		cin>>tr;
		h_insert(tr);
	}
	for(int i=0;i<m;i++){
		int tt;
		cin>>tt;
		if(h_find(tt)==true) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
