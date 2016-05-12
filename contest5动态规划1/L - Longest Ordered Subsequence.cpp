#include<cstdio>
int mm,k;
int main()
{
    int n,aa[1010],bb[1010];
    while(scanf("%d",&n)!=EOF)
    {
        mm=1;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&aa[i]);
            bb[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            k=0;
            for(int o=i-1;o>=0;o--)
            {
                if(aa[i]>aa[o]&&bb[o]>k)
                    k=bb[o];
            }
            bb[i]=k+1;
            if(bb[i]>mm)
                mm=bb[i];
        }
        printf("%d\n",mm);
    }
    return 0;
}
