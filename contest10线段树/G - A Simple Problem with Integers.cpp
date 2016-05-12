#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=100010;
long long sum[maxn<<2];
long long add[maxn<<2];
void Push_Up(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void Push_Down(int rt,int m)
{
    if (add[rt])
    {
        add[rt<<1] += add[rt];
        add[rt<<1|1] += add[rt];
        sum[rt<<1] += add[rt] * (m - (m >> 1));
        sum[rt<<1|1] += add[rt] * (m >> 1);
        add[rt] = 0;
    }
}
void build(int l,int r,int rt) {
    add[rt] = 0;
    if (l == r) {
        scanf("%lld",&sum[rt]);
        return ;
    }
    int mid = (l + r) >> 1;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
    Push_Up(rt);
}
void update(int L,int R,int c,int l,int r,int rt) {
    if (L <= l && r <= R) {
        add[rt] += c;
        sum[rt] += (long long)c * (r - l + 1);
        return ;
    }
    Push_Down(rt , r - l + 1);
    int mid = (l + r) >> 1;
    if (L <= mid) update(L , R , c , l,mid,rt<<1);
    if (mid < R) update(L , R , c , mid+1,r,rt<<1|1);
    Push_Up(rt);
}

long long query(int L,int R,int l,int r,int rt) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    Push_Down(rt , r - l + 1);
    int mid = (l + r) >> 1;
    long long ret = 0;
    if (L <= mid) ret += query(L , R , l,mid,rt<<1);
    if (mid < R) ret += query(L , R , mid+1,r,rt<<1|1);
    return ret;
}

int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        build(1,n,1);
        char op[3];
        int a,b,c;
        while(q--)
        {
            scanf("%s",op);
            if (op[0] == 'Q')
            {
                scanf("%d%d",&a,&b);
                printf("%lld\n",query(a , b , 1 , n , 1));
            } else {
                scanf("%d%d%d",&a,&b,&c);
                update(a , b , c , 1 , n , 1);
            }
        }
    }
    return 0;
}
