#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=1e6;
const int maxn=1100;
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
    if(cnt<n-1)
        return -1;//无法构成生成树；
    return ans;
}
int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%d",&m);
        memset(p,-1,sizeof(p));
        for(int i=0; i<m; i++)
            scanf("%d%d%d",&E[i].from,&E[i].to,&E[i].w);
        sort(E,E+m);
        printf("%d\n",Kruskal());
    }
    return 0;
}
