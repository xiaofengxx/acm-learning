#include<cstdio>
#include<cstring>
int pa[110000],pa1[110000];
int m,n;
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
    int t,zz,xx,aa,ff,tt;
    char cc[3];
    scanf("%d",&t);
    while(t-- >0)
    {
        scanf("%d%d",&m,&n);
        for(int i=0;i<=m;i++)
        {
            pa[i]=i;
            pa1[i]=0;
        }
        while(n-- >0)
        {
            scanf("%s%d%d",cc,&zz,&xx);
            if(cc[0]=='D')
            {
                bing(zz,xx);
            }
            else
            {
                aa=cha(zz);
                ff=cha(xx);
                if(aa!=ff)
                    printf("Not sure yet.\n");
                else
                    if(pa1[zz]==pa1[xx])
                        printf("In the same gang.\n");
                else
                    printf("In different gangs.\n");
            }
            for(int i=1;i<=m;i++)
            printf("%d  ",pa1[i]);
            printf("\n");
        }
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
