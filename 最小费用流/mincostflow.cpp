//最小费用最大流；
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1<<30;
const int maxn=1001;
const int maxm=maxn*maxn;
int e,pnt[maxm],head[maxn],cost[maxm],next[maxm],flow[maxm];
int st,des;
int n,m,dist[maxn],pre[maxn];
bool vis[maxn];
queue<int> q;
void AddEdge(int u,int v,int c,int f)
{
    pnt[e]=v;next[e]=head[u];cost[e]=c;flow[e]=f;head[u]=e++;
    pnt[e]=u;next[e]=head[v];cost[e]=-c;flow[e]=0;head[v]=e++;
}
bool spfa(int st,int des)
{
    for(int i=st; i<=des; i++)
        dist[i]=inf;
    dist[st]=0;
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u]; i!=-1; i=next[i])
            if(flow[i]&&dist[pnt[i]]>dist[u]+cost[i])
            {
                dist[pnt[i]]=dist[u]+cost[i];
                pre[pnt[i]]=i;//记录边的编号；
                if(!vis[pnt[i]])
                {
                    q.push(pnt[i]);
                    vis[pnt[i]]=1;
                }
            }
    }
    return dist[des]!=inf;
}
int MincostFlow(int st,int des)
{
    int ans=0;
    while(spfa(st,des))
    {
        int mini=inf;
        for(int i=pre[des]; i!=-1; i=pre[pnt[i^1]]) //从后到前依次遍历；
            mini=min(mini,flow[i]);//求最小的流;
        for(int i=pre[des]; i!=-1; i=pre[pnt[i^1]])
        {
            flow[i]-=mini;
            flow[i^1]+=mini;
        }
        ans+=mini*dist[des];//最大流乘上最短距离；
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        st=e=0;
        des=n+1;
        memset(head,-1,sizeof(head));
        memset(pre,-1,sizeof(pre));
        for(int i=0; i<m; i++)
        {
            int u,v,c;
           scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c,1);
            AddEdge(v,u,c,1);
        }
        AddEdge(st,1,0,2);
        AddEdge(n,des,0,2);
        printf("%d\n",MincostFlow(st,des));
    }
}
