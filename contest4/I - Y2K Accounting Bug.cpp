#include<cstdio>
long long a,b,mm;
long long hh[12];
int main()
{
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        for(int i=0;i<12;i++)
            hh[i]=a;
        mm=5*a;
        for(int i=4;mm>0;i--)
        {
            mm=mm-a-b;
            hh[i]=-b;
            hh[5+i]=-b;
            if(i<2)
                hh[10+i]=-b;
        }
        mm=0;
        for(int i=0;i<12;i++)
            mm+=hh[i];
        if(mm>0)
            printf("%lld\n",mm);
        else
            printf("Deficit\n");
    }
    return 0;
}
