#include<stdio.h>
int fx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char map[10][10];
int m,n,t;
int ii,pp,mm,qq,ww;
void dfs(int x,int y,int tt)
{
    if(t==-1||tt>t)
        return ;
    if(map[y][x]=='D'&&tt==t)
        {
            t=-1;
            return;
        }
    int i,y1,x1;
    for(i=0;i<4;i++)
    {
        x1=x+fx[i][1];
        y1=y+fx[i][0];
        if(map[y1][x1]=='.'||y1<m||x1<n)
        {
            map[y][x]='X';
            dfs(y1,x1,tt+1);
            map[y][x]='.';
        }
    }
}
void start()
{
    for(ii=0;ii<m;ii++)
        scanf("%s",map[ii]);
    for(ii=0;ii<m;ii++)
    {
        for(pp=0;pp<n;pp++)
        {
            if(map[ii][pp]=='S')
                {
                    qq=ii;
                    ww=pp;
                }
            else if(map[ii][pp]=='X')
                mm++;
        }
    }
    return ;
}
int main()
{
    while(1)
    {
        scanf("%d%d%d",&m,&n,&t);
        if(m==0||n==0||t==0)
            return 0;
        mm=0;
        start();
        if(m*n-mm<t)
            t=-1;
        else
            dfs(ww,qq,0);
        if(t==-1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

/*
4 4 5
S.X.
..X.
..XD
....
3 4 5
S.X.
..X.
...D
0 0 0
*/


#include <stdio.h>
#include <stdlib.h>
bool flag;
int n,m,t,i,j,x1,y1,x2,y2,num;
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
char str[8][8];
void BFS(int k,int l,int tc)
{
    int i;
    if(tc==t && k==x2 &&l==y2)
        flag=true;
    if(flag) return;
    if((abs(x2-k)+abs(y2-l))%2!=(t-tc)%2) return;
    for(i=0;i<4;i++)
    {
        int dx=k+dir[i][0];
        int dy=l+dir[i][1];
        if(dx>=0 && dx<n && dy>=0 && dy<m && str[dx][dy]!='X')
        {
            str[dx][dy]='X';
            BFS(dx,dy,tc+1);
            str[dx][dy]='.';
        }
    }
}
int main()
{
    while (scanf("%d%d%d",&n,&m,&t))
    {
        getchar();
        if(n==0 && m==0 && t==0)
            break;
        num=0;
        flag=false;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%c",&str[i][j]);
                if(str[i][j]=='S')
                {
                    x1=i;y1=j;
                }
                else if(str[i][j]=='D')
                {
                    x2=i;y2=j;
                    num++;
                }
                else if(str[i][j]=='.')
                {
                    num++;
                }
            }
            getchar();
        }
        str[x1][y1]='X';
        if(num>=t)
            BFS(x1,y1,0);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}



