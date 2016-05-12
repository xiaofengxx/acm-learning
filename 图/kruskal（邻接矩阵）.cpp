/*#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
const int maxn=1100;
const int inf=1<<29;
const int maxm=maxn*maxn/2;
int e,head[maxn],pnt[maxm],next[maxm],cost[maxm];
int n,m,dist[maxn];
bool vis[maxn];
void AddEdge(int u,int v,int c)
{
    pnt[e]=v;
    cost[e]=c;
    next[e]=head[u];
    head[u]=e++;
}
int Prim()
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        dist[i]=inf;
    vis[1]=1;
    for(int i=head[1]; i!=-1; i=next[i])
        dist[pnt[i]]=cost[i];
    for(int j=1; j<n; j++)
    {
        int mini=inf,u=-1;
        for(int i=1; i<=n; i++)
            if(!vis[i]&&dist[i]<mini)
            {
                mini=dist[i];
                u=i;
            }
        if(u==-1)
            break;
        ans+=mini;
        vis[u]=1;
        for(int i=head[u]; i!=-1; i=next[i])
            dist[pnt[i]]=min(dist[pnt[i]],cost[i]);
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        e=0;
        memset(head,-1,sizeof(head));
        for(int i=0; i<m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
            AddEdge(v,u,c);
        }
        printf("%d\n",Prim());
    }
}
*/



#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=1e6;
const int maxn=100000;
int n,m;
struct Node
{
    int from;
    int to;
    int w;
    bool operator < (const Node &a)const
    {
        return w<a.w;
    }
} E[maxm];
int p[maxn];
int Find(int x)
{
    if(p[x]==-1)
        return x;
    return p[x]=Find(p[x]);
}
int Kruskal()
{
    int ans=0,cnt=0;
    for(int i=0; i<m; i++)
    {
        int x=Find(E[i].from);
        int y=Find(E[i].to);
        if(x!=y)
        {
            cnt++;
            ans+=E[i].w;
            p[x]=y;
        }
    }
    if(cnt<n-1)
        return -1;//无法构成生成树；
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(p,-1,sizeof(p));
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&E[i].from,&E[i].to,&E[i].w);
        sort(E,E+m);
        printf("%d\n",Kruskal());
    }
    return 0;
}

