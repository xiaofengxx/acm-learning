#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int inf = 1<<29;
const int maxn = 1e4;
const int maxm = maxn * maxn;
int e,head[maxn],pnt[maxm],nxt[maxm],flow[maxm];
int n,m,level[maxn],st,des;
queue<int> q;
void addedge(int u,int v,int f)
{
    pnt[e] = v;nxt[e] = head[u];flow[e] = f;head[u] = e++;
    pnt[e] = u;nxt[e] = head[v];flow[e] = 0;head[v] = e++;
}
bool bfs(int st,int des)
{
    memset(level,0,sizeof(level));
    level[st] = 1;
    q.push(st);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i != -1; i = nxt[i])
            if(flow[i]&& !level[pnt[i]])
            {
                level[pnt[i]] = level[u] + 1;
                q.push(pnt[i]);
            }
    }
    return level[des];
}
int dfs(int u,int maxf)
{
    if(u == des|| maxf == 0)
        return maxf;
    for(int i = head[u],t; i != -1; i = nxt[i])
        if(level[pnt[i]] == level[u] + 1&&
            (t = dfs(pnt[i],min(flow[i],maxf))))
            {
                flow[i] -= t;
                flow[i^1] += t;
                return t;
            }
    return level[u] = 0;
}
int maxflow(int st,int des)
{
    int ans = 0;
    while(bfs(st,des))
        while(1)
        {
            int f = dfs(st,des);
            if(f == 0)
                break;
            ans += f;
        }
    return ans;
}
int main()
{
    int u,v,f;
    int pig[1005],pigs[1005],pp,ww,tt;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        e = 0;
        memset(head,-1,sizeof(head));
        memset(pig,-1,sizeof(pig));
        for(int i=1;i<=n;i++)
            scanf("%d",&pigs[i]);
        for(int i = 1; i <= m; i++)
        {
            pp=0;
            scanf("%d",&ww);
            while(ww--)
            {
                scanf("%d",&tt);
                if(pig[tt]>0)
                    addedge(pig[tt],i,inf);
                else
                    pp+=pigs[tt];
                pig[tt]=i;
            }
            if(pp>0)
                addedge(0,i,pp);
            scanf("%d",&pp);
            addedge(i,m+1,pp);
        }
        /*
        for(int i=0;i<=m;i++)
        {
            for(int ll=head[i];ll!=-1;ll=nxt[ll])
            {
                printf("%d---->%d  %d\n",i,pnt[ll],flow[ll]);
            }
        }
        */
        st=0,des=m+1;
        printf("%d\n",maxflow(st,des));
    }
    return 0;
}
