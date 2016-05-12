#include<cstdio>
#include<cstring>
const int maxn=100010;
int sum[maxn*4],add[maxn*4];
void PushUp(int o)
{
    sum[o]=sum[o*2]+sum[o*2+1];
}
void build(int l,int r,int o)
{
    if(l==r)
    {
        sum[o]=1;
        return;
    }
    int m=(l+r)/2;
    build(l,m,o*2);
    build(m+1,r,o*2+1);
    PushUp(o);
}
void Push_Down(int rt,int m)
{
    if (add[rt])
    {
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1] = add[rt] * (m - (m >> 1));
        sum[rt<<1|1] = add[rt] * (m >> 1);
        add[rt] = 0;
    }
}
void update(int x,int d,int c,int l,int r,int o)
{
    if(x<=l&&r<=d)
    {
        add[o]=c;
        sum[o]=c*(r-l+1);
        return;
    }
    Push_Down(o,r-l+1);
    int m=(l+r)/2;
    if(x<=m)
        update(x,d,c,l,m,o<<1);
    if(d>m)
        update(x,d,c,m+1,r,o*2 +1);
    PushUp(o);
}
int main()
{
    int tt;
    int n,t,p=1,a,b,c;
    scanf("%d",&tt);
    while(tt--)
    {
        memset(sum,0,sizeof(sum));
        memset(add,0,sizeof(add));
        scanf("%d%d",&n,&t);
        build(1,n,1);
        for(int i=0;i<t;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",p,sum[1]);
        p++;
    }
    return 0;
}
