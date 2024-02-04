/*
![](https://www.luogu.com.cn/problem/P3372)
*/

//区间修改和查询：线段树
#include<iostream>
#include <algorithm>
using namespace std;
#define endl "\n"
#define ll long long
#define lc p<<1
#define rc p<<1|1//父节点编号为p，则左孩子编号为2p，右孩子编号为2p+1
const int N=1e5+5;
int n,m;
ll arr[N];
struct node{
    ll l,r,sum,add;
    //线段树每个结点存储左右边界和要查询的信息（这里是和），
    //add:懒标记（先把父节点标记，需要时再下传加上的数）,在区间修改时作用
}trNode[4*N];//N个数据的区间分成的区间总数不会超过4*N

//上传，计算区间和
void pushup(ll p){ 
  trNode[p].sum=trNode[lc].sum+trNode[rc].sum;
}

//下传
void pushdown(ll p){
    if(trNode[p].add){//p结点有懒标记，往下更新儿子结点信息
        trNode[lc].sum+=trNode[p].add*(trNode[lc].r-trNode[lc].l+1);
        trNode[rc].sum+=trNode[p].add*(trNode[rc].r-trNode[rc].l+1);
        trNode[lc].add+=trNode[p].add;
        trNode[rc].add+=trNode[p].add;
        trNode[p].add=0;//取消懒标记
    }
}
//建树  p为编号  从根节点1开始建
void build(ll p,ll l,ll r){
    trNode[p]={l,r,arr[l],0};
    if(l==r){
        return;
    }
    ll mid = (l+r)>>1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    pushup(p);
}
//区间每个值加k
void update(ll p, ll l, ll r ,ll k){
    if(l<=trNode[p].l&&trNode[p].r<=r){//区间完全包含，区间和加上区间长度*k，懒标记加上k
        trNode[p].sum+=k*(trNode[p].r-trNode[p].l+1);
        trNode[p].add+=k;
        return;
    }
    pushdown(p);//往下传信息
    ll mid=(trNode[p].l+trNode[p].r)>>1;
    if(l<=mid){
        update(lc,l,r,k);
    }
    if(r>=mid+1){
        update(rc,l,r,k);
    }
    pushup(p);//全部更新完成后，上传信息，更新根节点

}
//查询区间和
ll query(ll p,ll l,ll r){
                                                                              
    if(l<=trNode[p].l&&trNode[p].r<=r){
        return trNode[p].sum;
    }
    pushdown(p);//查询到了结点p，就把之前懒标记“偷的懒”补回来
    ll sum=0;
    ll mid=(trNode[p].r+trNode[p].l)>>1;
    if(l<=mid){
        sum+=query(lc,l,r);
    }
    if(r>=mid+1){
        sum+=query(rc,l,r);
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    build(1,1,n);
    int op,x,y,k;
    while(m--){
        cin>>op>>x>>y;
        if(op==2){//查询区间和
            cout<<query(1,x,y)<<endl;
        }else{//区间每个值加k
            cin>>k;
            update(1,x,y,k);
        }
    }
    return 0;
}