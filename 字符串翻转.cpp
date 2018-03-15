#include<iostream>
#include<cstring>
using namespace std;
void fanzhuan(string &s,int begin,int end){
	while(begin<end){
		char m=s[begin];
		s[begin++]=s[end];
		s[end--]=m;
	}
}
int main(){
//	char x[100];
	string x;
//	cin.getline(x,100);
	getline(cin,x);
	int mark=0;
	int l=x.size();
	for(int i=0;i<l;i++){
		if(x[i]==' '){
			fanzhuan(x,mark,i-1);
			mark=i+1;
		}
	}
	fanzhuan(x,mark,l-1);
	
	fanzhuan(x,0,l-1);
	cout<<x;
}
