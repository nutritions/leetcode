/*
https://www.luogu.com.cn/problem/P3373
*/
#include <iostream>
using namespace std;
#define endl "\n"
#define ll long long
#define lc p << 1     // 左儿子
#define rc p << 1 | 1 // 右儿子
const int N = 1e5 + 5;
int arr[N];

int n, q, m; // 数据个数、操作次数、模数

struct trNode
{
    ll l, r, sum, add, mul; // 左右边界、区间和、加法懒标记、乘法懒标记
} tn[4 * N];

ll count(ll p)
{
    return tn[p].r - tn[p].l + 1;
}

// 上传，计算区间和
void pushup(ll p)
{
    tn[p].sum = tn[lc].sum + tn[rc].sum;
}

// 下传，有懒标记说明p被完全覆盖，往下传信息
void pushdown(ll p)//注意的是需要先乘后加，并且在区间乘时需要维护add
{
    tn[lc].sum = (tn[lc].sum * tn[p].mul + tn[p].add * count(lc))%m;
    tn[rc].sum = (tn[rc].sum * tn[p].mul + tn[p].add * count(rc))%m;

    tn[rc].mul = (tn[rc].mul * tn[p].mul)%m;
    tn[lc].mul = (tn[lc].mul * tn[p].mul)%m;

    tn[lc].add = ((tn[lc].add * tn[p].mul + tn[p].add))%m;
    tn[rc].add = ((tn[rc].add * tn[p].mul + tn[p].add))%m;

    tn[p].mul = 1;
    tn[p].add = 0;
}

// 建线段树
void build(ll p, ll l, ll r)
{ // 编号、左右范围
    tn[p] = {l, r, arr[l], 0, 1};
    if (l == r)
        return;
    ll mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}
// 区间全乘
void update_mul(ll p, ll l, ll r, ll k)
{
    if (l <= tn[p].l && tn[p].r <= r)
    {
        tn[p].add = (tn[p].add * k) % m;
		tn[p].mul = (tn[p].mul * k) % m;
		tn[p].sum = (tn[p].sum * k) % m;
        return;
    }
    pushdown(p);
    ll mid = (tn[p].l + tn[p].r) >> 1;
    if (l <= mid)
    {
        update_mul(lc, l, r, k);
    }
    if (r >= mid + 1)
    {
        update_mul(rc, l, r, k);
    }
    pushup(p);
}
// 区间全加
void update_add(ll p, ll l, ll r, ll k)
{
    if (l <= tn[p].l && tn[p].r <= r)
    { // 完全覆盖时，只需要更新p区间和以及懒标记
        tn[p].add = (tn[p].add + k) % m;
		tn[p].sum = (tn[p].sum + k * count(p)) % m;
        return;
    }
    pushdown(p); // 处理之前的懒标记
    ll mid = (tn[p].l + tn[p].r) >> 1;
    if (l <= mid)
    {
        update_add(lc, l, r, k);
    }
    if (r >= mid + 1)
    {
        update_add(rc, l, r, k);
    }
    pushup(p);
}
// 查询区间和
ll query(ll p, ll l, ll r)
{
    if (l <= tn[p].l && tn[p].r <= r)
    {
        return tn[p].sum % m;
    }
    pushdown(p);
    ll mid = (tn[p].l + tn[p].r) >> 1;
    ll sum = 0;
    if (l <= mid)
    {
        sum += query(lc, l, r);
        sum %= m;
    }
    if (r >= mid + 1)
    {
        sum += query(rc, l, r);
        sum %= m;
    }
    return sum % m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    build(1, 1, n);
    int op, x, y, k;
    while (q--)
    {
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            update_mul(1, x, y, k);
        }
        else if (op == 2)
        {
            cin >> k;
            update_add(1, x, y, k);
        }
        else
        {
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}