#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 200010;
int a[100010],c[maxn],n,m;
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int d)
{
    while(x <= m+n)
    {
        c[x] +=d;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int ret = 0;
    while(x > 0)
    {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
int main()
{
    int tt,low,p;
    scanf("%d",&tt);
    while(tt-- >0)
    {
        memset(c,0,sizeof(c));
        scanf("%d%d",&m,&n);
        low=n;
        for(int i=1;i<=m;i++)
        {
            a[i]=n+i;
            add(a[i],1);
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p);
            add(a[p],-1);
            if(i!=1)
                printf(" ");
            printf("%d",sum(a[p]));
            a[p]=low;
            add(a[p],1);
            low--;
        }
        printf("\n");
    }
    return 0;
}
