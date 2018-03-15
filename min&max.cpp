#include<iostream>
#include<vector>
using namespace std;

int main(){
	int num;
	int temp;
	int i=1;
	cin>>num;
	vector<int> ar;
	while(i<=num){
		cin>>temp;
		ar.push_back(temp);
		i++;
	}
	int min=ar[0];int max=ar[0];
	for(auto c:ar){
		if(c<=min) min=c;
	}
	for(auto c:ar){
		if(c>=max) max=c;
	}
	cout<<min<<' '<<max<<endl;
}
