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
    int i,j,k,t,m,flag,maxlen,len,tt;
    scanf("%d",&tt);
    while (tt-- >0)
    {
        scanf("%d",&m);
        for (i = 0; i < m; i++)
            scanf("%s",str[i]);
        aa[0] = '\0';
        maxlen = strlen(str[0]);
        for (len = 3; len <= maxlen; len++)
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
            printf("no significant commonalities\n");
        else printf("%s\n",aa);
    }
}
