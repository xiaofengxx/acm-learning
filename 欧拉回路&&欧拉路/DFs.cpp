#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1100;
const int maxm=maxn*maxn;
int e,head[maxn],pnt[maxm],nxt[maxm],cnt_in[maxn],cnt_out[maxn],ans[maxm];
bool vis[maxm];
int m,n,cnt;
void AddEdge(int u,int v)
{
    pnt[e]=v;
    nxt[e]=head[u];

    head[u]=e++;
}
void DFS(int i)
{
    for(int i=head[i];i!=-1;i=nxt[i])
        if(!vis[i])
        {
            vis[i]=1;
            DFS(pnt[i]);
            ans[cnt++]=pnt[i];
        }
}
int main()
{
    int st;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        e=0;
        memset(head,-1,sizeof(head));
        memset(cnt_in,0,sizeof(cnt_in));
        memset(cnt_out,0,sizeof(cnt_out));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            cnt_out[u]++;
            cnt_in[v]++;
            AddEdge(u,v);
        }
        int cntin=0,cntout=0;
        st=1;
        bool exist=true;
        for(int i=1;i<=n;i++)
        {
            if(cnt_in[i]==cnt_out[i])
                continue;
            if(cnt_in[i]==cnt_out[i]+1)
                cntout++;
            else if(cnt_in[i]+1==cnt_out[i])
            {
                cntin++;
                st=i;
            }
            else
            {
                exist=false;
                break;
            }
        }
        if(!exist||cntin>1||cntout>1)
        {
            puts("No exist!\n");
            continue;
        }
        cnt++;
        DFS(st);
        for(int i=cnt;i>=0;i--)
        {
            printf("%d%s",ans[i],i==0?"\n":"->");
        }
    }
    return 0;
}
