//再出这么难的题我要报警了
#include<cstdio>
#include<cstring>
int pa[110000],pa1[110000];
int m,n,mm;
int cha(int k)
{
    if(pa[k]!=k)
    {
        int ww=pa[k];
        pa[k]=cha(pa[k]);
        pa1[k]=(pa1[k]+pa1[ww])%2;
    }
    return pa[k];
}
void bing(int x,int y)
{
    int ss,dd;
    ss=cha(x);
    dd=cha(y);
    pa[ss]=dd;
    pa1[ss]=(pa1[x]+pa1[y])^1;
}
int main()
{
    int t,aa,bb;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        mm=0;
        if(i!=1)
            printf("\n");
        scanf("%d%d",&m,&n);
        for(int i=1;i<=m;i++)
        {
            pa[i]=i;
            pa1[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&aa,&bb);
            if(cha(aa)==cha(bb))
            {
                if(pa1[aa]==pa1[bb])
                    mm=1;
            }
            else
                bing(aa,bb);
        }
        printf("Scenario #%d:\n",i);
        if(mm)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
    }
    return 0;
}


/*
2
5 5
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4
*/
