#include<cstdio>
#include<algorithm>
#include<math.h>
using namespace std;
bool cmp(double a,double b)
{
    return a<b;
}
int main()
{
    double c[105];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%lf",&c[i]);
        while(n>1)
        {
            sort(c,c+n,cmp);
            c[n-2]=2*sqrt(c[n-1]*c[n-2]);
            n--;
        }
        printf("%.3lf\n",c[0]);
    }
    return 0;
}
