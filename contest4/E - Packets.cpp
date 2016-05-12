#include<stdio.h>
int i;
int mm;
int aabb;
int cc[6];
int main(void)
{
    while(1)
    {
        mm=1;
        aabb=0;
        for(i=0;i<6;i++)
        {
            scanf("%d",&cc[i]);
            if( cc[i]!=0 )
            {
                mm=0;
            }
        }
        if(mm==1)
        {
            break;
        }
        aabb += cc[5]+cc[4]+cc[3];
        cc[0]-=11*cc[4];
        cc[1]-=5*cc[3];
        if(cc[1] < 0)
        {
            cc[1]+=5*cc[3];
            cc[0]-=4*(5*cc[3]-cc[1]);
            cc[1]=0;
        }
        aabb+=cc[2]/4;
        if(cc[2]%4!=0)
        {
            aabb++;
            if(cc[2]%4==3)
            {
                if(cc[1]>0)
                {
                    cc[1]-=1;
                    cc[0]-=5;
                }
                else
                {
                    cc[0]-=9;
                }

            }
            if(cc[2]%4 ==2)
            {
                if( cc[1]<=0)
                {
                    cc[0]-=18;
                }
                else
                {
                    if( cc[1]>=3)
                    {
                        cc[1]-=3;
                        cc[0]-=6;
                    }
                    else
                    {
                        cc[0]-= 4*(3-cc[1])+6;
                        cc[1]=0;
                    }
                }
            }
            if(cc[2]%4 ==1)
            {
                if(cc[1]<=0)
                {
                    cc[0]-=27;
                }
                else
                {
                    if(cc[1]>=5)
                    {
                        cc[1]-=5;
                        cc[0]-=7;
                    }
                    else
                    {
                        cc[0]-=4*(5-cc[1])+7;
                        cc[1]=0;
                    }
                }
            }

        }
        if( cc[1]>0)
        {
            aabb+=cc[1]/9;
            if(cc[1]%9!= 0)
            {
                aabb++;
                cc[0]-= 4*(9-cc[1]%9);
                cc[1]=0;
            }
        }
        if(cc[0]>0)
        {
            aabb+=cc[0]/36;
            if(cc[0]%36!=0)
            {
                aabb++;
            }
        }
        printf("%d\n",aabb);

    }
    return 0;
}
