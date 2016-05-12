#include<stdio.h>
int x1[8]={0,1,1,1,0,-1,-1,-1},y1[8]={1,1,0,-1,-1,-1,0,1};
char you[200][200];
int k,g;
int mm;
void start()
{
    int i;
    for(i=0;i<g;i++)
    {
        scanf("%s",you[i]);
    }
}
void hehe(int x,int y)
{
    int i;
    for(i=0;i<8;i++)
    {
        if(you[y+y1[i]][x+x1[i]]=='@'&&y+y1[i]<g&&x+x1[i]<k)
          {
              you[y+y1[i]][x+x1[i]]='*';
              hehe(x+x1[i],y+y1[i]);
          }
    }
}
int main()
{
    int u,p;
    scanf("%d%d",&g,&k);
    while(g!=0&&k!=0)
    {
        mm=0;
        start();
        for(u=0;u<g;u++)
        {
            for(p=0;p<k;p++)
                if(you[u][p]=='@')
                    {
                        you[u][p]='*';
                        mm++;
                        hehe(p,u);
                    }
        }
        printf("%d\n",mm);
        scanf("%d%d",&g,&k);
    }
    return 0;
}
