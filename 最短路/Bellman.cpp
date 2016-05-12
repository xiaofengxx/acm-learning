#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int inf= 1<<29;
const int maxn=1100;
const int maxm=maxn*maxn;
int n,m,e,head[maxn],pnt[maxm],cost[maxm];
int from[maxm],nxt[maxm],dist[maxm];
void AddEdge(int u,int v,int c)
{
    pnt[e]=v;
    nxt[e]=head[u];
    from[e]=u;
    cost[e]=c;
    head[u]=e++;
}
bool Bellman_ford(int st)
{
            //1,初始化
    for(int i=0;i<=n;i++)
        dist[i]=inf;
    dist[st]=0;
            //2.进行n-1次更新
    for(int i=1;i<n;i++)
        for(int j =0;j<e;j++)
            if(dist[pnt[j]]>dist[from[j]]+cost[j])
                dist[pnt[j]]+dist[from[j]]+cost[j];
            //判断是否存在负环
    for(int j=0;j<e;j++)
        if(dist[pnt[j]]>dist[from[j]]+cost[j])
            return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(head,-1,sizeof(head));
        e=0;
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
        }

    }
}
