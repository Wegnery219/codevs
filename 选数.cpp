#include<iostream>
#include<cstring>
#define N 21
using namespace std;
int num[N];
int vis[N];
int n;
int M;
int count=0;

int judgenum(){
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=vis[i];
	}
	return ans;
}

bool sushu(int num){
	int div;
	for(int div=2;(div*div)<=num;div++){
		if(num%div==0){
			return false;
		}
	}
	return true;//忘了加return true 
}

void judge(){
	int sum=0;
	for(int i=0;i<N;i++){
		if(vis[i]==1){
			sum+=num[i];//num[i]写成vis[i] 
		}
	}
	if(sushu(sum)){//写进循环，错了 
		count++;
	}
}
int selectNum(int arg){
	vis[arg]=1;
	if(judgenum()==M){
		judge();
	}
	else{
		if(arg<(N-1)){
			selectNum(arg+1);
		}
	}
	vis[arg]=0;
	if(arg<N-1){
		selectNum(arg+1);
	}
}
int main(){
	cin>>n>>M;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	memset(vis,0,sizeof(vis));
	selectNum(0);
	cout<<count;
} 
