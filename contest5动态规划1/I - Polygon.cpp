#include<cstring>
#include<cstdio>
using namespace std;char s1[410],s2[410],s3[410];int len1,len2,len3;
int dfs(int x,int y,int t)
{
    if(len1==x && len2==y) return 1;
    if(s3[t]==s1[x] && x<len1)
    {
        if(dfs(x+1,y,t+1))
            return 1;

    }
    if(s3[t]==s2[y] && y<len2)
    {
        if(dfs(x,y+1,t+1))
            return 1;
    }
    return 0;
}
int main()
{

    int n;
    scanf("%d",&n);int h=1;
    while(n--)
    {
        scanf("%s %s %s",s1,s2,s3);
         len1 = strlen(s1);
         len2 = strlen(s2);
         len3 = strlen(s3);

        if(s3[len3-1]!=s1[len1-1] && s3[len3-1]!=s2[len2-1] ||(len1+len2)!=len3)
        {
            printf("Data set %d: no\n",h++);
        }
        else
        {
            if(dfs(0,0,0))
                printf("Data set %d: yes\n",h++);
            else
                printf("Data set %d: no\n",h++);
        }
    }
    return 0;
}
