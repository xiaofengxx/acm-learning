#include<stdio.h>
#include<string.h>
char map[210][210];
int fx[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
int dui[40001][2],deep,top;
int m,n,aa,bb;
void bfs()
{
    int i,x1,y1,x,y;
    if(y==bb&&x==aa)
    {
        printf("%d\n",map[y][x]-'a');
        return ;
    }
    while(deep<=top)
    {
        for(i=0;i<4;i++)
        {
            x=dui[deep][1];
            y=dui[deep][0];
            x1=dui[deep][1]+fx[i][1];
            y1=dui[deep][0]+fx[i][0];
            if(map[y1][x1]=='.'||map[y1][x1]=='x'||map[y1][x1]=='X')
            {
                //dui[top][0]=y1;
                //dui[top][1]=x1;
                //top++;
                if(map[y1][x1]=='X')
                {
                    map[y1][x1]=map[y][x]+2;
                    dui[top][0]=y1;
                    dui[top][1]=x1;
                    top++;
                }
                else if(map[y1][x1]=='x')
                {
                    map[y1][x1]='X';
                    dui[top][0]=y;
                    dui[top][1]=x;
                    top++;
                }
                else
                {
                    map[y1][x1]=map[y][x]+1;
                    dui[top][0]=y1;
                    dui[top][1]=x1;
                    top++;
                }
            }
            else if(y1==bb&&x1==aa&&map[y][x]<map[y1][x1])
            {
                printf("    %c  \n",map[y1][x1]);
                map[y1][x1]=map[y][x]+1;
            }
        }
        deep++;
    }
    if(map[bb][aa]==100000)
        printf("Poor ANGEL has to stay in the prison all his life.\n");
    return ;
}
void start()
{
    int i,p;
    top=0;
    deep=0;
    for(i=0;i<m;i++)
        scanf("%s",map[i]);
    for(i=0;i<m;i++)
    {
        for(p=0;p<n;p++)
        {
            if(map[i][p]=='a')
            {
                dui[top][0]=i;
                dui[top][1]=p;
                top++;
            }
            else if(map[i][p]=='r')
            {
                aa=p;
                bb=i;
                map[i][p]=100000;
            }
        }
    }
}
int main()
{
    int s;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        start();
        bfs();
        for(s=0;s<m;s++)
            printf("%s\n",map[s]);
        memset(map,'#',m*n);
    }
    return 0;
}


/*

7 8
#.#####.
#.a#xxr.
#..#xx..
..#..#.#
#...##..
.#......
........

*/
