#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 110;
const int inf = 1 << 29;
int  n,w[maxn][maxn],dist[maxn];
bool vis[maxn];
int prim()
{
    int ans = 0;
    memset(vis,0,sizeof(vis));
    memset(dist,inf,sizeof(dist));
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
    char u[3],v[3];
    int ta,c,x,y;
    while(scanf("%d",&n)&&n)
    {
        int l=n-1;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                w[i][j] = inf;
        while(l--)
        {
            scanf("%s%d",u,&ta);
            x=u[0]-'A'+1;
            while(ta--)
            {
                scanf("%s%d",v,&c);
                y=v[0]-'A'+1;
                w[x][y] = w[y][x] = c;
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}




