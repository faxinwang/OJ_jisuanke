/*
结果填空题：

给你一个从 n×n 的矩阵，里面填充 1 到 n×n 。例如当 n 等于 3 的时候，填充的矩阵如下。

1 2 3
4 5 6
7 8 9

现在我们把矩阵中的每条边的中点连起来，这样形成了一个新的矩形，请你计算一下这个新的矩形的覆盖的数字的和。
比如，n = 3 的时候矩形覆盖的数字如下。

  2
4 5 6
  8

那么当 nn 等于 101 的时候，矩阵和是多少？

解题思路：
我们会发现所有需要计算的点到中心点的距离（横坐标加纵坐标的距离和）都是小于等于 n / 2 的。
所以我们只需要把满足条件的点加上就可以了。

*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif 
    int n,cnt=0, mid, sum=0;
    cin>>n;  //输入101时 输出26020201
    mid = n / 2;
    //注意i和j的变化范围是从0到n-1
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            ++cnt;
            if(abs(i - mid) + abs(j - mid) <= mid) sum += cnt;
        }
    }
    cout<<sum<<endl;

    return 0;
}
