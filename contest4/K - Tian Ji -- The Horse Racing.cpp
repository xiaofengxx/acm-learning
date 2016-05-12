#include<cstdio>
#include<algorithm>
using namespace std;
int aa[1500],bb[1500];
int main()
{
    int n,i,ans,dade,dade1,xiao1,xiao2,tt;
    while(~scanf("%d", &n) && n)
    {
        for(i=0; i<n; i++)
            scanf("%d",&aa[i]);
        for(i=0; i<n; i++)
            scanf("%d",&bb[i]);
        sort(aa, aa+n);
        sort(bb, bb+n);
        ans=0;
        dade=dade1=n-1;
        xiao1=xiao2=0;
        tt=0;
        while((tt++)<n)
        {
            if(aa[dade]>bb[dade1])
            {
                ans += 200;
                dade--;
                dade1--;
            }
            else if(aa[dade]<bb[dade1])
            {
                ans -= 200;
                xiao1++;
                dade1--;
            }
            else
            {
                if(aa[xiao1]>bb[xiao2])
                {
                    ans += 200;
                    xiao1++;
                    xiao2++;
                }
                else
                {
                    if(aa[xiao1]<bb[dade1])
                        ans-=200;
                    xiao1++;
                    dade1--;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
