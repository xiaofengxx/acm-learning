#include<cstdio>
using namespace std;
int fx[6][3]={{0,1,0},{1,0,0},{0,0,1},{0,-1,0},{-1,0,0},{0,0,-1}};
int tou,lian,zuo,x,y,z;
void wocao(char a,int b)
{
    int fu;
    if(a=='l')
    {
        fu=zuo;
        zuo=(lian+3)%6;
        lian=fu;
    }
    else if(a=='b')
    {
        zuo=(zuo+3)%6;
        lian=(lian+3)%6;
    }
    else if(a=='r')
    {
        fu=lian;
        lian=(zuo+3)%6;
        zuo=fu;
    }
    else if(a=='u')
    {
        fu=tou;
        tou=(lian+3)%6;
        lian=fu;
    }
    else if(a=='d')
    {
        fu=lian;
        lian=(tou+3)%6;
        tou=fu;
    }
    x+=fx[lian][0]*b;
    y+=fx[lian][1]*b;
    z+=fx[lian][2]*b;
}
int main()
{
    int n,t,cc;
    char ss[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        x=y=z=0;
        tou=2;
        lian=0;
        zuo=4;
        scanf("%d",&t);
        for(int o=0;o<t;o++)
        {
            scanf("%s%d",ss,&cc);
            wocao(ss[0],cc);
        }
        printf("%d %d %d %d\n",y,x,z,lian);
    }
    return 0;
}
