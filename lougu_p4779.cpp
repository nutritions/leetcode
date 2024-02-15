/*https://www.luogu.com.cn/problem/P4779*/
//单源最短路（标准版

#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<cstring>
#define endl "\n"
#define inf 0x3f3f3f3f
const int N=1e5+5;
int n,m,s;
typedef struct 
{
    int v;//指向的顶点
    int w;//边权
}Edge;

vector<Edge> e[N];
vector<int> d(N,inf);
//int d[N];
int visited[N]={0};

//基本dijkstra
void dijkstra(int s){
    d[s]=0;
    for(int i=1;i<n;i++){//n-1轮循环可以求出所有结点最短距离了（第n-1轮有n-1个结点在最短路径集合中）
        int min_u=0;
        for(int j=1;j<=n;j++){
            if(!visited[j]&&d[j]<d[min_u]){
                min_u=j;
            }
        }
        visited[min_u]=1;
        for(vector<Edge>::iterator it =e[min_u].begin();it!=e[min_u].end();++it){
            int v=(*it).v;
            int w=(*it).w;
            if(w+d[min_u]<d[v]){
                d[v]=w+d[min_u];
            }
        }

    }
}

//堆优化dijkstra
void dijkstra_heap(int s){
    //小根堆，存储点到s的距离信息，距离最近的在堆顶，利用小根堆特性自动判断了到最短路径集合的最近结点
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;//到s距离、顶点
    q.push({0,s});
    d[s]=0;
    while(q.size()){
        pair<int,int> tmp=q.top();//顶部是最小距离
        q.pop();//出队表示加入最短路径上
        int min_u=tmp.second;
        if(visited[min_u])
            continue;
        visited[min_u]=1;
        //用新加入的结点松弛其指向的其他结点
        for(vector<Edge>::iterator it=e[min_u].begin();it!=e[min_u].end();++it){
            int v=(*it).v;
            int w=(*it).w;
            if(w+d[min_u]<d[v]){
                d[v]=w+d[min_u];
                q.push({d[v],v});//被松弛的结点，需要把新的距离信息加入优先队列中
            }

        }

    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    int u,v,w;
    while(m--){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
    }
    dijkstra_heap(s);
    for(int i=1;i<=n;i++){
        cout<<d[i]<<" ";
    }


    return 0;
}