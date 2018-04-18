#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define MAXN 27
using namespace std;

struct tree{
	char data;
	struct tree* left;
	struct tree* right;
};
struct tree* buildtree(char*a,char*b,int abegin,int aend,int bbegin,int bend,struct tree* root){//aÊÇÖÐÐò±éÀú 
	
		root=(struct tree*)malloc(sizeof(struct tree));
//		root->left=NULL;
//		root->right=NULL;
		root->data=a[abegin];
		
	
	
		if(abegin>aend||bbegin>bend){
			return NULL;
		}
		int flagb=bend+1;
//		for(int i=abegin+1;i<aend;i++){
		for(int j=1;j<=bend;j++){
			if(a[abegin+1]==b[bend-j]){
			//	flaga=i;
				flagb=j;
				break;
			}
		}
		int flaga=abegin-1;
		if(flagb!=1){
			
			for(int i=aend;i>=abegin;i--){
			if(a[i]==b[bend-1]){
				flaga=i;
				break;
			}
		}
		}
		else flaga=aend+1;
//		else root->right=NULL;
//		}
		if(flagb!=bend+1)
		root->left=buildtree(a,b,abegin+1,flaga-1,bbegin,bend-flagb,root->left);
		else
		root->left=NULL;
		if(flaga!=abegin-1&&flagb!=1)
		root->right=buildtree(a,b,flaga,aend,bend-flagb+1,bend-1,root->right);
		else
		root->right=NULL;
		return root;
	
	
}
//judgetree()
int ans=0;
void dfs(struct tree* node){
	if(node!=NULL){
		if((node->left!=NULL&&node->right==NULL)||(node->left==NULL&&node->right!=NULL)){
			ans+=1;
		}
		if(node->left!=NULL)
		dfs(node->left);
		if(node->right!=NULL)
		dfs(node->right);
	}
	else return;
} 
int main(){
	char a[MAXN];
	char b[MAXN];
	cin>>a>>b;
	struct tree* root=NULL;
	root=buildtree(a,b,0,strlen(a)-1,0,strlen(b)-1,root);
	dfs(root);
	ans=1<<ans;
	cout<<ans<<endl;
} 
