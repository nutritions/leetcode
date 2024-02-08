/*https://www.luogu.com.cn/problem/P3366*/

// prim算法
// 每次选出到集合U最近的结点加入最小生成树
// 因此需要记录结点u相邻结点的编号和边权，以及其他结点到集合U的最近距离和是否在集合U中
#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9
#define endl "\n"
const int N = 5005;  // 结点最大数量
int n, m;
struct edge {
    int v;  // 下一个结点
    int w;  // 权重
};
vector<edge> e[N];         // e[u]存储与u相邻的结点编号和边权
vector<int> dist(N, INF);  // dist[u]表示结点u到结合U的最近距离,需要初始化为inf
int visited[N];            // 记录是否在集合U中，1表示在
// prim求MST
bool prim(int s, int& ans) {  // s为起始结点，没有要求就默认1
    int cnt = 1;
    visited[s] = 1;
    for (vector<edge>::iterator it = e[s].begin(); it != e[s].end(); ++it) {
        edge ed = *it;
        if (ed.w < dist[ed.v]) {
            dist[ed.v] = ed.w;
        }
    }  // 将s加入集合U

    // n-1轮循环
    for (int i = 1; i < n; i++) {
        int min_u = 0;  // dist[0]是INF
        // 找最近的结点
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < dist[min_u]) {
                min_u = j;
            }
        }
        visited[min_u] = 1;  // 最近的结点加入U
        ans += dist[min_u];
        if (dist[min_u] != INF) {//判断是否连通
            cnt++;
        }
        // 相关结点需要更新dist
        for (vector<edge>::iterator it = e[min_u].begin(); it != e[min_u].end(); ++it) {
            edge ed = *it;
            if (ed.w < dist[ed.v]) {
                dist[ed.v] = ed.w;
            }
        }
    }

    return cnt == n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    int u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});  // 无向边
    }
    int ans = 0;
    if (prim(1, ans)) {
        cout << ans << endl;
    } else {
        cout << "orz" << endl;
    }

    return 0;
}