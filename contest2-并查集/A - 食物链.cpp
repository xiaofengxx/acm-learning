#include<cstdio>
#include<cstring>
int pa[50005],pa1[50005];
int m,n,mm;
int cha(int k)
{
    if(pa[k]!=k)
    {
        int ww=pa[k];
        pa[k]=cha(pa[k]);
        pa1[k]=(pa1[k]+pa1[ww])%3;
    }
    return pa[k];
}
void bing(int x,int y,int d)
{
    int ss,dd;
    ss=cha(x);
    dd=cha(y);
    pa[dd]=ss;
    pa1[dd]=(pa1[x]-pa1[y]+2+d)%3;
}
int main()
{
    int aa,bb,d;
    mm=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        pa[i]=i;
        pa1[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&d,&aa,&bb);
        if(aa>m||bb>m||(aa==bb&&d==2))
        {
            mm++;
            continue;
        }
        if(cha(aa)==cha(bb))
        {
            if(d==1&&pa1[aa]!=pa1[bb])
                mm++;
            else if(d==2&&pa1[aa]!=(pa1[bb]+2)%3)
                mm++;
        }
        else
            bing(aa,bb,d);
    }
    printf("%d\n",mm);
    return 0;
}









/*

#include <cstdio>
int n,m;
int p[50005],r[50005];
void make()
{
    int i;
    for(i=1; i<=n; i++)
    {
        p[i]=i; r[i]=0;
    }
}

int find(int x)
{
    if(x!=p[x])
    {

        int temp=p[x];
        p[x]=find(p[x]);
        r[x]=(r[temp]+r[x])%3;
    }
    return p[x];
}

void Union(int x,int y,int d)
{
    int rx,ry;
    rx=find(x);
    ry=find(y);
    p[ry] = rx;
    r[ry] = ( r[x] - r[y] + 2 + d ) % 3;
}

int main()
{
    int i,j,d,x,y;
    int ry,rx,fls;
    scanf("%d%d",&n,&m);
    fls=0;
    make();
    for(i=1; i<=m; i++)
    {
        scanf("%d%d%d",&d,&x,&y);
        if(x>n||y>n||(d==2&&x==y))
        {
            fls++; continue;
        }
        rx=find(x),ry=find(y);
        if(rx==ry)
        {
            if(d==1 && r[x]!=r[y])
            {    fls++;continue;   }
            else
            {
                if(d==2 && r[x] != (r[y]+2)%3)
                    fls++;
            }
        }
        else
            Union(x,y,d);
    }
    printf("%d\n",fls);
    return 0;
}
*/
