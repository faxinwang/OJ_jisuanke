/*
结果填空题：
用 0,1,2,3 \cdots 70,1,2,3⋯7 这 88 个数组成的所有整数中，质数有多少个（每个数字必须用到且只能用一次）。
提示：以 00 开始的数字是非法数字。

解题思路：
1.首先进行素数打表，把10234567 到 76543210之间的所有素数全部找出了
2.逐个判断这些素数是否是右0到7这八个数字组成，统计合法数字的个数。
该方法比方法一要慢几秒钟。
*/

#include<bits/stdc++.h>
#include<cmath>
using namespace std;
const int maxn = 76543210;
const int minn = 10234567;

bool s[maxn];
int p[maxn];
int cnt=0;
void init()
{
     int n=sqrt(maxn);
//    int n = maxn;
    for(int i=2; i<=n; ++i)
    {
//        if(s[i]) continue;
        for(int j=i*i; j<=maxn; j+=i) s[j] = 1;
    }
    printf("Test1\n");
    for(int i=minn; i<maxn; ++i) if(s[i]==0) p[cnt++] = i;
    printf("Test2\n");
}

//判断数字n是否是右0到7这八个数字组成，且每个数字只出现一次。
int a[10];
bool check(int n)
{
    memset(a,0,sizeof(a));
    while(n)
    {
        int tmp = n % 10;
        if(a[tmp] || tmp>=8) return 0;
        ++a[tmp];
        n /= 10;
    }
    for(int i=0; i<8; ++i) if(a[i] == 0) return 0;
    return 1;
}

int main()
{
    init();
    int ans = 0;
    for(int i=0; i<cnt; ++i)
    {
        if(check(p[i])) ++ans;
    }
    
    printf("%d",ans);
    
    return 0;
}