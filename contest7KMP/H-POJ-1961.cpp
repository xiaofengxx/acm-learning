#include<cstdio>
#include<string.h>
int next[1000005];
char ss[1000005];
void hehe(int n)
{
    next[0] = -1;
    int i = 0;
    int j = -1;
    while( i < n )
    {
        if(j == -1 || ss[i] == ss[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
    return ;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n==0)
    {
        scanf("%s",ss);
        hehe(n);
        for(int i=1;i<=n;i++)
            printf("%d  ",next[i]);
        printf("\n");
    }
    return 0;
}
