#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000;
const int inf = 1 << 29;
int  n,m,w[maxn][maxn],dist[maxn];
bool vis[maxn];
int prim()
{
    int ans = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++)
        dist[i] = w[1][i];
    vis[1] = 1;
    for(int i = 1; i < n; i++)
    {
        int maxi = inf , u;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && dist[j] < maxi)
            {
                maxi = dist[j];
                u = j;
            }
        ans += maxi;
        vis[u] = 1;
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j],w[u][j]);
    }
    return ans;
}

int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                w[i][j] = inf;
        for(int i =0; i < m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            w[u][v] = w[v][u] = c;
        }
        printf("%d\n",prim());
    }
    return 0;
}
