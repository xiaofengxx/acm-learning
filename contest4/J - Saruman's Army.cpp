#include<cstdio>
#include<algorithm>
using namespace std;
int aa[1500];
int main()
{
    int r,n;
    int mm,m;
    while(scanf("%d%d",&r,&n)!=EOF)
    {
        if(r==-1&&n==-1)
            break;
        mm=0;
        for(int i=0;i<n;i++)
            scanf("%d",&aa[i]);
        sort(aa,aa+n);
        for(int i=0;i<n;)
        {
            m=aa[i]+r;
            while(aa[i]<=m&&i<n)
                i++;
            mm++;
            m=aa[i-1]+r;
            while(aa[i]<=m&&i<n)
                i++;
        }
        printf("%d\n",mm);
    }
    return 0;
}
