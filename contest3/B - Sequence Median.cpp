#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double aa[250010];
int main()
{
    long long n;
    double ss;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
        scanf("%lf",&aa[i]);
    sort(aa,aa+n);
    if(n%2==0)
        ss=(aa[n/2-1]+aa[n/2])/2;
    else
        ss=aa[n/2];
    printf("%0.1lf\n",ss);
}


/*
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(void)
{
    double sq[250005];
    long long n,i;
    double re;
    scanf("%lld",&n);
    for( int i = 0; i < n; i++)
        scanf("%lf",&sq[i]);
    sort(sq,sq+n);
    //for(int i = 0; i < n ; i++)
        //printf("%.0lf ",sq[i]);
    //cout<<endl;
    if(n % 2 == 0)
    {
        n--;
        re = (sq[n/2]+sq[n/2+1])/2;
        printf("%.1lf\n",re);
    }else
    {
        n--;
        re = sq[n/2];
        printf("%.1lf\n",re);
    }
}
*/
