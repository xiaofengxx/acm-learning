#include<stdio.h>
int main()
{
    int M[10]={1,0,0,2,10,4,40,92,352,724};
    int i;
    scanf("%d",&i);
    while(i)
    {
        printf("%d\n",M[i-1]);
        scanf("%d",&i);
    }
    return 0;
}
