#include <iostream>
#include <algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int Max=100005;
struct  dd
{
    int mm,s,e;
}bbb,cow[Max];
int n,c[Max];
int lowbit(int i)
{
    return i&(-i);
}
bool cmp(dd a,dd b)
{
    if(a.e==b.e)
        return a.s<b.s;
    else
        return a.e>b.e;
}
void add(int i)
{
    while (i<=Max)
    {
        c[i]++;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int ans=0;
    while (i>0)
    {
        ans+=c[i];
        i-=lowbit(i);
    }
    return ans;
}
int main()
{
    int i,s,e,ans[Max];
    while (scanf("%d",&n)&&n)
    {
        memset(c,0,sizeof(c));
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&cow[i].s,&cow[i].e);
            cow[i].s++;
            cow[i].e++;
            cow[i].mm=i;
        }
        sort(cow,cow+n,cmp);
        int times=0;
        bbb.s=bbb.e=-1;
        for (i=0;i<n;i++)
        {
            if (cow[i].s==bbb.s&&cow[i].e==bbb.e)
                times++;
            else
            {
                times=0;
                bbb.s=cow[i].s;
                bbb.e=cow[i].e;
            }
            ans[cow[i].mm]=sum(cow[i].s)-times;
            add(cow[i].s);
        }
        for (i=0;i<n;i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}
