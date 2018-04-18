#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree* buildtree(int x,struct tree*root){
	if(root==NULL){
		root=(struct tree*)malloc(sizeof(struct  tree));
		root->left=NULL;
		root->right=NULL;
		root->data=x;
		return root; 
	}
	else if(root!=NULL){
		if(x==root->data){
			return root;
		}
		else if(x>root->data){
			root->right=buildtree(x,root->right);
			return root;
		}
		else if(x<root->data){
			root->left=buildtree(x,root->left);
			return root;
		}
	}
}
bool findx(int x,struct tree* root){
	if(root==NULL) return false;
	if(x==root->data) return true;
	else if(x>root->data) return findx(x,root->right);
	else if(x<root->data) return findx(x,root->left);
}

int main(){
	int n,m;
	cin>>n>>m;
	struct tree* root=NULL;
	for(int i=0;i<n;i++){
		int tr;
		cin>>tr;
		root=buildtree(tr,root);
	}
	for(int i=0;i<m;i++){
		int tt;
		cin>>tt;
		if(findx(tt,root)==true) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
