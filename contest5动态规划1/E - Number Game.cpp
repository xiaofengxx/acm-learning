#include <stdio.h>
#include <string.h>
#define AAA 1000
char aa[AAA];
char bb[AAA];
int dp[AAA][AAA];
int main()
{
    while(scanf("%s%s",aa+1,bb+1)>0)
    {
        int nl1=strlen(aa+1);
        int nl2=strlen(bb+1);
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
        printf("%d\n",dp[nl1][nl2]);
    }
    return 0;
}
