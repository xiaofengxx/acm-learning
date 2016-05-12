#include<cstdio>
#include<cstring>
const int inf = 1<<29;
int  n,m,vv;
int vis[1005];
int d[1005];
int kk;
int map[1005][1005];
void dij()
{
    kk=inf;
    for(int k=1;k<=n;k++)
    {
        memset(d,0x3f3f3f,sizeof(d));
        memset(vis,0,sizeof(vis));
        d[k]=0;
        for(int i=0; i < n; i++ )
        {
            int now = inf ;
            int x;
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
                if(d[y] > d[x]+map[x][y])
                    d[y] =d[x]+map[x][y];
            }
        }
        m=0;
        for(int i=1;i<=n;i++)
            if(d[i]>m)
            {
                m=d[i];
            }
        if(m>=0x3f3f3f)
            continue;
        if(m<kk&&m!=0)
        {
            kk=m;
            vv=k;
        }
    }
}
int main()
{
    int a,b,c;
    while(scanf("%d",&n)!=EOF&&n)
    {
        memset(map,0x3f3f3f,sizeof(map));
        for(int a=1;a<=n;a++)
        {
            scanf("%d",&m);
            while(m--)
            {
                scanf("%d%d",&b,&c);
                if(map[a][b]<c)
                    continue;
                map[a][b]=c;
            }
        }
        dij();
        printf("%d %d\n",vv,kk);
    }
}
