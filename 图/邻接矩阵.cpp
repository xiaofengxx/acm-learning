#include<cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000;
const int maxm = maxn * maxn / 2;
int n,m;
int e,head[maxn],next[maxm],pnt[maxm],cost[maxm];
void AddEdge(int u,int v,int c)
{
    pnt[e] = v;
    cost[e] = c;
    next[e] = head[u];
    head[u] = e++;
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        e = 0;
        memset(head,-1,sizeof(head));
        for(int i = 0; i < m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
        }
        for(int u = 1; u <= n; u++)
        {
            printf("%d:",u);
            for(int i = head[u]; i != -1; i = next[i])
                printf("%d ",pnt[i]);
            printf("\n");
        }
    }
}
