#include<cstdio>
#include<string.h>
int juzi=0;
int woeds=0;
int yuan=0;
char aabb[1500];
int l;
bool biaodian(char ch)
{
    if(ch==','||ch=='.'||ch==';'||ch=='!'||ch=='?'||ch==':')
        return true;
    else
        return false;
}
bool yuanyin(char c)
{
    if(c=='a'||c =='e'||c =='i'||c=='o'||c=='u'||c=='y'||c=='A'||c =='E'||c =='I'||c=='O'||c=='U'||c=='Y')
        return true;
    return false;
}
void jianshao()
{
    if(biaodian(aabb[l-1]))
    {
        if(aabb[l-1]!=',')
        juzi++;
        if((aabb[l-2]=='e'&&aabb[l-3]!= 'l'&&!yuanyin(aabb[l-3]))||(aabb[l-2]=='s'&&aabb[l-3]=='e'&&!yuanyin(aabb[l-4]))||(aabb[l-2]=='d'&&aabb[l-3]=='e'&&!yuanyin(aabb[l-4])))
            yuan--;
    }
    else
    {
        if((aabb[l-1]=='e'&&aabb[l-2]!= 'l'&&!yuanyin(aabb[l-2]))||(aabb[l-1]=='s'&&aabb[l-2]=='e'&&!yuanyin(aabb[l-3]))||(aabb[l-1]=='d'&&aabb[l-2]=='e'&&!yuanyin(aabb[l-3])))
            yuan--;
    }
}
int main()
{
    while(scanf("%s",aabb)!=EOF)
    {
        int ii=0;
        l=strlen(aabb);
        if(l<=3)
            yuan++;
        else
        {
            if(yuanyin(aabb[0]))
            {
                yuan++;
                ii=1;
            }
            for(int i=1;i<l;i++)
            {
                if(yuanyin(aabb[i])&&!ii)
                {
                    yuan++;
                    ii=1;
                }
                else if(!yuanyin(aabb[i]))
                    ii=0;
            }
            jianshao();
        }
        woeds++;
    }
    printf("%.2f\n", 206.835-1.015*woeds/juzi-84.6*yuan/woeds);
    return 0;
}
