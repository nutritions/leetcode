#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N=1e5;
int _next[N];

void getNext(string sub){
  _next[1]=0;
  int i=1,j=0;//i是next索引，j是某个next值
  while(i<sub.size()-1){
    if(j==0||sub[i]==sub[j]){
      _next[++i]=++j;
    }else{
      j=_next[j];
    }
  }
}

int KMP(string s,string sub){
  int i=1,j=1;//主串和模式串的指针
  int slen=s.size()-1;
  int sublen=sub.size()-1;
  while(i<=slen&&j<=sublen){
    if(j==0||s[i]==sub[j]){
      i++;
      j++;
    }else{
      j=_next[j];
    }
  }
  if(j>sublen){
    return i-sublen;
  }else{
    return 0;
  }
}

int main(){
  string s=" ";//主串
  string sub=" ";//模式串
  string tmp;
  cin>>tmp;
  s.append(tmp);
  cin>>tmp;
  sub.append(tmp);
  int slen=s.size()-1;
  int sublen=sub.size()-1;
  getNext(sub);
  cout<<_next[1]<<endl;
  cout<<sublen<<endl;
  for(int i=1;i<=sublen;i++){
      cout<<_next[i]<<" ";
  }
  cout<<KMP(s,sub)<<endl;
  return 0;
}