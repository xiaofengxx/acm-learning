#include <cstdio>
#include <cstring>
char aa[120][33], bb[120][33];
int dp[120][120];
int main()
{
    int i,j,nl1,nl2;
    while(scanf("%s", aa[0]) != EOF)
    {
        nl1 = 1, nl2 = 0;
        while (scanf("%s", aa[nl1]) && strcmp(aa[nl1], "#"))
            nl1++;
        while (scanf("%s", bb[nl2]) && strcmp(bb[nl2], "#"))
            nl2++;
        for (i = 0; i <= nl1; i++)
            for (j = 0; j <= nl2; j++)
                dp[i][j] = 0;
        for (i = nl1-1; i >= 0; i--) for (j = nl2-1; j >= 0; j--)
        {
            if (strcmp(aa[i], bb[j]))
                dp[i][j] = dp[i+1][j+1];
            else
                dp[i][j] = dp[i+1][j+1] + 1;
            if (dp[i][j] < dp[i+1][j])
                dp[i][j] = dp[i+1][j];
            if (dp[i][j] < dp[i][j+1])
                dp[i][j] = dp[i][j+1];
        }
        i = j = 0;
        while (i < nl1 && j < nl2)
        {
            if (dp[i][j] == dp[i+1][j+1] +1)
            {
                printf("%s", aa[i]);
                if (dp[i+1][j+1]) printf(" ");
                else printf("\n");
                i++;j++;
            }
            else if (dp[i+1][j] == dp[i][j])
                i++;
            else
                j++;
        }
    }
    return 0;
}
