#include<cstdio>
#include<cstring>
//const int inf = 1<<29;
int  n,m,tt,p=1,lk;
int vis[1005];
double d[1005];
char qian[1005][20];
double map[1005][1005];
void dij()
{
    double cc;
    d[1]=1;
    for(int k=1;k<=n;k++)
    {
        cc=d[k];
        for(int i=1;i<=n;i++)
            d[i]=0x3f3f3f;
        memset(vis,0,sizeof(vis));
        d[k]=cc;
        for(int i=0; i < n; i++ )
        {
            double now = 0x3f3f3f ;
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
                if(d[y] > d[x]*map[x][y]&&y!=x)
                    d[y] =d[x]*map[x][y];
            }
        }
        printf("\n %lf   %lf   %lf  \n ",d[1],d[2],d[3]);
    }
    if(d[1]!=1&&d[1]<0x3f3f3f)
        printf("Case %d: Yes\n",p);
    else
    printf("Case %d: NO\n",p);
}
int naodong()
{
    scanf("%s",qian[tt]);
    for(int i=1;i<tt;i++)
        if(strcmp(qian[i],qian[tt])==0)
            return i;
    tt++;
    return tt-1;
}
int main()
{
    int a,b;
    double c;
    char l[20];
    while(scanf("%d",&n)!=EOF&&n)
    {
        tt=1;
        for(int i=1;i<=n;i++)
            for(int u=1;u<=n;u++)
                map[i][u]=0;
        for(int i=1;i<=n;i++)
            naodong();
        scanf("%d",&lk);
        for(int i=1;i<=lk;i++)
        {
            a=naodong();
            scanf("%s",&l);
            sscanf(l,"%lf",&c);
            b=naodong();
            map[a][b]=c;
            map[b][a]=1/c;
        }
        for(int i=1;i<=n;i++)
            {
                for(int u=1;u<=n;u++)
                    printf("%lf     ",map[i][u]);
                printf("\n");
            }
        dij();
        p++;
    }
}
