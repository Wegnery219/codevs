# SPFA
涉及程序：最优贸易，躲避大龙（= =），爱情之路</br>
### 最优贸易：
核心代码：
```
while(!q.empty()){
		int u=q.front();q.pop();
		isInq[u]=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to;
			if(min(price[v],d[u])<d[v]) {//wrong first time
				d[v]=min(price[v],d[u]);
				if(isInq[v]==false){q.push(v);isInq[v]=true;}
			}
			
			
			if(max(price[v]-d[u],f[u])>f[v]) {//有=号会导致死循环 
				f[v]=max(price[v]-d[u],f[u]);
				if(isInq[v]==false){q.push(v);isInq[v]=true;}
			}
//			else f[v]=f[u];
//			if(nev[v]==0){q.push(v);isInq[v]=true;nev[v]=1;}
		}
		
```
### 躲避大龙
这道题里有一个不一样的地方就是负循环，在SPFA中负环路如果被判断出直接就被退出，pass掉，但是这里相当于对负循环做了个取模运算。所以就有个结构和spfa中不同`bool isInq[N][60];//第二维是t `，用来记录,核心代码：
```
void SPFA(int s){
	while(!q.empty()) q.pop();
	xt sxt;sxt.x=s;sxt.t=0;
	q.push(sxt);isInq[s][0]=true;
	while(!q.empty()){
		xt u=q.front();q.pop();int pos=u.x;int time=u.t;
		//isInq[pos][time]=false;
		for(int i=0;i<g[pos].size();i++){
			int v=g[pos][i].to;
			xt vxt;
			vxt.x=v;
			int cost=g[pos][i].cost;
			int t=(time+cost)%60;
			while(t<0) t+=60;
			vxt.t=t;
			if(!isInq[v][t]){
				q.push(vxt);
				isInq[v][t]=true;
			}
//			if(t<f[v]){
//				
//				f[v]=t;
////				d[v]=d[u]+cost;
//				if(!isInq[v]){
//					q.push(v);
//					isInq[v]=true;
//				}
			}
		}
	}
```
### 爱情之路
首先理解清楚题意，如果LOVE没连上，这条路就不走了，而且LOVELOVE...必须是紧连着的，不能是LOVEELOVE...这不算完成考验:)，还有一点需要注意的是每条边相当于有两个限制条件，长度和字母，所以isInq[n][M]设置成二维的，n表示点，M表示字母，跟躲避大龙很像。核心代码：
```
while(!q.empty()){
		mark u=q.front();q.pop();
		int pos=u.x;int uletter=u.letter;isInq[pos][uletter]=false;
		for(int i=0;i<g[pos].size();i++){
			
			int v=g[pos][i].to;
			int vletter=g[pos][i].letter;
			int cost=g[pos][i].cost;
			if(!((uletter==4&&vletter==1)||(vletter==uletter+1))) continue;
			if(d[pos][uletter]+cost<=d[v][vletter]){
				d[v][vletter]=d[pos][uletter]+cost;
				if(vletter==4){
					times[v][vletter]=max(times[v][vletter],times[pos][uletter]+1);
				}
				else times[v][vletter]=max(times[v][vletter],times[pos][uletter]);
			    
				if(!isInq[v][vletter]){
					mark vm;vm.x=v;vm.letter=vletter;
					q.push(vm);
					isInq[v][vletter]=true; 
				}
			
		}
	}
```
