#include<cstdio>
int mm,k,n,tt=1;
int aa[35000],bb[35000];
int main()
{

    while(scanf("%d",&aa[0])!=EOF&&aa[0]!=-1)
    {
        mm=1;
        bb[0]=1;
        for(n=0;aa[n]!=-1;)
        {
            n++;
            scanf("%d",&aa[n]);
            bb[n]=1;
        }
        for(int i=1;i<n;i++)
        {
            k=0;
            for(int o=i-1;o>=0;o--)
            {
                if(aa[i]<aa[o]&&bb[o]>k)
                    k=bb[o];
            }
            bb[i]=k+1;
            if(bb[i]>mm)
                mm=bb[i];
        }
        printf("Test #%d:\n  maximum possible interceptions: %d\n\n",tt,mm);
        tt++;
    }
    return 0;
}
