#include<cstdio>
#include<cstring>
int pa[60000];
int m,n,mm;
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
    int a,b,t=0;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        mm=0;
        t++;
        if(m==0&&n==0)
            return 0;
        for(int i=0;i<=m;i++)
            pa[i]=i;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
            bing(a,b);
        }
        for(int i=1;i<=m;i++)
        {
            if(pa[i]==i)
                mm++;
        }
        printf("Case %d: %d\n",t,mm);
    }
}

