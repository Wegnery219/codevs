#include<iostream>
#include<math.h>
using namespace std;
long long b,p,k;
//vector<int> record;
//int quyu(int b,int p,int k){
//	if(p==0) return 1;
//	if(p==1) return b%k; 
//	int mid=p/2;
//	int res=p-mid;
//	int l1=quyu(b,mid,k);
//	int l2=quyu(b,res,k);
//	int x=(l1*l2)%k;
//	return x;
//}
//上面这种方法适合动归，没有添加备忘会tle
int quyu(long long x){
	if(x==0)return 1;//任何数的0次方模k都等于1 
    long long tmp=quyu(x/2)%k;//a*b%k=a%k*b%k%k;
    tmp=(tmp*tmp)%k;
    if(x%2==1)tmp=(tmp*b)%k;
    return tmp;
} 
int main(){
	
	cin>>b>>p>>k;

	long long ans=quyu(p);
	cout<<b<<'^'<<p<<" mod "<<k<<'='<<ans;
	return 0;
}
