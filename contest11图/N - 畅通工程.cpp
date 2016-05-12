#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 110;
const int inf = 1 << 29;
int  n,m,w[maxn][maxn],dist[maxn];
bool vis[maxn];
void prim()
{
    int ans = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 1; i <= n; i++)
        dist[i] = w[1][i];
    vis[1] = 1;
    for(int i = 1; i < n; i++)
    {
        int maxi = inf,u=-1;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && dist[j] < maxi)
            {
                maxi = dist[j];
                u = j;
            }
        if( u== -1)
        {
            printf("?\n");
            return ;
        }
        ans += maxi;
        vis[u] = 1;
        for(int j = 1; j <= n; j++)
            dist[j] = min(dist[j],w[u][j]);
    }
    printf("%d\n",ans);
}

int main()
{
    int u,v,c;
    while(scanf("%d%d",&m,&n) != EOF&&m)
    {
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                w[i][j] = inf;
        for(int i =0; i < m; i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            w[u][v] = w[v][u] = c;
        }
        prim();
    }
    return 0;
}
