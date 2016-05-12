#include<cstdio>
#include<algorithm>
using namespace std;
const int Max=25010;
struct ddd
{
    int x,y;
}a[Max];
int n,T;
int cmp(ddd a,ddd b)
{
    return a.x<b.x;
}
int main()
{
    scanf("%d%d",&n,&T);
    for (int i=1;i<=n;++i)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    a[n+1].x=1000001;
    int t=0,aabb=0,hehe=0;
    bool f=0;
    for (int i=1;i<=n;++i)
        if (a[i].x<=t+1)
            {
                if (aabb<a[i].y) aabb=a[i].y,f=1;
                if (a[i+1].x>t+1 && f)
                    t=aabb,++hehe,f=0;
            }
    if (t<T)
        printf("-1\n");
    else
        printf("%d\n",hehe);
    return 0;
}
