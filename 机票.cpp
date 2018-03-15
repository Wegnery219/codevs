#include<iostream>
using namespace std;
int main(){
	int price;
	float zhe; 
	cin>>price;
	cin>>zhe;
	float ans=price*(zhe/10);
	int i=int(ans);
	if((ans-i)*10>=5) i=i+1;
	int ge=i%10;
	int shi=(i%100-ge)/10;
	int bai=i/100;
	if(ge>=5) shi=shi+1;
	i=bai*100+shi*10;
	cout<<i;
}
