#include<cstdio>
#include<cstring>
#include <iostream>
using namespace std;
const int maxn=200010;
int sum[maxn*4];

void PushUp(int o)
{
    sum[o]=max(sum[o*2],sum[o*2+1]);
}

void build(int l,int r,int o)
{
    if(l==r)
    {
        scanf("%d",&sum[o]);
        return;
    }

    int m=(l+r)/2;
    build(l,m,o*2);
    build(m+1,r,o*2+1);
    PushUp(o);
}

void update(int x,int d,int l,int r,int o)
{

    if(l==r&&r==x)
    {
        sum[o]=d;
        return;
    }

    int m=(l+r)/2;

    if(x<=m)
        update(x,d,l,m,o*2);
    else
        update(x,d,m+1,r,o*2 +1);
    PushUp(o);
}

int query(int a,int b,int l,int r,int o)
{
    if(a<=l&&r<=b)
        return sum[o];
    int res=0,res2=0;
    int m=(l+r)/2;
    if(a<=m)
        res=query(a,b,l,m,o*2);
    if(m<b)
        res2=query(a,b,m+1,r,o*2+1);
    return max(res,res2);
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        build(1,n,1);
        char op[3];
        while(m--)
        {
            int a,b;
            scanf("%s",op);
            scanf("%d%d",&a,&b);
            if(op[0]=='U')
                update(a,b,1,n,1);
            else if(op[0]=='Q')
                printf("%d\n",query(a,b,1,n,1));
        }
    }
    return 0;
}
