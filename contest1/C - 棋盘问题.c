#include<stdio.h>
int mm,p;
int n=1,k=1;
char map[10][10];
int map1[25];
int he[100][2];
void start()
{
    int i,o;
    for(i=0;i<n;i++)
    {
        scanf("%s",map[i]);
    }
    for(i=0;i<n;i++)
    {
        for(o=0;o<n;o++)
        {
            if(map[i][o]=='#')
            {
                he[p][1]=i;
                he[p][0]=o;
                map1[n+o+1]=1;
                map1[n-i-1]=1;
                p++;
            }
        }
    }
    return ;
}
void dfs(int sd,int l)
{
    int h;
    if(l==0)
    {
        mm++;
        return ;
    }
    for(h=0;h<n;h++)
    {
        if(sd+h<p&&map1[n+he[sd+h][0]+1]==1&&map1[n-he[sd+h][1]-1]==1)
        {
            map1[n+he[sd+h][0]+1]==0;
            map1[n-he[sd+h][1]-1]==0;
            dfs(sd+h+1,l-1);
            map1[n+he[sd+h][0]+1]==1;
            map1[n-he[sd+h][1]-1]==1;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    while(n>0&&k>=0)
    {
        p=0,mm=0;
        start();
        dfs(0,k);
        printf("%d\n",mm);
    scanf("%d%d",&n,&k);
    }
    return 0;
}



/*


3 2
..#
.#.
#..
2 1
#.
.#
4 4
...#
..#.
..#.
#...
-1 -1






*/
