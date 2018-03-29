/*
结果填空：
一个有 20 个节点的二叉树，其中序遍历的结果为 (1,2,3⋯20)，其中1,2,3,⋯20 为节点编号。每个结点都有一个分数，
节点 1 到 节点 20 的分数依次为

9 8 9 9 5 7 4 2 2 4 5 6 7 8 9 3 3 4 5 1

每个结点 i 都有一个加分，如果是叶子节点，这个节点的加分 = 结点分数。
否则这个节点的加分 = 左儿子的加分 × 右儿子的加分 + 自己的分数。
如果左儿子或者右儿子为空，我们用 1 代替。

那么对于这 20 个点，中序遍历的结果为 (1,2,3⋯20) 的所有二叉树中，根节点加分最多的二叉树的加分是多少。

解题思路：
可以用 dfs 直接搜索。dfs 搜索方法很好写，对于每棵子树，只需要枚举一下根节点即可，然后取加分最大的一棵。

另外的方法就是标程的方法，用 dp[i][j] 表示 i 到 j 组成一棵子树的的最大分数，然后进行区间 dp 即可。

dfs 的方法，可以转换成动态规划，也就是记忆化搜索。

答案是 53071238

*/

#include<iostream>
#include<cstdio>
using namespace std;

int dp[30][30]; // dp[i][j]表示 i 到 j 组成一棵子树的的最大分数
int a[30];

int dfs(int L,int R)
{
    if(dp[L][R]) return dp[L][R]; 
    if(L > R) return 1; //空结点
    if(L == R) return a[L]; //叶子结点
    //枚举以结点i作为根结点时的最大得分，无论以哪个结点作为根结点，都有符合题目要求的二叉树结构。
    int ans = 0;
    for(int i=L; i<=R; ++i) 
    {
        int tmp = dfs(L, i-1) * dfs(i+1,R) + a[i];
        if(tmp > ans) ans = tmp;
    }
    return dp[L][R] = ans;
}

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i) cin>>a[i];
    cout<< dfs(1,n) <<endl;

    return 0;
}