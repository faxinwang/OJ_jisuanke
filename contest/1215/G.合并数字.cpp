/*
蒜头君得到了 n 个数，他想对这些数进行下面这样的操作，选出最左边的相邻的差的绝对值为 1 的两个数，
只保留较小的数，删去较大的数，直到没有两个相邻的差的绝对值为 11 的数，问最多可以进行多少次这样
的操作？

输入格式
输入第一行为一个整数n(1≤n≤10^5)，表示数字的总数

第二行为 n 个整数 x1,x2,...,xn(1<=xi <= 10^9)，表示这些数。

输出格式
输出一行，为一个整数，表示蒜头君最多可以进行多少次这样的操作。

样例输入
4
1 2 0 1
样例输出
3

解题思路：
用栈来维护每次合并完的数，每入栈一个数以后栈顶和次栈顶比较，如果可以合并就合并为新的栈顶，
并且再次与次栈顶比较直至无法合并，在合并过程中统计次数即可。

*/

#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    stack<int> s;
    int n,x, ans=0;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        scanf("%d",&x);
        while(!s.empty() && s.top() - x == 1)
        {
            s.pop();
            ++ans;
        }
        if(!s.empty() && x - s.top() == 1) ++ans;
        else s.push(x);
    }   
    cout<<ans<<endl;

    return 0;
}