#include <cstdio>
const int inf = 2<<29;
int w[1000][1000];
int main()
{
    int nv,ne,x,y,l,cnt[1000];
    while(scanf("%d%d",&nv,&ne)!=EOF)
    {
        for(int i = 0;  i < 1000; i++)
            for(int j = 0;  j < 1000; j++)
                w[i][j] = inf;
        memset(cnt,0,sizeof(cnt));
        while(ne--)
        {
            scanf("%d%d",&x,&y);
            w[x][y] = w[y][x] = 2;
            cnt[x]++;
            xnt[y]++;
        }
        for(int i = 1; i <= nv; i++)
        {
            for(int j = 1; j <= nv; j++)
            {
                printf("%d\t",w[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d",&x);
        printf("-----%d",cnt[x]);
    }

}
