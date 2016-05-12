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
    pnt[e] = v;
    nxt[e] = head[u];
    flow[e] = f;
    head[u] = e++;
    pnt[e] = u;
    nxt[e] = head[v];
    flow[e] = 0;
    head[v] = e++;
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
    while(scanf("%d%d",&m,&n) != EOF)
    {
        e = 0;
        memset(head,-1,sizeof(head));
        for(int i = 0; i < m; i++)
        {
            int u,v,f;
            scanf("%d%d%d",&u,&v,&f);
            addedge(u,v,f);
        }
        st = 1;des = 4;
        printf("%d\n",maxflow(st,des));
    }
    return 0;
}
