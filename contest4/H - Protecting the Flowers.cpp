#include<cstdio>
#include<algorithm>
using namespace std;
struct dd{
    int t;
    int d;
}niu[100010];
int time;
long long aabb=0;
bool cmp(dd a,dd b)
{
    return a.t*b.d<=a.d*b.t;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&niu[i].t,&niu[i].d);
    sort(niu,niu+n,cmp);
    time=niu[0].t*2;
    for(int i=1;i<n;i++)
    {
        aabb+=time*niu[i].d;
        time+=niu[i].t*2;
    }
    printf("%lld\n",aabb);
    return 0;
}
