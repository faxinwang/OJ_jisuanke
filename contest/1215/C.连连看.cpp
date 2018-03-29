/*
结果填空：
连连看是一款非常有意思的游戏.我们可以把任意两个在图的在边界上的相同的方格一起消掉
1 4 2 5
2 1 2 1
3 1 3 2
2 5 3 4

比如把两个 4 消掉以后，

1   2 5
2 1 2 1
3 1 3 2
2 5 3 

每次消掉两个方格的时候，都有会获得一个分数，第 i 次消的分数为 i × 方格的值。比如上面的消法，
是第一次消，获得的分数为 1 x 4 = 4。

请你帮忙最优操作情况下，获得的分数最多为多少。


解题思路：
用 dfs 求解，尝试将每个位置作为起点进行深搜，每一次搜索，找到两个相同的边界点，标记为已访问(已消除)，
然后找下一个点，一直进行下去，直到遍历完所有的消除方案，过程中记录下最优方案及其得分。

检测边界点的方法也很简单，只需要一
个点的四个方向中有一个点在地图外或者已经被标记，那么这个点就是边界点。

答案是 89 。 最优的消除方案为(2 2)、(1 1)、(1 1)、(3 3)、(4 4)、(5 5)。
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int dir[4][2]={0,1,1,0,0,-1,-1,0};
int mat[10][10];
bool vis[10][10];
int ans,n;
vector<int> best, tmp;

bool in(int x, int y){ return 1<=x && x<=n && 1<=y && y<=n; }

//检测当前状态下是否可以消除mat[x][y]这个元素
bool check(int x, int y)
{
    if(vis[x][y]) return false; //访问过，不可消除
    for(int i=0; i<4; ++i) //判断该点是否在边界上
    {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if(!in(tx,ty)) return true;
        if(vis[tx][ty]) return true;
    }
    return false; 
}

void dfs(int step, int sum)
{
    // printf("step=%d sum=%d\n", step, sum);
    if(sum > ans)
    {
        ans = sum;
        best = tmp;
    }
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(check(i,j))
                for(int p=1; p<=n; ++p)
                    for(int q=1; q<=n; ++q)
                    {
                        if(p==i && q==j) continue;
                        if( check(p,q) && mat[i][j] == mat[p][q] )
                        {
                            vis[i][j] = vis[p][q] = 1;
                            tmp.push_back(mat[i][j]);
                            dfs(step+1, sum + step * mat[i][j]);
                            tmp.pop_back();
                            vis[i][j] = vis[p][q] = 0;
                        }
                    }
        }
    }
}

int main()
{
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
    cin>>n;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            scanf("%d",&mat[i][j]);
    dfs(1,0);
    cout<<"max score:"<<ans<<endl;
    cout<<"best path:"; copy(best.begin(), best.end(), ostream_iterator<int>(cout," "));
    cout<<endl;

    return 0;
}
