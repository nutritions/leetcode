/*https://www.luogu.com.cn/problem/P3366*/
// kruskal求MST

#include <algorithm>
#include <iostream>
#define endl "\n"

using namespace std;
const int N = 2e5 + 5;
int n, m;
int ans;
int cnt=0;
int fa[N];
struct edge {
    int u, v, w;
    bool operator<(const edge& t) const{
        return w < t.w;
    }
} e[N];
int find(int x){
    if(x==fa[x]){
        return x;
    }else{
        return fa[x]=find(fa[x]);
    }
}
bool kruskal() {
    sort(e,e+m);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for(int i=0;i<m;i++){
        int x=find(e[i].u);
        int y=find(e[i].v);
        if(x!=y){//不在一棵树上
            fa[x]=y;
            ans+=e[i].w;
            cnt++;
        }
        if(cnt==n-1){
            break;
        }            
    }
    return cnt==n-1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    if (!kruskal()) {
        cout << "orz" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}