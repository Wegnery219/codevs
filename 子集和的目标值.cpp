#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#define MAXT 0x7fffffff
#define N 102
using namespace std;

struct store{
	int goal;
	int result;
};
vector<long long> in;
vector<store> record[N];


int minabs(int a, int b) {
	if (a >= 0 && b >= 0) return min(a, b);
	else if (a >= 0 && b<0) return min(a, -b);
	else if (a<0 && b >= 0) return min(-a, b);
	else if (a<0 && b<0) return min(-a, -b);
}

int f(int length, int goal) {
	if (length == -1) {
		if (goal<0) return 0 - goal;
		else return goal;
	}
//	if (record[length][goal] != -1) return record[length][goal];
	for(int i=0;i<record[length].size();i++){
	
		if(record[length][i].goal==goal) return record[length][i].result;
	}
	
		store s;
		s.goal=goal;
		s.result= minabs(f(length - 1, goal), f(length - 1, goal - in.at(length)));
		record[length].push_back(s);
		return s.result;
		//最后一个元素放不放在集合中 
	
}
int main() {
	int n, t;
	cin >> n >> t;
	
	for (int i = 0; i<n; i++) {
		long long m;
		cin >> m;
		in.push_back(m);
	}
	int l = in.size();
	cout << f(l - 1, t);
	
}
