#include<cstdio>
#define MM 500005
using namespace std;
bool dp[10000000]={false};
int aa[MM]={0},a;
int main()
{
    for(int n=1;n<=500000;n++)
    {
        if(aa[n-1]-n<=0||dp[aa[n-1]-n])
            aa[n]=aa[n-1]+n;
        else
            aa[n]=aa[n-1]-n;
        dp[aa[n]]=true;
    }
    while(scanf("%d",&a)!=EOF&&a!=-1)
        printf("%d\n",aa[a]);
    return 0;
}
