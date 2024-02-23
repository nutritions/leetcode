/*https://www.luogu.com.cn/problem/P3379*/
#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;


int n,m,root;//结点个数、询问次数、树根编号
const int N=5*1e5+5;
vector<int> e[N];
int fa[N];//u的父节点
int wSon[N];//u的重儿子
int siz[N];//u为根的子树结点个数
int dep[N];//u的深度
int top[N];//u的重链顶点

//第一遍dfs，求出fa，wson，size，dep
void dfs1(int u,int f){
    //入，访问到u结点即可确定其父节点和深度，都是由父节点确定
    fa[u]=f;
    siz[u]=1;
    dep[u]=dep[f]+1;
    for(vector<int>::iterator it=e[u].begin();it!=e[u].end();++it){
       int v=*it;
       if(v==f){
        continue;
       }
       dfs1(v,u);
       //回，siz和wson需要子节点确定，在回溯时得到
       siz[u]+=siz[v];
       if(siz[wSon[u]]<siz[v]){
            wSon[u]=v;
       }
    }

}

//第二遍dfs，有了重儿子，可以求每个顶点的top，即进行重链剖分
void dfs2(int u,int t){
    top[u]=t;
    if(!wSon[u]) return;
    dfs2(wSon[u],t);//有重儿子时，沿着重儿子进行dfs，得到一条重链
    //回，一条重链求完，返回时对轻儿子dfs，继续求其他重链
    for(vector<int>::iterator it=e[u].begin();it!=e[u].end();++it){
        int v=*it;
        if(v==wSon[u]||v==fa[u]) continue;
        dfs2(v,v);
    }
}
int LCA(int u,int v){
    while(top[u]!=top[v]){//直到在一条重链上
        if(dep[top[u]]<dep[top[v]]){
            swap(u,v);//始终保持u是深度大的
        }
        u=fa[top[u]];//深度大的往上跳
    }
    return dep[u]<dep[v]?u:v;//返回深度小的
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>root;
    int x,y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(root,0);
    dfs2(root,root);
    while(m--){
        cin>>x>>y;
        cout<<LCA(x,y)<<endl;

    }

    return 0;
}