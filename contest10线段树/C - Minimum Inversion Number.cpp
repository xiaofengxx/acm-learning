#include<cstdio>
#include<cstring>
const int maxn=100010;
int sum[maxn*4];

void PushUp(int o)
{
    sum[o]=sum[o*2]+sum[o*2+1];
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
        sum[o]+=d;
        return;
    }

    int m=(l+r)/2;

    if(x<=m)
        update(x,d,l,m,o<<1);
    else
        update(x,d,m+1,r,o<<1 +1);
    PushUp(o);
}

int query(int a,int b,int l,int r,int o)
{
    if(a<=l&&r<=b)
        return sum[o];
    int res=0;
    int m=(l+r)/2;
    if(a<=m)
        res+=query(a,b,l,m,o*2);
    if(m<b)
        res+=query(a,b,m+1,r,o*2+1);
    return res;
}
int main()
{
    int t;
    int n;
    scanf("%d",&t);
    int tmd=0;
    while(t--)
    {
        memset(sum,0,sizeof(sum));
        scanf("%d",&n);
        build(1,n,1);
        printf("Case %d:\n",++tmd);
        char op[10];
        while(~scanf("%s",op)&&op[0]!='E')
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if(op[0]=='A')
            {
                update(a,b,1,n,1);
            }
            else if(op[0]=='S')
            {
                update(a,-b,1,n,1);
            }
            else
            {
                printf("%d\n",query(a,b,1,n,1));
            }
            for(int i=1;i<=n*4;i++)
                printf("%d  ",sum[i]);
            printf("\n");
        }
    }
    return 0;
}
