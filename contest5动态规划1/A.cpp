#include<cstdio>
#include<iostream>
using namespace std;
int n;
int a[1000][1000];
int biaoji[1000][1000];
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            scanf("%d",&a[i][j]);
    for(int i=n; i>0; i--)
        for(int j=1; j<=i; j++)
        {
            biaoji[i][j]=max(biaoji[i+1][j],biaoji[i+1][j+1])+a[i][j];
        }
        printf("%d\n",biaoji[1][1]);
}
