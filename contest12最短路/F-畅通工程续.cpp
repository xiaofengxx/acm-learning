#include<cstdio>
#include<cstring>
const int inf = 1<<29;
int  n,m;
int vis[1005];
int d[1005];
int map[1005][1005];
int  dij(int a,int b)
{
    d[a]=0;
    for(int i=0; i < n; i++ )
    {
        int now = inf ;
        int x;
        /*
            每一次都从D[] 数组中去找一个D[]最小的值，记录下标。
        */
        for(int j=1 ;j<=n ; j++)
        {
            if(!vis[j]&&now >d[j])
            {
                now=d[j];
                x=j;
            }
        }
        vis[x]=1;
        for(int y=1 ; y<=n ; y++)
        {
            // 松弛操作
            if(d[y] > d[x]+map[x][y])
                d[y] =d[x]+map[x][y];
        }
    }
    return d[b];
}
int main()
{
    int a,b,c,sum;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(map,0x3f3f3f,sizeof(map));
        memset(d,0x3f3f3f,sizeof(d));
        memset(vis,0,sizeof(vis));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            a++;
            b++;
            if(map[a][b]<c)
                continue;
            map[a][b]=map[b][a]=c;
        }
        scanf("%d%d",&a,&b);
        sum=dij(a+1,b+1);
        if(sum<0x3f3f3f)
            printf("%d\n",sum);
        else
            printf("-1\n");
    }
}
