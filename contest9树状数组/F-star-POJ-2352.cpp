#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define maxn 32005
int c[maxn],ans[15005];
int lowbit(int x)
{
    return x&-x;
}
void add(int x)
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
int main()
{
    int tt = 0,x,y;
    scanf("%d",&tt);
    for(int i=1;i<=tt;i++)
    {
        scanf("%d%d",&x,&y);
        ans[sum(++x)]++;
        add(x);
    }
    for(int i=0;i<tt;i++)
        printf("%d\n",ans[i]);
    return 0;
}
