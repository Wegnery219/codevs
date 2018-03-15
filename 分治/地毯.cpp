#include<iostream>
#include<math.h>
using namespace std;
void ditan(int lx,int ly,int len,int x,int y){
	if(len<=1) return;//一开始忘了加这个 
	 if(len==2){
	 	if(x==lx&&y==ly){cout<<ly+1<<' '<<lx+1<<' '<<3<<endl;return;}
	 	else if(x==lx+1&&y==ly){cout<<ly+1<<' '<<lx<<' '<<1<<endl;return;}
	 	else if(x==lx&&y==ly+1){cout<<ly<<' '<<lx+1<<' '<<2<<endl;return;}
	 	else if(x==lx+1&&y==ly+1){cout<<ly<<' '<<lx<<' '<<4<<endl;return;}
	 }
	 int w;
	 if(x>=lx&&y>=ly&&x<x+len&&y<y+len){
	 	if(x<lx+len/2&&y<ly+len/2) w=1;
	 	else if(x>=lx+len/2&&y<ly+len/2) w=2;
	 	else if(x<lx+len/2&&y>=ly+len/2) w=3;
	 	else if(x>=lx+len/2&&y>=ly+len/2) w=4;
	 }
	 switch(w){
	 	case 1:
	 		cout<<ly+len/2<<' '<<lx+len/2<<' '<<3<<endl;
	 		ditan(lx,ly,len/2,x,y);
	 		ditan(lx+len/2,ly,len/2,lx+len/2,ly+len/2-1);
	 		ditan(lx,ly+len/2,len/2,lx+len/2-1,ly+len/2);
	 		ditan(lx+len/2,ly+len/2,len/2,lx+len/2,ly+len/2);
	 		break;
	 	case 2:
	 		cout<<ly+len/2<<' '<<lx+len/2-1<<' '<<1<<endl;
	 		ditan(lx+len/2,ly,len/2,x,y);
	 		ditan(lx,ly,len/2,lx+len/2-1,ly+len/2-1);
	 		ditan(lx,ly+len/2,len/2,lx+len/2-1,ly+len/2);
	 		ditan(lx+len/2,ly+len/2,len/2,lx+len/2,ly+len/2);
	 		break;
	 	case 3:
	 		cout<<ly+len/2-1<<' '<<lx+len/2<<' '<<2<<endl;
	 		ditan(lx,ly+len/2,len/2,x,y);
	 		ditan(lx,ly,len/2,lx+len/2-1,ly+len/2-1);
	 		ditan(lx+len/2,ly,len/2,lx+len/2,ly+len/2-1);
	 		ditan(lx+len/2,ly+len/2,len/2,lx+len/2,ly+len/2);
	 		break;
	 	case 4:
	 		cout<<ly+len/2-1<<' '<<lx+len/2-1<<' '<<4<<endl;
	 		ditan(lx+len/2,ly+len/2,len/2,x,y);
	 		ditan(lx,ly,len/2,lx+len/2-1,ly+len/2-1);
	 		ditan(lx+len/2,ly,len/2,lx+len/2,ly+len/2-1);
	 		ditan(lx,ly+len/2,len/2,lx+len/2-1,ly+len/2);
	 		break;
	 }
	 return;
}
int main(){
	int k;
	cin>>k;
	int x,y;
	cin>>x>>y;
	int l=pow(2,k);
//	cout<<l<<endl;
	ditan(1,1,l,x,y);
} 
