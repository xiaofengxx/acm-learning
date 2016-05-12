#include<cstdio>
#define N 10010
int main()
{
    int n,m,f[N],j;
    scanf("%d",&n);
    f[0]=1;
    f[1]=2;
    for(int i=0; i<n; i++)
    {
        scanf("%d",&m);
        for(j=2; j<=m; j++)
            f[j]=f[j-1]+f[j-2];
        printf("Scenario #%d:\n%d\n\n",i+1,f[m]);
    }
    return 0;
}
