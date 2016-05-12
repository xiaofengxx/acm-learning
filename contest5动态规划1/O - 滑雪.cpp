#include<stdio.h>
#include<string.h>
const int maxn=105;
int snow[maxn][maxn];
int d[maxn][maxn];
int n,m;
int Max(int a,int b)
{
    return (a)>(b)?(a):(b);
}
int dfs(int x,int y){
    if(d[x][y]>0)return d[x][y];
    if(x-1>0&&snow[x-1][y]<snow[x][y]){d[x][y]=Max(d[x][y],dfs(x-1,y)+1);}
    if(x+1<=n&&snow[x+1][y]<snow[x][y]){d[x][y]=Max(d[x][y],dfs(x+1,y)+1);}
    if(y-1>0&&snow[x][y-1]<snow[x][y]){d[x][y]=Max(d[x][y],dfs(x,y-1)+1);}
    if(y+1<=m&&snow[x][y+1]<snow[x][y]){d[x][y]=Max(d[x][y],dfs(x,y+1)+1);}
    return d[x][y];
}

int main(){
    int i,j;
    while(scanf("%d%d",&n,&m)==2)
    {
        memset(d,0,sizeof(d));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&snow[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                dfs(i,j);
            }
        }
        int maxdist=-1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(maxdist<d[i][j])maxdist=d[i][j];
            }
        }
        printf("%d\n",maxdist+1);
    }
    return 0;
}
