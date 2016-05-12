#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int inf= 1<<29;
const int maxn=1100;
const int maxm=maxn*maxn;
int n,m,dist[maxm];
struct Edge
{
    int from;
    int to;
    int c;
}E[maxm];
bool Bellman_frod(int st)
{
    for(int i=0;i<=n;i++)
        dist[i]=inf;
    dist[st]=0;
    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
            if(dist[E[j].to]>dist[E[j].from]+E[j].c)
                dist[E[j].to]=dist[E[j].from]+E[j].c;
    for(int j=0;j<n;j++)
        if(dist[E[j].to]>dist[E[j].from]+E[j].c)
            return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0 ;i<m;i++)
            scanf("%d%d%d",&E[i].from,&E[i].to,&E[i].c);
    }
}
