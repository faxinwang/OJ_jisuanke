/*
今天蒜头君拿到了一个数轴，上边有 n 个点，但是蒜头君嫌这根数轴不够优美，想要通过加一些点让它变优美，
所谓优美是指考虑相邻两个点的距离，最多只有一对点的距离与其它的不同。

蒜头君想知道，他最少需要加多少个点使这个数轴变优美。

输入格式
输入第一行为一个整数n(1≤n≤10^5)，表示数轴上的点数。
第二行为 n 个不重复的整数 x1,x2,...,xn(-10^9 <= xi <= 10^9)，表示这些点的坐标，点坐标乱序排列。

输出格式
输出一行，为一个整数，表示蒜头君最少需要加多少个点使这个数轴变优美。

样例输入
4
1 3 7 15

样例输出
1

解题思路：
考虑两对相邻点距离怎么由不同的通过加点变为全部相同，也就是对线段进行分割，分割成相同长度的若干段，
这个长度最大也就是原来两条线段长度的最大公约数，我们先对点排好序然后做差，得到相邻点距离，因为最多
允许有一段距离跟其它不同，可以枚举不同的是哪一段，对其它段求最大公约数。

怎么快速求出这个值，可以运用前缀和的思路，预处理出前缀 GCD 和后缀 GCD ，那么其它段的 GCD 就可以
通过这两个 GCD 再求一遍 GCD 得到。得到分割后的距离后，每一段需要加的点就可以算了，但是如果每一次
都去看每一段要加多少点还是太慢了，我们可以预处理得到最左点和最右点的距离，减去枚举中的那一段，再
除以最大公约数得到一共会被分成多少小段，需要加的点数就是这个数字减去原来有多少段，也就是减去 n - 2。

*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1e5+5;

int gcdL[maxn]; //前缀GCD
int gcdR[maxn]; //后缀GCD
int p[maxn]; //保存点的坐标
int dist[maxn]; //记录点排序后每段距离的长度。

int GCD(int a,int b)
{
    while(a && b) a>b? a = a % b : b = b % a;
    return a+b;
}


int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n ;++i) scanf("%d",&p[i]);
    sort(p+1, p+n+1);
    //n个点,n-1段距离
    for(int i=1; i<n; ++i) dist[i] = p[i+1] - p[i];  
    int sum = p[n] - p[1]; //总长度

    //计算前缀GCD, n-1段距离，n-1个前缀GCD
    gcdL[1] = dist[1];
    for(int i=2; i<n; ++i) gcdL[i] = GCD(gcdL[i-1], dist[i]);
    //计算后缀GCD，n-1段距离，n-1个后缀GCD
    gcdR[n-1] = dist[n-1];
    for(int i=n-2; i>=1; --i) gcdR[i] = GCD(gcdR[i+1], dist[i]);
    //枚举可以忽略的一段距离,计算最少需要添加的点数
    int ans=1e9, gcd;
    for(int i=1; i<n; ++i)
    {
        if(i == 1) gcd = gcdR[2]; //gcd等于右边n-2段距离的最小公倍数
        else if( i == n-1) gcd = gcdL[n-2]; //gcd等于左边n-2段距离的最小公倍数
        else gcd = GCD(gcdL[i-1], gcdR[i+1]); //gcd等于除去第i段距离后剩下的n-2段距离的最小公倍数
        int cnt = ( sum- dist[i]) / gcd - n + 2; //需要添加的点数即为可以分成的小段数再减去原本已有的段数(n-2)
        ans = min(ans, cnt);
    }
    cout<<ans<<endl;

    return 0;
}