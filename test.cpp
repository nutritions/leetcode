#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int a[500005],s[500005]; //差分的区间和

int lowbit(int x){ //提取x的低位2次幂数
  return x&-x;
}
void change(int x,int k){ //向后修
  while(x<=n) s[x]+=k, x+=lowbit(x);
}
int query(int x){ //向前查
  int t=0;
  while(x) t+=s[x], x-=lowbit(x);
  return t;
}
int main(){
  cin>>n>>m; int op,x,y,k;
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  for(int i=1;i<=m;i++){
    scanf("%d%d",&op,&x);
    if(op==1){
      scanf("%d%d",&y,&k);
      change(x,k); change(y+1,-k); //差分
    }
    else printf("%d\n",a[x]+query(x));
  }
}