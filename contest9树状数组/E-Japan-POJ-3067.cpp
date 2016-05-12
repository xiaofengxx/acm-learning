#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1005;
int c[maxn];
struct dd{
    int x,y;
}city[1000010];
int lowbit(int x)
{
    return x&-x;
}
void add(int x)
{
    while(x <= maxn)
    {
        c[x]++;
        x += lowbit(x);
    }
}
long long sum(int x)
{
    long long  ret = 0;
    while(x > 0)
    {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}
bool cmp(struct dd a,struct dd b)
{
    if(a.x==b.x)
        return a.y<=b.y;
    else
        return a.x<b.x;
}
int main()
{
    int tt,t=1,n,m,mm;
    long long ans;
    scanf("%d",&tt);
    while(tt-- >0)
    {
        ans=0;
        memset(c,0,sizeof(c));
        scanf("%d%d%d",&n,&m,&mm);
        for(int i=0;i<mm;i++)
            scanf("%d%d",&city[i].x,&city[i].y);
        sort(city,city+mm,cmp);
        for(int i=0;i<mm;i++)
        {
            add(city[i].y);
            ans+=(sum(m)-sum(city[i].y));
        }
        printf("Test case %d: %lld\n",t,ans);
        t++;
    }
    return 0;
}
