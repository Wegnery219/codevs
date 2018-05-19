//#include<iostream>
//using namespace std;
//int a(string x){
//	string &m=x;
//	m[0]='b';
//	return 0;
//}
//int main(){
//	string x;
//	cin>>x;
//	a(x);
//	cout<<x;
//	int t;
//	t=2147484647;
//	cout<<t;
//}
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
#define MAXT 0x7fffffff
#define N 102
using namespace std;
/*
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == NULL || l2 == NULL) {
		return l1 == NULL ? l1 : l2;
	}
	int value = l1->val + l2->val;
	ListNode* l3 = new ListNode(value % 10);
	l3->next = addTwoNumbers(l1->next, l2->next);
	if (value >= 10) {
		l3->next = addTwoNumbers(new ListNode(value / 10), l3->next);
	}
	return l3;
}
int pos[256];
		memset(pos, -1, sizeof(pos));
		int length = 0;
		int maxlength = 0;
		for (int i = 0; i < s.length(); i++) {
			char a = s[i];
			if (pos[int(a)] == -1) {
				length += 1;
				pos[int(a)] = i;
			}
			else {
				maxlength = max(length, maxlength);
				length=i-pos[int(a)];
				for (int j = 0; j <= pos[int(a)]; j++) {
					pos[int(s[j])] = -1;
					
				}
				for(int p=i-length+1;p<=i;p++)
				pos[int(s[p])]=p;
			}
		}
        maxlength=max(length,maxlength);
		return maxlength;
*/
int lengthOfLongestSubstring(string s) {
		if(s=="") return 0;
		int maxlen=1;
		int currentLen = 1;
		for (int i = 1; i < s.length(); i++) {
			int repeat = s.substr(i - currentLen, currentLen).find(s.substr(i,1));
			if (repeat == -1) {
				currentLen++;
			}
			else {
				currentLen -= repeat;
			}
			if (maxlen < currentLen) {
				maxlen = currentLen;
			}
		}
		return maxlen;
        
    }
	
int main() {
	
	string s;
	getline(cin, s);
	
	cout << lengthOfLongestSubstring(s);
}
