#include<cstdio>
#include<string.h>
int next[500050],mm,n,hh[500050];
char ss[500050];
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
    int tt;
    while(scanf("%s",ss)!=EOF)
    {
        mm=0;
        n=strlen(ss);
        hehe(n);
        hh[0]=n;
        while(next[n]>0)
        {
            n=next[n];
            hh[++mm]=n;
        }
        for(;mm>=0;mm--)
        {
            printf("%d ",hh[mm]);
        }
        printf("\n");
    }
    return 0;
}
