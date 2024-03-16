#include<iostream>
#include<cstring>
using namespace std;
#define endl "\n"
#define ll long long
const int N=101;
const int mod=1e9+7;
int n;
ll k;

class matrix{
    public:
    ll m[101][101];
    matrix(){
        memset(m,0,sizeof(m));
    }
    matrix operator*(matrix &x){
        matrix t;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                for(int k=1; k<=n; k++)
                    t.m[i][j]=(t.m[i][j]+this->m[i][k]*x.m[k][j])%mod;//注意取模
        return t;
    }
    void printMatrix(){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++)
                cout<<this->m[i][j]<<" ";
            cout<<endl;
        }
    }
    void initMatrix(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>this->m[i][j];
            }
        }
    }
};

matrix quickpow(matrix &A,ll k){
    matrix ans;
    for(int i=1;i<=n;i++){
        ans.m[i][i]=1;
    }//单位矩阵开始乘
    while(k){
        if(k&1){
            ans=ans*A;
        }
        A=A*A;
        k=k>>1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    matrix A;
    A.initMatrix();
    matrix ans=quickpow(A,k);
    ans.printMatrix();
    return 0;
}