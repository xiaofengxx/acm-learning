#include<cstdio>
int aa[10],ww,flag;
void DFS(int aabb, int cc)
{
    if(aabb == ww)
    {
        flag = 1;
        return;
    }
    if(flag||aabb>ww)
        return;
    for(int i=cc;i>0;i--)
    {
        if(aa[i])
        {
            if(i + aabb<= ww)
            {
                aa[i]--;
                DFS(i+aabb,i);
                //aa[i]++;
                if(flag)
                    return;
            }
        }
    }
}
int main()
{
    int tt=0,n;
    while(1)
    {
        flag=0;
        ww=0;
        tt++;
        n=0;
        for(int i=1;i<=6;i++)
        {
            scanf("%d",&aa[i]);
            ww+=aa[i]*i;
            n+=aa[i];
        }
        if(n==0)
            break;
        if(ww&1)
            flag=0;
        else
        {
            ww/=2;
            DFS(0,6);
        }
        printf("Collection #%d:\n",tt);
        if(flag)
            printf("Can be divided.\n\n");
        else
            printf("Can't be divided.\n\n");
    }
    return 0;
}
