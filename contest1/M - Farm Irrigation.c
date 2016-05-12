#include<stdio.h>
int fx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};//ÉÏÏÂ×óÓÒ
int zz[11][4]={{1,0,0,1},{1,1,0,0},{0,0,1,1},{0,1,1,0},{1,0,1,0},{0,1,0,1},{1,1,0,1},{1,0,1,1},{0,1,1,1},{1,1,1,0},{1,1,1,1}};
char map[60][60];
int map1[60][60];
int mm,m=1,n=1;
void  dfs(int x,int y)
{
    int i,p=map[y][x]-'A';
    int x1,y1,w,l;
    map1[y][x]=0;
    for(i=0;i<4;i++)
    {
        if(zz[p][i]==1)
        {
            x1=x+fx[i][1];
            y1=y+fx[i][0];
            if(x1>=n||y1>=m||x1<0||y1<0||map1[y1][x1]==0)
                continue;
            l=(i+2)%4;
            w=map[y1][x1]-'A';
            if(zz[w][l]==1)
            {
                dfs(x1,y1);
            }
        }
    }
}
void start()
{
    int xx,pp;
    for(xx=0;xx<m;xx++)
        scanf("%s",map[xx]);
    for(xx=0;xx<m;xx++)
    {
        for(pp=0;pp<n;pp++)
            map1[xx][pp]=1;
    }
}
int main()
{
    int ss,dd;
    while(1)
    {
        mm=0;
        scanf("%d%d",&m,&n);
        if(m==-1||n==-1)
            break;
        start();
        for(ss=0;ss<m;ss++)
        {
            for(dd=0;dd<n;dd++)
            {
                if(map1[ss][dd]!=0)
                    {
                        mm++;
                        dfs(dd,ss);
                    }
            }
        }
        printf("%d\n",mm);
    }
    return 0;
}
