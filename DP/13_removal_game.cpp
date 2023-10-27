#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][5005][5005];
int X(int p,int i,int j,vector<int> &v){
    if(i > j) return 0;
    if(dp[p][i][j] != -1) return dp[p][i][j];
    int ans = 0;
    if(p == 0){
        ans = max(v[i]+X(1,i+1,j,v), v[j]+X(1,i,j-1,v));
    }else{
        ans = min(X(0,i+1,j,v), X(0,i,j-1,v));
    }
    return dp[p][i][j] = ans;
}
signed main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &temp:v) cin >> temp;
    memset(dp,-1,sizeof(dp));
    int ans = X(0,0,n-1,v);
    cout << ans << "\n";
    return 0;
}
