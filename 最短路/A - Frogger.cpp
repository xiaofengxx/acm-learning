#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
const int maxn=1100;
const int inf= 1 << 29 ;
double map[maxn][maxn], a[maxn], b[maxn];
int n,ans=1;
int main()
{
    while(scanf("%d",&n)!=EOF&& n)
    {
        for(int i=1; i<=n; i++)
            scanf("%lf%lf",&a[i],&b[i]);
        for(int i=1; i<n; i++)
            for(int j=i+1; j<=n; j++)
                map[i][j]=map[j][i]=sqrt((a[j]-a[i])*(a[j]-a[i])+(b[j]-b[i])*(b[j]-b[i]));
        for(int k=1; k<=n; k++)
            for(int i=1; i<n; i++)
                for(int j=i+1; j<=n; j++)
                    if(map[i][j]>max(map[i][k],map[k][j]))
                        map[i][j]=map[j][i]=max(map[i][k],map[k][j]);
        printf("Scenario #%d\n",ans);
        printf("Frog Distance = %.3lf\n\n",map[1][2]);
        ans++;
    }
    return 0;
}
