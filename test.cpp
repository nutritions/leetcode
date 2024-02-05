#include <iostream>
#define lc p << 1     // 左儿子
#define rc p << 1 | 1 // 右儿子
#define MAXN 100010
#define ll long long

using namespace std;

int n, m, mod;
int a[MAXN];

struct Segment_Tree {
	ll sum, add, mul;
	int l, r;
}tn[MAXN * 4];

void update(int p) {
	tn[p].sum = (tn[lc].sum + tn[rc].sum) % mod;
    return;
}

void pushdown(int p) { //pushdown的维护
	tn[lc].sum = (tn[lc].sum * tn[p].mul + tn[p].add * (tn[lc].r - tn[lc].l + 1)) % mod;
	tn[rc].sum = (tn[rc].sum * tn[p].mul + tn[p].add * (tn[rc].r - tn[rc].l + 1)) % mod;
	
	tn[lc].mul = (tn[lc].mul * tn[p].mul) % mod;
	tn[rc].mul = (tn[rc].mul * tn[p].mul) % mod;
	
	tn[lc].add = (tn[lc].add * tn[p].mul + tn[p].add) % mod;
	tn[rc].add = (tn[rc].add * tn[p].mul + tn[p].add) % mod;
		
	tn[p].add = 0;
	tn[p].mul = 1;
	return; 
}

void build_tree(int p, int l, int r) { //建树
	tn[p].l = l;
	tn[p].r = r;
	tn[p].mul = 1;
	
	if (l == r) {
		tn[p].sum = a[l] % mod;
		return;
	}
	
	int mid = (l + r) >> 1;
	build_tree(lc, l, mid);
	build_tree(rc, mid + 1, r);
	update(p);
	return;
}

void ChangeMul(int p, int x, int y, int k) { //区间乘法
	if (x <= tn[p].l && tn[p].r <= y) {
		tn[p].add = (tn[p].add * k) % mod;
		tn[p].mul = (tn[p].mul * k) % mod;
		tn[p].sum = (tn[p].sum * k) % mod;
		return;
	}
	
	pushdown(p);
	int mid = (tn[p].l + tn[p].r) >> 1;
	if (x <= mid) ChangeMul(lc, x, y, k);
	if (y > mid) ChangeMul(rc, x, y, k);
	update(p);
	return;
}

void ChangeAdd(int p, int x, int y, int k) { //区间加法
	if (x <= tn[p].l && tn[p].r <= y) {
		tn[p].add = (tn[p].add + k) % mod;
		tn[p].sum = (tn[p].sum + k * (tn[p].r - tn[p].l + 1)) % mod;
		return;
	}
	
	pushdown(p);
	int mid = (tn[p].l + tn[p].r) >> 1;
	if (x <= mid) ChangeAdd(lc, x, y, k);
	if (y > mid) ChangeAdd(rc, x, y, k);
	update(p);
	return;
}

ll AskRange(int p, int x, int y) { //区间询问
	if (x <= tn[p].l && tn[p].r <= y) {
		return tn[p].sum;
	}
	
	pushdown(p);
	ll val = 0;
	int mid = (tn[p].l + tn[p].r) >> 1;
	if (x <= mid) val = (val + AskRange(lc, x, y)) % mod;
	if (y > mid) val = (val + AskRange(rc, x, y)) % mod;
	return val;
}

int main() {
	scanf("%d%d%d", &n, &m, &mod);
	
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	build_tree(1, 1, n);
	
	for (int i = 1; i <= m; i++) {
		int opt, x, y;
		scanf("%d%d%d", &opt, &x, &y);
		if (opt == 1) {
			int k;
			scanf("%d", &k);
			ChangeMul(1, x, y, k);
		}
		if (opt == 2) {
			int k;
			scanf("%d", &k);
			ChangeAdd(1, x, y, k);
		}
		if (opt == 3) {
			printf("%lld\n", AskRange(1, x, y));
		}
	}
    
	return 0;
}