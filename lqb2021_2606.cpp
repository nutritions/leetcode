/*https://www.dotcpp.com/oj/problem2606.html*/
//由于根没有兄弟，所以高度完全取决于儿子结点怎么排列
//而左子树只连儿子，右子树只连兄弟，所以所有儿子一定是沿着右子树依次相连的
//如果把最高的放在最后相连，就可以使得总高度最高，因为其他的儿子的儿子高度一定小于这个高度，被兄弟的高度覆盖
//这样就可以得到总高度应该为最高儿子+剩余儿子个数+根=最高儿子高度+根儿子个数
//因此，可以采用树形dp
#include<iostream>
//#include<algorithm>
#include<vector>
#define endl "\n"
using namespace std;
const int N=100005;
vector<int> edge[N];//edge[u]表示u的所有邻边
int n;
int dp(int i){//计算i为根的转换后的树的最高高度
    int ans=0;
    int sonCnt=0;
    for(vector<int>::iterator it=edge[i].begin();it!=edge[i].end();++it){
        int j=*it;
        sonCnt++;
        ans=max(ans,dp(j));//找儿子结点最大高度
    }
    ans+=sonCnt;//加上儿子个数就是根最大高度
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int x;
    for(int i=2;i<=n;i++){
        cin>>x;
        edge[x].push_back(i);//只需要找儿子，所以添加单向边即可，就不用处理访问到父节点的情况了
    }
    cout<<dp(1)<<endl;
    
    return 0;

    
}
