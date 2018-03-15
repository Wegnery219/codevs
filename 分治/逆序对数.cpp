#include<iostream>
using namespace std; 
#define MAX 100000
int ar[MAX];
int temp[MAX];
long long total=0;
void merge(int begin,int mid,int end){
	for(int i=begin;i<=end;i++){
		temp[i]=ar[i];
	}
	int i=begin;
	int j=mid+1;
	int k=begin;
	while(i<=mid&&j<=end){
		if(temp[i]<=temp[j]){
			ar[k++]=temp[i++];
		}
		else{
			total+=mid-i+1;
			ar[k++]=temp[j++];
		}
	}
	while(i<=mid) ar[k++]=temp[i++];
	while(j<=end) ar[k++]=temp[j++];
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
	cin>>num;
	for(int i=0;i<num;i++){
		int tr;
		cin>>tr;
		ar[i]=tr;
	}
	mergesort(0,num-1);
	cout<<total;
}
