#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=5e6;
const int maxn=2100;
int n,m;
struct Node
{
    int from;
    int to;
    int w;
    bool operator < (const Node &a)const
    {
        return w<a.w;
    }
} E[maxm];
int p[maxn];
int Find(int x)
{
    if(p[x]==-1)
        return x;
    return p[x]=Find(p[x]);
}
int Kruskal()
{
    int ans=0,cnt=0;
    for(int i=0; i<m; i++)
    {
        int x=Find(E[i].from);
        int y=Find(E[i].to);
        if(x!=y)
        {
            cnt++;
            ans+=E[i].w;
            p[x]=y;
        }
    }
    return ans;
}
int main()
{
    char h[maxn][9];
    int cnt;
    while(scanf("%d",&n)!=EOF&&n)
    {
        m=0;
        memset(p,-1,sizeof(p));
        for(int i=0;i<n;i++)
            scanf("%s",h[i]);
        for(int i=0;i<n;i++)
        {
            for(int ss=i+1;ss<n;ss++)
            {
                cnt=0;
                for(int sd=0;sd<7;sd++)
                    if(h[i][sd]!=h[ss][sd])
                        cnt++;
                E[m].from=i;
                E[m].to=ss;
                E[m].w=cnt;
                m++;
            }
        }
        sort(E,E+m);
        printf("The highest possible quality is 1/%d.\n",Kruskal());
    }
    return 0;
}
