#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
struct Matrix {
    long long mat[2][2];
    Matrix operator*(const Matrix& other) const {
        Matrix res = {{{0,0},{0,0}}};
        for(int i = 0;i<2;i++) {
            for(int j = 0;j<2;j++) {
                for(int k=0;k<2;k++) {
                    res.mat[i][j]+= mat[i][k]*other.mat[k][j];
                }
            }
        }
        return res;
    }
    bool operator==(const Matrix& other) const {
        return mat[0][0]==other.mat[0][0]&& mat[0][1]==other.mat[0][1] &&
               mat[1][0]==other.mat[1][0] && mat[1][1]==other.mat[1][1];
    }
};

const Matrix I={{{1,0},{0,1}}};
const Matrix M0={{{0,-1},{1,-1}}};
const Matrix M1={{{-1,1},{-1,0}}};
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    long long ans = 0;
    // Frequency counters for our three states: Identity, M0, and M1
    long long count_I = 0, count_M0 = 0, count_M1 = 0;
    count_I = 1; 
    Matrix curr_prefix = I;

    // Step 1: Matrix Multiplication pass
    for (int i=0;i<n;++i) {
        if (s[i]=='0') {
            curr_prefix=curr_prefix*M0;
        } else {
            curr_prefix=curr_prefix* M1;
        }
        if(curr_prefix==I) {
            ans+=count_M0+count_M1;
            count_I++;
        } 
        else if(curr_prefix==M0) {
            ans+=count_I+count_M1;
            count_M0++;
        }
        else if(curr_prefix==M1) {
            ans+=count_I + count_M0;
            count_M1++;
        }
    }
    long long len=1;
    for(int i=1;i<=n;++i) {
        if (i<n&&s[i]!=s[i - 1]) {
            len++;
        }else{
            if(len >= 3){
                long long k =(len-1)/2;
                ans-= k*(len-k-1);
            }
            len = 1;
        }
    }
    cout<<ans<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}