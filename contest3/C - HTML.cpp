#include<cstdio>
#include<cstring>
using namespace std;
char aa[1500];
int i=0;
int main()
{

    while(scanf("%s",aa)!=EOF)
    {
        if(strcmp(aa,"<br>")==0)
        {
            i=0;
            printf("\n");
            continue;
        }
        if(strcmp(aa,"<hr>")==0)
        {
            if(i)
                printf("\n");
            i=0;
            printf("--------------------------------------------------------------------------------\n");
            continue;
        }
        if(i+strlen(aa)>=79)
        {
            i=strlen(aa);
            printf("\n%s",aa);
        }
        else
        {
            if(i!=0)
            {
                printf(" ");
                i++;
            }
            printf("%s",aa);
            i=i+strlen(aa);
        }
    }
    return 0;
}
