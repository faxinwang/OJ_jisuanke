#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;
const int maxn = 20005;

int a[maxn];

LL mul(LL a , LL b)
{
    LL ans=0;
    while(b)
    {
        if(b&1) ans = ans + a;
        a <<= 1;
        b >>=1 ;
    }
    return ans;
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif

    LL N, p,s,x, Max=0;
    scanf("%lld",&N);
    for(int i=0; i<N; ++i)
    {
        scanf("%lld",&x);
        ++a[x];
        Max < x? Max = x : 0;
    }
    scanf("%lld%lld", &p, &s);

    bool flag=1;
    for(int i=Max, j=Max; i>=2; --i)
    {
        // printf("%d %d ", i, a[i]);
        LL total =  mul(p, a[i]);
        if(s >= total )
        {
            s -= total;
            a[i-1] += a[i];
        } 
        else
        {
             printf("%d\n",i);
             flag = 0;
             break;
        }
    }
    if(flag) printf("1");

    return 0;
}