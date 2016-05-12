#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int inf= 1<<29;
const int maxn=1e3+100;
const int maxm=maxn*maxn;
int e,head[maxn],pnt[maxm],cost[maxm];
int nxt[maxm],dist[maxm];
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
        dist[i]=0;
    dist[st]=0x3f3f3f;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=nxt[i])
            if(dist[pnt[i]]<min(dist[u],cost[i]))
            {
                dist[pnt[i]]=min(dist[u],cost[i]);
                if(!vis[pnt[i]])
                {
                    q.push(pnt[i]);
                    vis[pnt[i]]=1;
                }
            }
    }
    return dist[n];
}
int main()
{
    int sum,tt=1,nn;
    scanf("%d",&nn);
    while(nn--)
    {
        scanf("%d%d",&n,&m);
        e=0;
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
            AddEdge(v,u,c);
        }
        Spfa(1);
        printf("Scenario #%d:\n%d\n",tt,);
        tt++;
    }
}
