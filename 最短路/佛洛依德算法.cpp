#include <cstdio>
#include <cstring>
const int inf = 0x3f3f3f;
int vis[1005];
int d[1005];
int map[1005][1005];
int main()
{
    int m,n,a,b,c;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(map,0x3f3f3f,sizeof(map));
        memset(d,0x3f3f3f,sizeof(d));
        memset(vis,0,sizeof(vis));
        d[1] = 0;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(map[a][b] < c)
                continue ;
            map[a][b] = map[b][a] = c;
        }
        for(int k = 1; k <= n; k++)
            for(int i = 1;i <= n; i++)
                for(int j = 1; j <= n; j++)
                    if(map[i][j] > map[i][k] + map[k][j])
                        map[i][j] = map[i][k] + map[k][j];
        printf("%d\n",w[1][n]);
    }
}
