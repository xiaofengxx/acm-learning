#include <cstdio>
#include <cstring>
#define maxn 1000000
int next[maxn];
char p[maxn];
void getNext()
{
    int m,i = 0,j = -1;
    int len = strlen(p);
    next[0] = -1;
    while(i < len)
    {
        if(j == -1|| p[i] == p[j])
        {
            next[++i] = ++j;
            if(i % (i - j) == 0&& i/( i - j) > 1)
                printf("%d %d\n",i ,i/( i - j));
        }
        else
            j = next[j];
    }
}
int main()
{
    int m,i,n,j = 1;
    while(scanf("%d",&n)&&n)
    {
        scanf("%s",p);
        printf("Test case #%d\n",j++);
        getNext();
        printf("\n");
    }
}
