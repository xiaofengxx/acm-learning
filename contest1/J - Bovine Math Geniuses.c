#include<stdio.h>
int n,p;
int lk[1000000];
int dd(int ss)
{
    int s;
    for(s=0;s<p;s++)
    {
        if(lk[s]==ss)
            return s;
    }
    return -1;
}
int main()
{
    int pp;
    while(scanf("%d",&n)!=EOF)
    {
        p=0;
        while(1)
        {
            n=n/10;
            n=n%10000;
            n=n*n;
            n=n%1000000;
            pp=dd(n);
            if(pp!=-1)
                break;
            lk[p]=n;
            p++;
        }
        printf("%d %d %d\n",n,p-pp,p+1);
    }
    return 0;
}
