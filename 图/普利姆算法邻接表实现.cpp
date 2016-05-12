#include<cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int inf = 1 << 29
const int maxn = 1100;
const int maxm = maxn * maxn / 2;
int e,head[maxn],pnt[maxm],nxt[maxm],cost[maxm];
int n,m,dist[maxn];
bool vis[maxn];
void AddEdge(int u,int v,int c)
{
    pnt[e] = v;
    cost[e] =c;
    nxt[e] = head[u];
    head[u] = e++;
}
int prim()
{
    int ans = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++)
        dist[i] = inf;
    vis[1] = 1;
    for(int i = head[1]; i != -1; i = nxt[i])
        dist[pnt[i]] = cost[i];
    for(int i =1; i < n; i++)
    {
        int mini = inf,u = -1;
        for(int j = 1; j <= n; j++)
            if(dist[j] < mini)
        {
            mini = dist[j];
            u = j;
        }
        if(u == -1)
            break;
        ans += mini;
        vis[u] = 1;
        for(int j = head[u]; j != -1; j =nxt[j])
            dist[pnt[j]] = min(dist[pnt[j]],cost[j]);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        e = 0;
        memset(head,-1,sizeof(head));
        for(int i = 0; i < m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
            AddEdge(v,u,c);
        }
        printf("%d\n",prim());
    }
}
