#include<cstdio>
#include<string.h>
int next[205],mm,n,n1,n2,t,flag,mm1;
char ss[205],aa[4010][203];
void hehe(int n)
{
    next[0] = -1;
    int i = 0;
    int j = -1;
    while( i < n )
    {
        if(j == -1 || ss[i] == ss[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
    return ;
}
void kmp(int t)
{
    int j=0,i=0;
    while(j<n1)
    {
        if(i==-1||ss[i]==aa[t][j])
        {
            i++;
            j++;
        }
        else
            i=next[i];
        if(i>=n)
        {
            mm++;
            return ;
        }
    }
}
int main()
{
    int tt,pp;
    while(scanf("%d",&tt)!=EOF&&tt)
    {
        flag=1;
        pp=0;
        while(pp<tt)
            scanf("%s",aa[pp++]);
        n2=strlen(aa[0]);
        for(int i=n2;i>0&&flag;i--)
        {
            for(int q=0;i+q<=n2;q++)
            {
                mm=1;
                strncpy(ss,aa[0]+q,i);
                ss[i]='\0';
                printf("%s\n",ss);
                n=strlen(ss);
                hehe(n);
                for(int o=1;o<tt;o++)
                {
                    n1=strlen(aa[o]);
                    mm1=mm;
                    kmp(o);
                    if(mm1==mm)
                        break;
                }
                if(mm==tt)
                {
                    printf("%s\n",ss);
                    flag=0;
                    break;
                }
            }
        }
        if(flag)
            printf("IDENTITY LOST\n");
    }
    return 0;
}



//

#include <cstdio>
#include <cstring>
int next[201],n,n1;
char str[4001][203];
char aa[201],hehe[201];
void yaya(char *s2)
{
    int i,j,k;
    n1 = strlen(s2);
    i = 0,j = -1;
    next[0] = -1;
    while (i < n1)
    {
        if (j == -1 || s2[i] == s2[j])
            i++,j++,next[i] = j;
        else j = next[j];
    }
}
int kmp(char *s1,char *s2)
{
    int i =0, j = 0;
    n = strlen(s1);
    while (i < n)
    {
        if (j == -1 || s1[i] == s2[j])
            i++,j++;
        else j = next[j];
        if (j == n1) return 1;
    }
    return 0;
}
int main()
{
    int i,j,k,t,m,flag,maxlen,len;
    while (1)
    {
        scanf("%d",&m);
        if(m == 0)
            break;
        for (i = 0; i < m; i++)
            scanf("%s",str[i]);
        aa[0] = '\0';
        maxlen = strlen(str[0]);
        for (len = 1; len <= maxlen; len++)
            for (i = 0; i <= maxlen - len; i++)
            {
                for (k = 0,j = i; j < i + len; j++)
                    hehe[k++] = str[0][j];
                hehe[k] = '\0';
                yaya(hehe);
                for (k = 1; k < m; k++)
                    {
                        if (kmp(str[k],hehe) == 0)
                            break;
                    }
                if (k == m)
                {
                    if (strlen(aa) == len && strcmp(aa,hehe) > 0)
                        strcpy(aa,hehe);
                    if (strlen(aa) < len)
                        strcpy(aa,hehe);
                }
            }
        if (aa[0] == '\0')
            printf("IDENTITY LOST\n");
        else printf("%s\n",aa);
    }
}
