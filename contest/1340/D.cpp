/*
对于数列F(n)与G(n), 当n>2时, 有F(n) = (G(n-1) + 2*G(n-2)) mod M.
G(n) = (F(n-1) + 3*F(n-2)) mod M
M = 1000000009, F(1)=1, F(2)=5, G(1)=1, G(2)=7.
求F(G(x)), x是小于2^63的正整数.

解题思路:
使用矩阵快速幂
F(n)    |0 1 0 2|  F(n-1)
G(n)    |1 0 3 0|  G(n-1)
F(n-1)  |1 0 0 0|  F(n-2)
G(n-1)  |0 1 0 0|  G(n-2)

计算出系数矩阵A之后, 即可直接计算出任意F(n)和G(n)
           |F(2)|   |F(n)  |
A^(n-2) *  |G(2)| = |G(n)  | (n>2)
           |F(1)|   |F(n-1)|
           |G(1)|   |G(n-1)|

本题先要计算出G(n),也就是要计算A^(n-2), 得到Gn
再计算F(G(n)), 也就是要计算A^(Gn-2),得到Fn.
*/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL;
const LL mod = 1000000009;

struct Matrix
{
    int N,M;//N row, M col
    vector<vector<LL> > v;
    Matrix(int n, int m):N(n), M(m), v(n, vector<LL>(m, 0)){}
    
    //单位化,当矩阵是方阵的时候才可调用该函数
    void identify() { for(int i=0; i<N; ++i) v[i][i] = 1; }

    Matrix operator * (const Matrix& a)
    {
        Matrix ret(N, a.M);
        for(int i=0; i<N; ++i)
            for(int j=0; j<a.M; ++j)
                for(int k=0; k<N; ++k)
                {
                    ret.v[i][j] += v[i][k] * a.v[k][j] % mod;
                    if(ret.v[i][j] >= mod) ret.v[i][j] -= mod;
                }
        return ret;
    }

    void show(string str="")
    {
        cout<<str<<endl;
        for(int i=0; i<N; ++i)
        {
            for(int j=0; j<M; ++j) printf("%d ", v[i][j]);
            cout<<endl;
        }
    }
};

Matrix pow_mod(Matrix A, LL n)
{
    Matrix ret(A.N, A.M);
    ret.identify(); //单位化
    while(n)
    {
        if(n & 1) ret = ret * A;
        A = A * A;
        n >>= 1;
    }
    return ret;
}

int main()
{
    #ifdef WFX
    freopen("in.txt","r",stdin);
    #endif
    int a[4][4] = 
    {
        {0,1,0,3},
        {1,0,2,0},
        {1,0,0,0},
        {0,1,0,0}
    };
    int base[4]={7,5,1,1}; //G(n-1), F(n-1), G(n-2), F(n-2)

    Matrix A(4, 4);
    for(int i=0; i<4; ++i)
        for(int j=0; j<4; ++j)
            A.v[i][j] = a[i][j];
    

    Matrix Base(4, 1);
    for(int i=0; i<4; ++i) Base.v[i][0] = base[i];

    LL x;
    while(cin>>x)
    {
        if(x == 1) cout << 1 << endl;
        else if(x == 2) cout<< 204 << endl;
        else
        {
            Matrix Gx = pow_mod(A, x-2) * Base;
            LL gx = Gx.v[0][0];
            printf("G(%lld)=%lld\n",x, gx);
            Matrix FGx = pow_mod(A, gx-2) * Base;
            LL fgx = FGx.v[1][0];
            printf("F(G(%lld))=%lld\n",x, fgx);
        }
    }

    return 0;
}
