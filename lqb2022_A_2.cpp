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
#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll n,m,x;
int dp[N];    //a^b=x  a,b中早出现的数字位置
map<ll,int> mp;
int max(int a,int b){
  return a>b?a:b;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);     //加速（很关键！）
  cin>>n>>m>>x;
  for(int i=1;i<=n;i++){
    ll data;
    cin>>data;
    dp[i]=max(dp[i-1],mp[data^x]);    //mp存放另一个数的位置
    cout<<dp[i]<<endl;
    mp[data]=i;
  }
  while(m--){
    int l,r;
    cin>>l>>r;
    if(dp[r]>=l) cout<<"yes\n";
    else cout<<"no\n";
  }
  return 0;
}