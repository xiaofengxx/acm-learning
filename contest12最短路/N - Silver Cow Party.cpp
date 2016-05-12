#include<cstdio>
#include<cstring>
using namespace std;
const int inf = 1<<29;
int  n,m,as;
int vis[1005];
int d[1005][2];
int map[1005][1005];
void dij(int a)
{
    memset(vis,0,sizeof(vis));
    d[a][as]=0;
    for(int i=0; i < n; i++ )
    {
        int now = inf ;
        int x;
        for(int j=1 ;j<=n ; j++)
        {
            if(!vis[j]&&now >d[j][as])
            {
                now=d[j][as];
                x=j;
            }
        }
        vis[x]=1;
        for(int y=1 ; y<=n ; y++)
        {
            if(d[y][as] > d[x][as]+map[x][y])
                d[y][as] =d[x][as]+map[x][y];
        }
    }
}
int main()
{
    int mm;
    int a,b,c,ds;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        mm=0;
        scanf("%d",&ds);
        memset(map,0x3f3f3f,sizeof(map));
        memset(d,0x3f3f3f,sizeof(d));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(map[a][b]<c)
                continue;
            map[a][b]=c;
        }
        as=0;
        dij(ds);
        for(int i=1;i<=n;i++)
        {
            for(int u=i;u<=n;u++)
            {
                m=map[i][u];
                map[i][u]=map[u][i];
                map[u][i]=m;
            }
        }
        as=1;
        dij(ds);
        for(int i=1;i<=n;i++)
        {
            d[i][0]+=d[i][1];
            if(d[i][0]>=0x3f3f3f)
                d[i][0]=0;
            if(d[i][0]>mm)
                mm=d[i][0];
        }
        printf("%d\n",mm);
    }
}
