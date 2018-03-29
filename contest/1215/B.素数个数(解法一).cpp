/*
结果填空题：
用 0,1,2,3 \cdots 70,1,2,3⋯7 这 88 个数组成的所有整数中，质数有多少个（每个数字必须用到且只能用一次）。
提示：以 00 开始的数字是非法数字。

解题思路：
因为我们需要判断一个数字是否是素数判定次数过多，所以这里使用素数筛法打表，便于查询。

然后我们需要把这 8 个数字全排列，这里和之前的全排列不太一样，这里的全排列第一个数字不能是 0 ，
另外我们还需要记录我们全排列的结果。所以我们使用一个数字来记录全排列的结果 num，这样也便于查询
是否是素数 。添加一个数字的时候我们通过 10*num + i 完成把先添加的数字放到数字末尾 。对于第一位
数字不能为 0 ，我们可以通过判定 num 是否为 0 来判定第一位数字是否放 0 。

这些细节处理完之后，剩下的就是一个简单的递归了。答案是2668

*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn = 76543210+5;
const int M = 8;
bool p[maxn], vis[10];
int ans=0;

void init_prime(int N)
{
    int n = sqrt(N);
    p[0] = p[1] = 1;
    for(int i=2; i<=n; ++i)
        if(!p[i])
            for(int j=i*i; j<N; j+=i)
                p[j] = 1; // is not prime
}

//枚举的由0到7中的数字组成的数，k为num的数字位数
void dfs(int num, int k)
{
    // printf("k=%d\n",k);
    if(k == M) //已经有了M位数
    {
        // printf("%d\n", num);
        if(p[num] == 0) ++ans;
        return;
    }
    //枚举下一位数字的取值，如果num为0,则下一位不能取0
    for(int i=(num==0?1:0); i<M; ++i )
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(num * 10 + i,  k+1);
            vis[i] = 0;
        }
        
    }
}

int main()
{
    init_prime(maxn);
    dfs(0,0);
    cout<<ans<<endl;

    return 0;
}