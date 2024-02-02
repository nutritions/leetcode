/*
给定一个长度为 n 的数列 A1, A2, · · · , An 和一个非负整数 x，给定 m 次查询, 
每次询问能否从某个区间 [l,r] 中选择两个数使得他们的异或等于 x 。

输入格式：输入的第一行包含三个整数 n, m, x 。
第二行包含 n 个整数 A1, A2, · · · , An 。
接下来 m 行，每行包含两个整数 li ,ri 表示询问区间 [li ,ri ] 。

输出格式：
对于每个询问, 如果该区间内存在两个数的异或为 x 则输出 yes, 否则输出 no。

数据范围：对于所有评测用例，1 ≤ n, m ≤ 100000 ，0 ≤ x < 2^20 ，1 ≤ li ≤ ri ≤ n ， 0 ≤ Ai < 2^20
*/

//利用a^b=x可以得到b^x=a，
//因此可以确定b对应的a所在的位置（认为a在b的左边）
//用dp存储对应的最靠近b的a的位置（越小的区间，只要l<=dp[r],说明这个区间可以）
#include<iostream>
#include<vector>
#include<map>
#define endl "\n"//endl比\n慢，一直卡在这里超时
using namespace std;
typedef long long ll;
const int MAX = 1e5+5;
ll n,m;//数据格式，测试次数
ll x;//a^b=x
vector<int> dp(MAX,-1);
map<ll,int> idx;//表示b对应最近的a的位置

int max(int a,int b){
  return a>b?a:b;
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m>>x;
  for(int i=1;i<=n;i++){
    ll num;
    cin>>num;
    dp[i]=max(dp[i-1],idx[num^x]);//map[key]不存在则返回零
    idx[num]=i;
  }
  while(m--){
    int l,r;
    cin>>l>>r;
    if(dp[r]>=l){
      cout<<"yes"<<endl;
    }else{
      cout<<"no"<<endl;
    }
  }
  return 0;
}