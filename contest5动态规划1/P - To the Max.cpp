#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[105][105];
int main()
{
    int i,j,k,hehe,n,x;
    while(scanf("%d",&n) != EOF)
    {
        hehe = -200;
        memset(dp,0,sizeof(dp));
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
            {
                scanf("%d",&x);
                dp[i][j] = dp[i][j-1]+x;
            }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= i; j++)
            {
                int t = -1;
                for(k = 1; k <= n; k++)
                {
                    t = max(t,0) + dp[k][i] - dp[k][j-1];
                    hehe = max(hehe,t);                }
            }
        }
        printf("%d\n",hehe);
    }
}
