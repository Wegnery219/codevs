#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
#define N 41
#define K 7
using namespace std;
int num[N];
int n,k;
long long Maxvalue[N][K];
//long long f(int nn,int kk){
//	if(Maxvalue[nn][kk]!=-1) return Maxvalue[nn][kk];
//	
//	if(n-nn==kk){
//		Maxvalue[nn][kk]=1;
//		for(int i=nn;i<n;i++)
//		Maxvalue[nn][kk]*=num[i];
//	}
//	else if(n-nn>kk){
//		if(kk>0){
//		long long b=f(nn+1,kk-1)*num[nn];
//		int fff=num[nn];
//		num[nn]=num[nn]*10+num[nn+1];
//		long long a=f(nn+1,kk);
//		if(a>=b){
//			Maxvalue[nn][kk]=a;
//		}
//		else{
//			Maxvalue[nn][kk]=b;
//			num[nn]=fff;
//		}
//		}
//		else{
//			Maxvalue[nn][kk]=0;
//			int mi=n-nn;
//			for(int j=mi;j>=1;j--)
//			Maxvalue[nn][kk]+=num[n-mi]*pow(10,mi-1);
//		}
//	}
//	return Maxvalue[nn][kk];
//}
long long tonum(int start,int end){
	long long ret = 0;
    for (int i = start; i <= end; i++)
        ret = ret * 10 + num[i];
    return ret;
}
int main(){

	cin>>n>>k;
//	for(int i=1;i<=n;i++){
//		scanf("%d",&num[i]);
//	}
	char str[N];
	scanf("%s",str);
	for(int i=1;i<=strlen(str);i++){
		num[i]=int(str[i-1]-'0');
	}
	memset(Maxvalue,0,sizeof(Maxvalue));
	for (int i = 1; i <= n; i++)
        Maxvalue[i][0] = tonum(1, i);
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){//i代表截断元素Maxvalue[i][j]含义是1->第i个元素插入j个*号的最大值 
			for(int l=j;l<i;l++){//从j到i，因为要保证符号能放进去 
				Maxvalue[i][j]=max(Maxvalue[i][j],Maxvalue[l][j-1]*tonum(l+1,i));
			}
		}
	}
	cout<<Maxvalue[n][k];
} 
//f[j,s]=max{f[i,s-1]*num[i+1,j]}
