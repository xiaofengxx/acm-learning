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
        ans+=mini;
        vis[u]=1;
        for(int j=1; j<=n; j++)
            dist[j]=min(dist[j],w[u][j]);
    }
    return ans;
}
int main()
{
    int ss[maxn];
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&ss[i]);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                {
                    scanf("%d",&w[i][j]);
                    w[i][j]+=(ss[i]+ss[j]);
                }
        }
        printf("%d\n",Prim());
    }
    return 0;
}
