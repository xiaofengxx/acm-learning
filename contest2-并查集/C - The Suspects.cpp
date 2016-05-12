#include<cstdio>
#include<cstring>
int pa[40000],pa1[40000],mm;
int cha(int k)
{
    if(pa[k]!=k)
    {
        pa[k]=cha(pa[k]);
    }
    return pa[k];
}
bool bing(int x,int y)
{
    x=cha(x);
    y=cha(y);
    if(x==y)
        return false;
    pa[x]=y;
    return true;
}
int main()
{
    int n,k,x,y,t;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        mm=0;
        if(n==0&&k==0)
            return 0;
        for(int i=0;i<=n;i++)
        {
            pa[i]=i;
            pa1[i]=0;
        }
        pa1[0]=1;
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&t);
            if(t>0)
            {
                scanf("%d",&x);
                pa1[x]=1;
                t--;
            }
            for(;t>0;t--)
            {
                scanf("%d",&y);
                pa1[y]=1;
                bing(x,y);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(pa1[i]==1)
            {
                if(cha(0)==cha(i))
                {
                    mm++;
                }
            }
        }
        printf("%d\n",mm);
    }
    return 0;
}
