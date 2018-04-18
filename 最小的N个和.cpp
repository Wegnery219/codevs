#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001],b[100001];
int n;
struct node{
	int index;int value;
	bool operator <(const node &v) const{
		return value>v.value;
	}
};
bool cmp(const int &a,const int &b){
	return a<b;
}
priority_queue<node> q;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	node k;
	for(int i=0;i<n;i++){
		node k;
		k.index=0;
		k.value=a[i]+b[0];
		q.push(k);
	}
	int s=0;
	while(s<n){
		node now=q.top();
		q.pop();
		node k;
		if(now.index+1<n){
			k.index=now.index+1;
			k.value=now.value-b[now.index]+b[now.index+1];
			q.push(k);
		}
		s++;
		cout<<now.value<<' ';
	}
}








































/*#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n;
priority_queue<long long> a;
priority_queue<long long> b;
vector<long long> ans;

int judge(){
	a.pop();
	b.pop(); 
	long long newa=a.top();
	long long newb=b.top();
	newa=-newa;
	newb=-newb;
	int flag;
	if(newa<newb){
		flag=0;//0ÊÇa 
	}
	else flag=1;//1ÊÇb
	return flag;
}
int main(){
	cin>>n;

	for(int i=0;i<n;i++){
		long long tra;
		cin>>tra;
		a.push(-tra);
	}
	for(int i=0;i<n;i++){
		long long trb;
		cin>>trb;
		b.push(-trb);
	}
	int sss=0;
	while(sss<n){
		long long mina=a.top();
		long long minb=b.top();
		mina=-mina;
		minb=-minb;
		ans.push_back(mina+minb);
		if(mina<minb) b.pop();
		else if(mina>minb) a.pop();
		else{
			int j=judge();
			if(j==0){//¸Ãapop
				b.push(-minb); 
			}
			else if(j==1){
				a.push(-mina);
			}
		}
		sss=sss+1;
	}
	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
}
*/


