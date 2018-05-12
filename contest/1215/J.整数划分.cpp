/*
蒜头君特别喜欢数学。今天，蒜头君突发奇想：如果想要把一个正整数 n 分解成不多于 k 个正整数相加的形式，
那么一共有多少种分解的方式呢？

蒜头君觉得这个问题实在是太难了，于是他想让你帮帮忙。

输入格式
共一行，包含两个整数 n(1≤n≤300) 和 k(1≤k≤300)，含义如题意所示。

输出格式
一个数字，代表所求的方案数。

样例输入
5 3
样例输出
5

提示
对于样例，5 有 5 种不大于 3 个数的相加方式， 分别是：
5 = 5
5 = 4 + 1
5 = 3 + 2
5 = 3 + 1 + 1
5 = 2 + 2 + 1

解题思路：
采用动态规划的方式。令 dp(n, k) 表示将 n 分解为不超过 k 个数之和的方案数。
分成四种情况讨论，
1. n = 1 或者 k = 1 的时候，只有一种方案。
2. n < k 的时候，实际上方案树就是 dp(n ,n)，因为 n 不可能分解超过 n 个数。
3. n > k 的时候，这时候，我们分情况，如果一定拆成 k 个数，那么实际上每个数必须大于等于 1，
   我们把每个数都减去 1，那么对应的方案数是 dp(n - k, k)，如果拆成小于 k 个数，那么就是 
   dp(n, k - 1)，这时候方案数是 dp(n, k - 1) + dp(n - k, k)。
4. n = k 的时候，沿用 3 结论，这时候，如果一定要拆成 k 个数，实际上只有一种方案，那么总方
   案为 dp(n, k-1) + 1。
*/

#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 305;
typedef long long LL;

LL dp[maxn][maxn];

LL f(int n,int k)
{
    if(dp[n][k]) return dp[n][k];
    if(n == 1 || k == 1) return dp[n][k] = 1;
    if(n < k) return dp[n][k] = f(n,n);
    if(n == k) return dp[n][k] = f(n,k-1) + 1;
    if(n > k) return dp[n][k] = f(n, k-1) + f(n-k, k);   
}

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n,k;
    cin>>n>>k;
    cout<<f(n,k)<<endl;

    return 0;
}