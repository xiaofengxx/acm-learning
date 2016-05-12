#include<string.h>
#include<cstdio>
char s1[110],s2[110],s12[220],sb[1010][220];
int p,t,n,mm,ll=0;
int main()
{
    scanf("%d",&t);
    while(ll++ <t)
    {
        p=0;
        mm=0;
        scanf("%d",&n);
        scanf("%s",s1);
        scanf("%s",s2);
        scanf("%s",s12);
        while(!mm)
        {
            for(int i=0;i<n;i++)
            {
                sb[p][i*2]=s2[i];
                sb[p][i*2+1]=s1[i];
            }
            sb[p][n*2]='\0';
            if(strcmp(s12,sb[p])==0)
            {
                printf("%d %d\n",ll,p+1);
                break;
            }
            for(int i=0;i<p;i++)
            {
                if(strcmp(sb[i],sb[p])!=0)
                       continue;
                mm=1;
                break;
            }
            if(mm)
               {
                   printf("%d -1\n",ll);
                   break;
               }
            else
            {
                for(int i=0;i<n;i++)
                {
                    s1[i]=sb[p][i];
                    s2[i]=sb[p][n+i];
                }
            }
            p++;
        }
    }
    return 0;
}


/*

1
4
AHAH
HAHA
HHAAAAHH
3
CDE
CDE
EEDDCC

*/
