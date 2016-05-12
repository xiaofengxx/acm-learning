#include<cstdio>
int aa[40010];
int efcz(int a,int b,int n)
{
    int mid;
    while(a<=b)
    {
        mid = (a+b)/2;
        if(n>aa[mid])
            a = mid + 1;
        else
            b = mid - 1;
    }
    return b;
}
int main()
{
    int n,tt,mid;
    scanf("%d",&tt);
    aa[0]=-1000000;
    while(tt-- >0)
    {
        scanf("%d",&n);
        int jj=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&aa[jj]);
            if(aa[jj]>aa[jj-1])
                jj++;
            else
            {
                mid=efcz(1,jj-1,aa[jj]);
                aa[mid+1]=aa[jj];
            }
        }
        printf("%d\n",jj-1);
    }
}
