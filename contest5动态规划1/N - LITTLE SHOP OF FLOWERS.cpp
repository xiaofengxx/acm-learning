#include<cstdio>
int aa[2][100],p1=0,p2=1,ww;
int Max(int a,int b)
{
    return a>=b?a:b;
}
int main()
{
    int n,t;
    scanf("%d%d",&t,&n);
    aa[p2][0]=-1000000;
    aa[p1][0]=-1000000;
    for(int i=1;i<=t;i++)
    {
        p1^=1;
        p2^=1;
        for(int o=1;o<=n;o++)
        {
            scanf("%d",&aa[p1][o]);
            if(i>2&&o<i-1)
                aa[p2][o]=-100000;
            //printf("_%d*%d\n",aa[p2][o-1],aa[p2][o-2]);
            if(o>i-1&&i>1)
                aa[p1][o]+=aa[p2][o-1]=Max(aa[p2][o-2],aa[p2][o-1]);
            //printf("*%d*%d\n",aa[p2][o-1],aa[p2][o-2]);
        }
        /*printf("                    ");
        for(int i=1;i<=n;i++)
            printf("%d  ",aa[p2][i]);printf("\n                     ");
        for(int i=1;i<=n;i++)
            printf("%d  ",aa[p1][i]);
        printf("\n");*/
    }
    ww=aa[p1][t];
    for(int i=t+1;i<=n;i++)
        ww=Max(aa[p1][i-1],aa[p1][i]);
    printf("%d\n",ww);
    return 0;
}


/*
3 5
7 23 -5 -24 16
5 21 -4 10 23
-21 5 -4 20 -20

5 5
1 2 3 4 5
6 5 4 2 3
4 5 6 8 7
21 65 4 7 8
1 2 4 7 8

3 5
-50 -50 -50 -50 -50
-50 -50 -51 -50 -50
-50 -50 -50 -50 -50

*/
