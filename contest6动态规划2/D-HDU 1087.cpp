#include<cstdio>
int aa[1010];
int dp[1010];
int main()
{
    int n,mm,mmax;
    while(scanf("%d",&n)&&n!=0)
    {
        mmax=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&aa[i]);
            dp[i]=aa[i];
            mm=0;
            for(int p=i-1;p>=0;p--)
            {
                if(aa[i]>aa[p]&&dp[p]>mm)
                    mm=dp[p];
            }
            dp[i]+=mm;
            if(dp[i]>mmax)
                mmax=dp[i];
        }
        printf("%d\n",mmax);
    }
    return 0;
}
