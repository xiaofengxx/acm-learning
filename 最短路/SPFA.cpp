#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int inf= 1<<29;
const int maxn=1e3+100;
const int maxm=maxn*maxn;
int e,head[maxn],pnt[maxm],cost[maxm];
int pre[maxm],nxt[maxm],dist[maxm],cnt[maxn];
int n,m;
bool vis[maxn];
queue<int> q;
void AddEdge(int u,int v,int c)
{
    pnt[e]=v;
    nxt[e]=head[u];
    cost[e]=c;
    head[u]=e++;
}
bool Spfa(int st)
{
    for(int i=0;i<=n;i++)
        dist[i]=inf;
    dist[st]=0;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=nxt[i])
            if(dist[pnt[i]]>dist[u]+cost[i])
            {
                pre[pnt[i]]=u;
                dist[pnt[i]]=dist[u]+cost[i];
                if(!vis[pnt[i]])
                {
                    if(++cnt[pnt[i]]>=n)
                        return false ;
                    q.push(pnt[i]);
                    vis[pnt[i]]=1;
                }
            }
    }
}
void DFS(int u)
{
    if(pre[u]==-1)
    {
        printf("%d\n",u);
        return ;
    }
    DFS(pre[u]);
    printf("%d->",u);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        e=0;
        memset(head,-1,sizeof(head));
        memset(cnt,0,sizeof(cnt));
        memset(pre,-1,sizeof(pre));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
        }
    }
}
