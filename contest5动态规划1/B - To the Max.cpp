#include<cstdio>
long long dp[22][22][22];
long long hh(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0)
        return 1;
    else if(a>20||b>20||c>20)
    {
        dp[20][20][20]=hh(20,20,20);
            return dp[20][20][20];
    }
    else if(dp[a][b][c]!=-1)
        return dp[a][b][c];
    else if(a<b&&b<c)
    {
        dp[a][b][c]=hh(a,b,c-1)+hh(a, b-1,c-1)-hh(a,b-1,c);
        return dp[a][b][c];
    }
    else
    {
        dp[a][b][c]=hh(a-1,b,c)+hh(a-1,b-1,c)+hh(a-1,b,c-1)-hh(a-1,b-1,c-1);
        return dp[a][b][c];
    }
}
int main()
{
    int a,b,c;
    for(int i=0;i<22;i++)
        for(int o=0;o<22;o++)
            for(int k=0;k<22;k++)
                dp[i][o][k]=-1;
    while(1)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==-1&&b==-1&&c==-1)
            break;
        printf("w(%d, %d, %d) = %lld\n",a,b,c,hh(a,b,c));
    }
    return 0;
}
