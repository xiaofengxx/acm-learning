#include<cstdio>
char mapx[9][9];
int n,k,sum=0;
int flag[9];
void sq(int high,int q)
{
    int i,j,k,l;
    for(i=0;i<n;i++)
    {
        if(mapx[high][i]=='#'&&flag[i]==0)
        {
            if(q==1)
            {
                sum++;
            }
            else
            {
                flag[i]=1;
                for(l=high+1;l<n-q+2;l++)
                    sq(l,q-1);
                flag[i]=0;
            }
        }
    }
}
int main(void)
{
    int i;
    while(scanf("%d%d",&n,&k))
    {
        if(n==-1&&k==-1)
            break;
        for(i=0;i<9;i++)
            flag[i]=0;
        for(i=0;i<n;i++)
            scanf("%s",mapx[i]);
        for(i=0;i<n;i++)
            sq(i,k);
        printf("%d\n",sum);
        sum=0;
    }
}




#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
struct flog
{
    char map [10][10];
    int x; //��һ�����ӵ�����
};
int m;
int ans;
void DFS(flog tmp,int n)
{
    if(n==0)
    {
        ans++;
        return ;
    int i,j;
    for (i=tmp.x+1;i<=m-n;i++)
    {//���ϸ����ӵ���һ�п�ʼ�ѣ����ʣ��ɷ����������Դ���ʣ�������������֪����ʱ�޽�
        for (j=0;j<m;j++)
        {//�Ӹ��еĵ�һ�����̿�ʼ�ѵ����һ��
            if (tmp.map[i][j]=='#')
            {//����ҵ���һ����Է�����
                flog tmp2;
                tmp2=tmp;
                tmp2.x=i;//���¸ĵ������
                int k;
                for (k=i+1;k<m;k++)
                {//�������̣���Ϊ������������к͸���֮ǰ��������������ֻ�ø��¸�����ͬ�е�����
                    tmp2.map[k][j]='.';
                }
        DFS(tmp2,n-1);//�ź�һ�����ӣ�������

            }
    }
        }
    }
 }
 int main()
 {
    int n; //Ҫ������ӵĶ���
    while (scanf("%d%d",&m,&n) , m != -1 || n != -1 )
    {
        ans=0;//��ʼ��Ϊ0
        flog map;
        map.x=-1;//��ʱ��δ�����ӣ���ʼ��Ϊ-1
        int i;
        for (i=0;i<m;i++)
        {
            scanf("%s",map.map[i]);
        }
        DFS(map,n);
            printf("%d\n",ans);
        }
        return 0;
}
