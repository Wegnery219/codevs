#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue> 
#include<cmath>
#define maxv 100005
#define maxe 200005
using namespace std;
struct edge
{
long long u,v,w,nxt;
}e[maxe],tr[maxe];
long long g[maxv],h[maxv],n,m,x,y,z,nume1=0,nume2=0;
long long pre[maxv],dis[maxv];
long long father[maxv],sum=0,ans=0;;
bool cmp(edge x,edge y)
{
return x.w<y.w;
}
void addedge(long long u,long long v,long long w)
{
e[++nume1].u=u;
e[nume1].v=v;
e[nume1].w=w;
e[nume1].nxt=g[u];
g[u]=nume1;
}
void addtree(long long u,long long v,long long w)
{
tr[++nume2].u=u;
tr[nume2].v=v;
tr[nume2].w=w;
tr[nume2].nxt=h[u];
h[u]=nume2;
}
long long getfather(long long x)
{
if (x!=father[x])
father[x]=getfather(father[x]);
return father[x];
}
void unionn(long long u,long long v)
{
long long r1=getfather(u),r2=getfather(v);
if (r1!=r2)
father[r1]=r2;
}
void kruskal()
{
for (long long i=1;i<=n;i++)
father[i]=i;
for (long long i=1;i<=nume1;i++)
{
if (getfather(e[i].u)!=getfather(e[i].v))
{
unionn(e[i].u,e[i].v);
addtree(e[i].u,e[i].v,e[i].w);
addtree(e[i].v,e[i].u,e[i].w);
sum=sum+e[i].w;
}
}
}
long long find_longest_path()
{
queue <long long> q;
memset(dis,-1,sizeof(dis));
q.push(1);
dis[1]=0;
while (!q.empty())
{
long long head=q.front();
q.pop();
for (long long i=h[head];i;i=tr[i].nxt)
{
long long v=tr[i].v;
if (dis[v]==-1)
{
dis[v]=dis[head]+tr[i].w;
q.push(v);
}
}
}
long long rec=-1,maxn=0;
for (long long i=1;i<=n;i++) 
{
if (dis[i]>maxn)
{
maxn=dis[i];
rec=i;
}
}
q.push(rec);
memset(dis,-1,sizeof(dis));
dis[rec]=0;
while (!q.empty())
{
long long head=q.front();
q.pop();
for (long long i=h[head];i;i=tr[i].nxt)
{
long long v=tr[i].v;
if (dis[v]==-1)
{
dis[v]=dis[head]+tr[i].w;
pre[v]=head;
q.push(v);
}
}
}
maxn=0;
for (long long i=1;i<=n;i++) 
{
if (dis[i]>maxn)
{
maxn=dis[i];
rec=i;
}
}
return rec;
}
int main()
{
memset(g,0,sizeof(g));
memset(h,0,sizeof(h));
scanf("%lld%lld",&n,&m);
for (long long i=1;i<=m;i++)
{
scanf("%lld%lld%lld",&x,&y,&z);
addedge(x,y,z);
addedge(y,x,z);
}
sort(e+1,e+nume1+1,cmp);
kruskal();
long long ends=find_longest_path();
long long rrr=12345678;
for (long long i=ends;i;i=pre[i])
{
long long maxmax=max(dis[i],dis[ends]-dis[i]);
if (maxmax<rrr)
rrr=maxmax;
}
printf("%lld\n%lld\n",sum,rrr);
return 0;
}
