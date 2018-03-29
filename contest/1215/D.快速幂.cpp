/*
代码填空题：
一个数的整数次幂，是我们在计算中经常用到的，但是怎么可以在 O(log(n)) 的时间内算出结果呢？
代码框中的代码是一种实现，请分析并填写缺失的代码，求 x^y % p 的结果。

#include <iostream>
using namespace std;

int pw(int x, int y, int p) {
    if (!y) {
        return 1;
    }
    int res =   ;//在这里填写必要的代码
    if (y & 1) {
        res = res * x % p;
    }
    return res;
}

int main() {
    int x, y, p;
    cin >> x >> y >> p;
    cout << pw(x, y, p) << endl;
    return 0;
}

解题思路：
对于 x^y % p, 可以写成
x^(y/2) * x^(y/2)       y为偶数
x^(y/2) * x^(y/2) * x   y为奇数


测试：

input
1 2 3
1 1 5
0 0 5
0 1 5
1 0 5
10 10 10
123 456 789

output
1  1
1  1
1  1
0  0
1  1
0  0
699  699

*/


#include <iostream>
using namespace std;

//递归写法
int pw(int x, int y, int p) {
    if(y == 0) return 1;
    int res =  (pw(x,y/2,p) % p) * (pw(x,y/2,p) % p) % p ;//在这里填写必要的代码
    if (y & 1)  res = res * x % p;
    return res;
}

//循环写法
int quick(int x, int y, int p)
{
    int ans = 1;
    x %= p;
    while(y)
    {
        if(y & 1) ans = ans * x % p;
        y >>= 1;
        x = x * x % p;
    }
    return ans;
}

int main() {
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    int x, y, p;
    while(cin >> x >> y >> p)
    {
        cout << pw(x, y, p) << "  "<< quick(x,y,p)<<endl;
    }
    
    return 0;
}