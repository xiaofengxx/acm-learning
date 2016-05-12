#include<cstdio>
char map[40][40];
int mm=0;
char aa[6]={'K','Q','R','B','N','P'};
char ab[6]={'k','q','r','b','n','p'};
int main()
{
    int c;
    for(int i=0;i<17;i++)
        scanf("%s",map[i]);
    printf("White: ");
    for(int p=0;p<6;p++)
    {
        for(int i=0;i<8;i++)
        {
            for(int o=0;o<8;o++)
            {
                if(map[(8-i)*2-1][o*4+2]==aa[p])
                {
                    if(mm)
                        printf(",");
                    mm=1;
                    if(p<5)
                        printf("%c",aa[p]);
                    printf("%c%d",o+'a',i+1);
                }
            }
        }
    }
    mm=0;
    printf("\nBlack: ");
    for(int p=0;p<6;p++)
    {
        for(int i=0;i<8;i++)
        {
            for(int o=0;o<8;o++)
            {
                if(map[i*2+1][o*4+2]==ab[p])
                {
                    if(mm)
                        printf(",");
                    mm=1;
                    if(p<5)
                        printf("%c",aa[p]);
                    printf("%c%d",o+'a',8-i);
                }
            }
        }
    }
    printf("\n");
    return 0;
}
