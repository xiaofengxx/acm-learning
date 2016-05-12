#include<cstdio>
int main()
{
    long long aa=0;
    int a,b,c,n,d;
    scanf("%d%d",&n,&d);
    scanf("%d%d",&a,&b);
    aa+=a*b;
    c=a;
    while(n-- >1)
    {
        c+=d;
        scanf("%d%d",&a,&b);
        if(a>c)
            a=c;
        else
            c=a;
        aa+=a*b;
    }
    printf("%lld\n",aa);
    return 0;
}
