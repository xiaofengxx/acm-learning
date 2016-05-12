#include<stdio.h>
int hehe(int m,int n)
{
    if(m==0||n==1)
        return 1;
    if(m<n)
        return hehe(m,m);
    return hehe(m,n-1)+hehe(m-n,n);
}
int main()
{
    int t,m,n;
    scanf("%d",&t);
    for(;t>0;t--)
    {
        scanf("%d%d",&m,&n);
        printf("%d\n",hehe(m,n));
    }
    return 0;
}


#include <stdio.h>
int sum = 0;
int gg(int a,int b,int q)
{
    int n = a;
    if(a == 0 && b>=0)
    {
        sum++;
        return ;
    }
    for(;n>0;n--)
    {
        if(n>q)
            continue ;
        gg(a-n,b-1,n);
    }
}
int main()
{
    int i,m,n,j;
    int k,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&k,&l);
        gg(k,l,1000);
        printf("%d\n",sum);
        sum = 0;
    }
}
