#include<cstdio>
#include<cstring>
int pa[10000],pa1[10000][3];
int m,mm;
long n;
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
    char cc[3];
    long d;
    int aa,bb;
    scanf("%d%ld",&m,&n);
    n=n*n;
    for(int i=1;i<=m;i++)
        {
            pa[i]=i;
            pa1[i][2]=0;
            scanf("%d%d",&pa1[i][0],&pa1[i][1]);
        }
    while(scanf("%s",cc)!=EOF)
    {
        if(cc[0]=='O')
        {
            scanf("%d",&mm);
            pa1[mm][2]=1;
            for(int i=1;i<=m;i++)
            {
                if(pa1[i][2]==1)
                {
                    d=(pa1[mm][0]-pa1[i][0])*(pa1[mm][0]-pa1[i][0])+(pa1[mm][1]-pa1[i][1])*(pa1[mm][1]-pa1[i][1]);
                    if(d<=n)
                        bing(mm,i);
                }
            }
        }
        else
        {
            scanf("%d%d",&aa,&bb);
            if(cha(aa)==cha(bb))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}
