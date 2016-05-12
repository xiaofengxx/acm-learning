#include<stdio.h>
#define max 9999999
int n,p,p1,p2,k;
int x1[8]={1,2,2,1,-1,-2,-2,-1},y1[8]={-2,-1,1,2,2,1,-1,-2};
int dui[max][2];
int map[300][300];
void start()
{
    int i,o;
    for(i=0;i<n;i++)
    {
        for(o=0;o<n;o++)
            map[i][o]=0;
    }
    return ;
}
void bfs()
{
    int l,x,y;
    x=dui[p][1],y=dui[p][0];
    if(x==p1&&y==p2)
       {
          return ;
       }
    p++;
    if(p>9999997)
        p=0;
    for(l=0;l<8;l++)
    {
        if(x+x1[l]<n&&y+y1[l]<n&&x+x1[l]>=0&&y+y1[l]>=0&&map[y+y1[l]][x+x1[l]]==0)
        {
            map[y+y1[l]][x+x1[l]]=map[y][x]+1;
            dui[k][0]=y+y1[l];
            dui[k][1]=x+x1[l];
            k++;
            if(k>9999997)
                k=0;
        }
    }
    bfs();
}
int main()
{
    int t;
    scanf("%d",&t);
    for(;t>0;t--)
    {
        p=0,k=1;
        scanf("%d",&n);
        scanf("%d%d",&dui[0][0],&dui[0][1]);
        scanf("%d%d",&p1,&p2);
        bfs();
        printf("%d\n",map[p1][p2]);
        start();
    }
    return 0;
}
