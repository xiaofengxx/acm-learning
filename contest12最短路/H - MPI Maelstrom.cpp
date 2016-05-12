#include<cstdio>
#include<cstring>
const int inf = 1<<29;
int n;
int vis[1005];
int d[1005];
int map[1005][1005];
void dij()
{
    d[1]=0;
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
}
int main()
{
    int a,b,c;
    char naodong[20];
    while(scanf("%d",&n)!=EOF)
    {
        memset(map,0x3f3f3f,sizeof(map));
        memset(d,0x3f3f3f,sizeof(d));
        memset(vis,0,sizeof(vis));
        for(int a=2;a<=n;a++)
        {
            for(b=1;b<a;b++)
            {
                scanf("%s",naodong);
                if(naodong[0]=='x')
                    continue;
                else
                    sscanf(naodong,"%d",&c);
                if(map[a][b]<c)
                    continue;
                map[a][b]=map[b][a]=c;
            }
        }
        dij();
        a=0;
        for(int i=1;i<=n;i++)
            if(d[i]>a&&d[i]<0x3f3f3f)
                a=d[i];
        printf("%d\n",a);
    }
}
