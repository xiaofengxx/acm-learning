#include<cstdio>
#include<string.h>
int next[10005],mm,n,n1;
char ss[10005],aa[1000010];
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
void kmp()
{
    int j=0,i=0;
    while(j<n1)
    {
        if(i==-1||ss[i]==aa[j])
        {
            i++;
            j++;
        }
        else
            i=next[i];
        if(i>=n)
        {
            mm++;
            i=next[i];
        }
    }
}
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt-- >0)
    {
        mm=0;
        scanf("%s",ss);
        scanf("%s",aa);
        n=strlen(ss);
        n1=strlen(aa);
        hehe(n);
        kmp();
        printf("%d\n",mm);
    }
    return 0;
}

/*
VERDI
AVERDIVYERDIAN
*/
