#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
const int inf= 1<<29;
const int maxn=30010;
const int maxm=150010;
int e,head[maxn],pnt[maxm],cost[maxm];
int nxt[maxm],dist[maxm];
int n,m;
bool vis[maxn];
stack<int> q;
void AddEdge(int u,int v,int c)
{
    pnt[e]=v;
    nxt[e]=head[u];
    cost[e]=c;
    head[u]=e++;
}
int  Spfa(int st)
{
    for(int i=0;i<=n;i++)
        dist[i]=inf;
    dist[st]=0;
    q.push(st);
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=nxt[i])
            if(dist[pnt[i]]>dist[u]+cost[i])
            {
                dist[pnt[i]]=dist[u]+cost[i];
                if(!vis[pnt[i]])
                {
                    q.push(pnt[i]);
                    vis[pnt[i]]=1;
                }
            }
    }
    return dist[n]-dist[1];
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        e=0;
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
        }
        printf("%d\n",Spfa(1));
    }
}
