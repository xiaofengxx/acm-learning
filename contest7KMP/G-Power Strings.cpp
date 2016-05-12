#include<cstdio>
#include<string.h>
int next[1000005] = {0};
char s[1000005];
int main()
{
    int i,j,n,mm,he;
    next[0] = -1;
    while(1)
    {
        i = 0;
        j = -1;
        scanf("%s",s);
        if(s[0]=='.')
            break;
        n=strlen(s);
        while( i < n )
        {
            if(j == -1 || s[i] == s[j])
                next[++i] = ++j;
            else
                j = next[j];
        }
        he=1;
        if(n%(n-next[n])==0)
            he=n/(n-next[n]);
        printf("%d\n",he);
    }
    return 0;
}
