#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxm=1e6;
const int maxn=1100;
int p[maxn];
int n,m,op;
struct Node
{
    int from;
    int to;
    double w;
    bool operator < (const Node &a)const
    {
        return w<a.w;
    }
} E[maxm];
struct point{
    double x;
    double y;
};
int Find(int x)
{
    if(p[x]==-1)
        return x;
    return p[x]=Find(p[x]);
}
void Kruskal()
{
    int cnt=0;
    for(int i=0; i<op; i++)
    {
        int x=Find(E[i].from);
        int y=Find(E[i].to);
        if(x!=y)
        {
            p[x]=y;
            if(cnt==m-n-1)
            {
                printf("%.2lf\n",E[i].w);
               return ;
            }
            cnt++;
        }
    }
}
int main()
{
    int tt;
    struct point hh[1100];
    double len;
    scanf("%d",&tt);
    while(tt--)
    {
        op=0;
        scanf("%d%d",&n,&m);
        memset(p,-1,sizeof(p));
        for(int i=1;i<=m;i++)
            scanf("%lf%lf",&hh[i].x,&hh[i].y);
        for(int i=1; i<=m; i++)
            for(int g=i+1;g<=m;g++)
            {
                len=sqrt(1.0*(hh[i].x-hh[g].x)*(hh[i].x-hh[g].x)+1.0*(hh[i].y-hh[g].y)*(hh[i].y-hh[g].y));
                E[op].w=len;
                E[op].from=i;
                E[op].to=g;
                op++;
            }
        sort(E,E+op);
        Kruskal();
    }
    return 0;
}
