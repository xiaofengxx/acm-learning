#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int inf = 1<<29;
int  n,m,tt;
int vis[1005];
char city[250][30];
int d[1005];
int map[1005][1005];
int dij(int a,int b)
{
    d[a]=20000;
    for(int i=0; i < n; i++ )
    {
        int now = 0 ;
        int x;
        /*
            每一次都从D[] 数组中去找一个D[]最小的值，记录下标。
        */
        for(int j=1 ;j<=n ; j++)
        {
            if(!vis[j]&&now<d[j])
            {
                now=d[j];
                x=j;
            }
        }
        vis[x]=1;
        for(int y=1 ; y<=n ; y++)
        {
            // 松弛操作
            if(d[y] < min(d[x],map[x][y])&&map[x][y]<0x3f3f3f)
                d[y] =min(d[x],map[x][y]);
        }
    }
    return d[b];
}
int naodong()
{
    scanf("%s",city[tt]);
    for(int i=1;i<tt;i++)
        if(strcmp(city[i],city[tt])==0)
            return i;
    tt++;
    return tt-1;
}
int main()
{
    int a,b,c,sum,sd=1;
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
    {
        tt=1;
        memset(map,0x3f3f3f,sizeof(map));
        memset(d,0,sizeof(d));
        memset(vis,0,sizeof(vis));
        while(m--)
        {
            a=naodong();
            b=naodong();
            scanf("%d",&c);
            if(map[a][b]<c)
                continue;
            map[a][b]=map[b][a]=c;
        }
        a=naodong();
        b=naodong();
        sum=dij(a,b);
        printf("Scenario #%d\n%d tons\n\n",sd,sum);
        sd++;
    }
}
