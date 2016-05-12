#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int c[500005],a[500005];
long long ans;
struct dd{
    int mm;
    int val;
}cc[500005];
bool cmp(struct dd a,struct dd b)
{
    return a.val<b.val;
}
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int maxn)
{
    while(x <= maxn)
    {
        c[x] ++;
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
void start(int tt)
{
    for(int i=1;i<=tt;i++)
        c[i]=0;
    ans=0;
    for(int i=1;i<=tt;i++)
    {
        scanf("%d",&cc[i].val);
        cc[i].mm=i;
    }
    sort(cc+1,cc+tt+1,cmp);
    for(int i=1;i<=tt;i++)
        a[cc[i].mm]=i;

}
int main()
{
    int tt;
    while(scanf("%d",&tt)&&tt)
    {
        start(tt);
        for(int i=1;i<=tt;i++)
        {
            ans+=sum(tt)-sum(a[i]);
            add(a[i],tt);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
