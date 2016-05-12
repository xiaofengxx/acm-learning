#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
const int inf= 1 << 30 ;
const int maxn=1e6+1;
stack <int> S;
int e, head[maxn], pnt[maxn], cost[maxn], dist[maxn], nxt[maxn], vis[maxn];
int t, m, n, P[maxn], Q[maxn], c[maxn];
void AddEdge(int u,int v,int c)
{
    pnt[e]=v;
    nxt[e]=head[u];
    cost[e]=c;
    head[u]=e++;
}

void Spaf()
{
    dist[1]=0;
    vis[1]=0;
    S.push(1);
    while(!S.empty())
    {
        int u=S.top ();
        S.pop();
        vis[u]=0;
        for(int i=head[u]; i!=-1; i=nxt[i])
        {
            int h=pnt[i],k=cost[i];
            if(dist[h]>dist[u]+k)
            {
                dist[h]=dist[u]+k;
                if(!vis[h])
                {
                    vis[h]=1;
                    S.push(h);
                }
            }
        }
    }
    return ;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        long long ans=0;
        scanf("%d%d",&n,&m);
        e=0;
        for(int i=1; i<=n; i++)
        {
            dist[i]=inf;
            head[i]=-1;
            vis[i]=0;
        }
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d",&P[i],&Q[i],&c[i]);
            AddEdge(P[i],Q[i],c[i]);
        }
        Spaf();
        for(int i=1; i<=n; i++)ans+=dist[i];
        for(int i=1; i<=n; i++)
        {
            dist[i]=inf;
            head[i]=-1;
            vis[i]=0;
        }
        e=0;
        for(int i=1; i<=m; i++)
            AddEdge(Q[i],P[i],c[i]);
        Spaf();
        for(int i=1; i<=n; i++)ans+=dist[i];
        printf("%lld\n",ans);
    }
    return 0;
}
