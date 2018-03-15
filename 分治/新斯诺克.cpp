#include<iostream>
#include<vector>
using namespace std;
#define MAX 10010
vector<int> sum;
int total=0;
long long temp[MAX]; 
void merge(int begin,int mid,int end){
//	vector<int> temp=sum;//ÿһ���������������飬����ʱ��䳤,tle
	for (int i=begin;i<=end;i++) temp[i]=sum[i]; 
	int i=begin;
	int j=mid+1;
	int k=begin;//һ��ʼ�����k=0 
	while(i<=mid&&j<=end){
		if(temp[i]>=temp[j]){//һ��ʼд��С�� 
			sum[k++]=temp[i++];
		}
		else{
			total=total+(mid-i+1);//midһ��ʼ��д��j
			sum[k++]=temp[j++]; 
		}
	}
	while(i<=mid)
	sum[k++]=temp[i++];
	while(j<=end)
	sum[k++]=temp[j++]; 
	
}
void mergesort(int begin,int end){
	if(begin>=end) return;
	int mid=(begin+end)/2;
	mergesort(begin,mid);
	mergesort(mid+1,end);
	merge(begin,mid,end);
}
int main(){
	int num;
	scanf("%d",&num); 
	int mu;
	scanf("%d",&mu);
	
	sum.push_back(0);
	for(int i=1;i<=num;i++){
		int tr;
		scanf("%d",&tr);
		tr=tr-mu;
		sum.push_back(tr+sum[i-1]);
	}
	mergesort(0,num);
	cout<<total;
}
