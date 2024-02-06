/*https://www.luogu.com.cn/problem/P3374*/
// 参考：https://www.cnblogs.com/dx123/p/17933150.html
//单点修改和区间查询
#include <iostream>
using namespace std;
#define endl "\n"
#include <vector>
const int N = 5 * 1e5;
vector<int> sum(N);//部分前缀和（相关联的）
int n, m;
//取出二进制下x的最低位以及后面的0，用于向前和向后找结点
int lowbit(int x){
    return x&-x;//取反加1再异或
}
// 单点x加上k
// 需要向后更新
void update(int x,int k)
{
    while(x<=n){
        sum[x]+=k;//当前结点前缀和更新
        x+=lowbit(x);//向后找关联的结点也有更新
    }
}
// 求前缀和 --区间和减一下就好了
// 部分前缀和向前找，把前缀和补全
int query(int x)
{
    int pre_sum=0;
    while(x){
        pre_sum+=sum[x];
        x-=lowbit(x);
    }
    return pre_sum;
}
int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin>>num;
        update(i,num);//单点修改相当于建树
    }
    int op, x, y;

    while (m--)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            update(x,y);
        }
        else
        {
            cout << query(y)-query(x-1) << endl;
        }
    }

    return 0;
}
