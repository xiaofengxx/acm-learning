#include <stdio.h>
#define AAA 5005
char aa[AAA];
char bb[AAA];
short dp[AAA][AAA];
int n,nl1;
int main()
{
    while(scanf("%d%s",&nl1,aa+1)!=EOF)
    {
        bb[nl1+2]='\0';
        for(int i=1;i<=nl1;i++)
            bb[i]=aa[nl1-i+1];
        int nl2=nl1;
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
        printf("%d\n",nl1-dp[nl1][nl2]);
    }
    return 0;
}
