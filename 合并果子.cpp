#include<iostream>
#include<queue>
using namespace std;
int main(){
	int n;
	int sum=0;
	cin>>n;
	priority_queue<int> q;
	for(int i=0;i<n;i++){
		int tran;
		cin>>tran;
		q.push(-tran);
	}
	while(q.size()-1){//Ҫ������������������-1Ϊ�½� 
		int t=q.top();
		t=-t;
		q.pop();
		int s=q.top();
		s=-s;
		q.pop();
		int ne=s+t;
		sum+=ne;
		q.push(-ne); 
	}
	cout<<sum;
}
