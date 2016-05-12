#include<cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1000;
struct Node
{
    int v;int c;
    Node(){}
    Node(int sc,int sv)
    {
        v = sv;
        c = sc;
    }
};
vector<Node> g[maxn];
int n,m;

void AddEdge(int u,int v,int c)
{
    g[u].push_back(Node(v,c));
}
int main()
{
    while(scanf("%d%d",&n,&m) != EOF)
    {
        for(int i = 1; i < n; i++)
            g[i].clear();
        for(int i = 0; i < m; i++)
        {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,c);
        }
        for(int u = 1; u <= n; u++)
        {
            printf("%d:",u);
            for(int i = 0; i < g[u].size(); i++)
                printf("%d ",g[u][i].v);
            printf("\n");
        }
    }
}
