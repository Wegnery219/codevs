#include<iostream>
#include<stack>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
map<char,char> charpair;

stack<char> s;
vector<string> svector;
void judge(string str){
	char last;
	for(int i=0;i<str.length();i++){
		if(!s.empty()) last=s.top();
		else {s.push(str[i]);continue;}
		if(charpair.at(last)!=str[i])
			s.push(str[i]);
		else
			s.pop();
	}
	if(!s.empty()) cout<<"FALSE"<<endl;
	else cout<<"TRUE"<<endl;
}
int main(){
//	map<char,char> charpair={{'(',')'},{'[',']'},{'{','}'},{'<','>'}};
//	stack<char> s;
	charpair['(']=')';
	charpair['[']=']';
	charpair['<']='>';
	charpair['{']='}';
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	
		string str;
		cin>>str;
		svector.push_back(str);
	//s.push(str[0]);
	
	}
	for(int j=0;j<n;j++){
		while(s.size()!=0) s.pop();
		judge(svector[j]);
	}
}
