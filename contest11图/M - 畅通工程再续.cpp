#include<cstdio>
#include<cstring>
#include<iostream>
#include<math.h>
using namespace std;
const int inf=1<<29;
const int maxn=1100;
double w[maxn][maxn],dist[maxn];
bool vis[maxn];
int n,m;
void  Prim()
{
    double ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
        dist[i]=w[1][i];
    vis[1]=1;
    for(int i=1; i<n; i++)
    {
        double mini=inf;
        int u=-1;
        for(int j=1; j<=n; j++)
            if(!vis[j]&&dist[j]<mini)
            {
                mini=dist[j];
                u=j;
            }
        if(u==-1)
            {
                printf("oh!\n");
                return ;
            }
        ans+=mini;
        vis[u]=1;
        for(int j=1; j<=n; j++)
            dist[j]=min(dist[j],w[u][j]);
    }
    printf("%.1lf\n",ans*100);
}
int main()
{
    double gg[2][maxn],x,y,sum,ssxx,x1,y1;
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%lf%lf",&gg[0][i],&gg[1][i]);
        for(int i=1;i<=n;i++)
        {
            x=gg[0][i];
            y=gg[1][i];
            w[i][i]=inf;
            for(int p=i+1;p<=n;p++)
            {
                x1=gg[0][p];
                y1=gg[1][p];
                ssxx=1.0*(x-x1)*(x-x1)+1.0*(y-y1)*(y-y1);
                sum=sqrt(ssxx);
                if(sum<=1000&&sum>=10)
                    w[i][p]=w[p][i]=sum;
                else
                    w[i][p]=w[p][i]=inf;
            }
        }
        Prim();
    }
    return 0;
}





