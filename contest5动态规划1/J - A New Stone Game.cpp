#include <stdio.h>
#include <string.h>
#define AAA 1500
int Max(int a,int b)
{
    return a>b?a:b;
}
char aa[AAA];
char bb[AAA];
int dp[AAA][AAA];
int main()
{
    int nl1,nl2;
    while(scanf("%d%s%d%s",&nl1,aa+1,&nl2,bb+1)!=EOF)
    {
        int i,j;
        for(i=0;i<=nl1;i++)
            dp[i][0]=0;
        for(j=0;j<=nl2;j++)
            dp[0][j]=0;
        for(i=1;i<=nl1;i++)
        {
            for(j=1;j<=nl2;j++)
            {
                if(aa[i]==bb[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                {
                    if(dp[i][j-1]>dp[i-1][j])
                        dp[i][j]=dp[i][j-1];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        printf("%d\n",Max(nl1-dp[nl1][nl2],nl2-dp[nl1][nl2]));
    }
    return 0;
}
