#include<iostream>
#include<cstdio>
using namespace std;
int a[103][103];
#define inf 100000
int N;
void flody()
{
    int i,j,k;
    for(k=1; k<=N; k++)
        for(i=1; i<=N; i++)
            for(j=1; j<=N; j++)
                if(a[i][j]>a[i][k]+a[k][j])
                    a[i][j]=a[i][k]+a[k][j];
}
int main()
{
    int A,B,i,j,k,t;
    scanf("%d%d%d",&N,&A,&B);
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
        {
            if(i==j) a[i][j]=0;
            else a[i][j]=inf;
        }

    for(i=1; i<=N; i++)
    {
        scanf("%d",&k);
        for(j=1; j<=k; j++)
        {
            scanf("%d",&t);
            if(j==1) a[i][t]=0;
            else  a[i][t]=1;
        }
    }
    flody();
    if(a[A][B]==inf)  puts("-1");
    else  printf("%d\n",a[A][B]);
}

