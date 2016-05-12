#include<stdio.h>
int x1[4]={0,1,0,-1},y1[4]={1,0,-1,0};
int mm;
int m,n;
int q,p;
char mn[25][25];
int vm[25][25];
void he()
{
    int s;
    for(s=0;s<n;s++)
    {
        scanf("%s",mn[s]);
    }
}
void start()
{
    for(q=0;q<n;q++)
    {
        for(p=0;p<m;p++)
        {
            vm[q][p]=0;
        }
    }
    q=0,p=0;
    for(q=0;q<n;q++)
    {
        for(p=0;p<m;p++)
        {
            if(mn[q][p]=='@')
                return;
        }
    }
}
void hehe(int x,int y)
{
    int  l;
    for(l=0;l<4;l++)
    {
        if(mn[y+y1[l]][x+x1[l]]=='.'&&vm[y+y1[l]][x+x1[l]]==0&&(y+y1[l]<n||x+x1[l]<x))
        {
            vm[y+y1[l]][x+x1[l]]=1;
            mm++;
            hehe(x+x1[l],y+y1[l]);
        }
    }
}
int main()
{
    scanf("%d%d",&m,&n);
    while(m!=0||n!=0)
    {
        mm=1;
        he();
        start();
        hehe(p,q);
        printf("%d\n",mm);
        scanf("%d%d",&m,&n);
    }
    return 0;
}
