/*
代码填空题：
N! 末尾有多少个 00 呢？

N!=1×2×⋯×N。

代码框中的代码是一种实现，请分析并填写缺失的代码。
#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    while (n) {
        ans += //在这里填写必要的代码;
    }
    cout << ans << endl;
    return 0;
}

解题思路：
填空 n = n / 5

对于一个数的阶乘(分解成多个素数相乘)，如果想末尾出现 0 的话，只有当 5 和 2 出现的时候，才会在末尾出现 0 。

因为 2 的个数一定比 5 多。所以我们就可以得出一个结论，一个数的阶乘，末尾 0 的个数就是看里面 5 的个数。

现在变成求 1 到 n 的因子有多少个 5。对于包含 1 个 5 的数字，就是 n/5，包含两个 5 的数字个数为 n / 25。
通过 n = n / 5 的方式，每次剥掉一层 5。

*/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n,ans;
    cin>>n;
    while(n)
    {
        ans += n/=5; 
    }
    cout<<ans<<endl;
    
    return 0;
}