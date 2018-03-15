#include<iostream>
using namespace std;
int main(){
	int n;long long max=0xffffffff;
	cin>>n;
	if (n>100) return 0;
	int i=0;int sum=0;
	int temp;
	while(sum<=max&&i<n&&cin>>temp){
		sum+=temp;
		i++;
	}
	if(sum>max){
		return 0;
	}
	else cout<<sum<<endl;
}
