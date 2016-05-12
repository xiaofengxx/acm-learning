#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=1<<29;
const int maxn=1100;
int n,m,w[maxn][maxn],dist[maxn];
bool vis[maxn];
int Prim()
{
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        dist[i]=w[1][i];
    vis[1]=1;
    for(int i=1; i<n; i++)
    {
        int mini=inf,u=-1;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&dist[j]<mini)
            {
                mini=dist[j];
                u=j;
            }
            if(u==-1)
                break;//处理无法构成最小生成树；
        ans+=mini;
        vis[u]=1;
        for(int j=1; j<=n; j++)
            dist[j]=min(dist[j],w[u][j]);
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                w[i][j]=inf;
        for(int i=0; i<m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            w[u][v]=w[v][u]=c;
        }
        printf("%d\n",Prim());

    }
    return 0;
}





