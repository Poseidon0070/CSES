// Tabulation 
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n,m; cin >> n >> m;
//     vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
//     for(int i{1};i<=n;i++) dp[i][1] = i-1;
//     for(int i{1};i<=m;i++) dp[1][i] = i-1;
//     for(int i{};i<=min(m,n);i++) dp[i][i] = 0;
//     for(int i{2};i<=n;i++){
//         for(int j{2};j<=m;j++){
//             for(int k{1};k<j;k++){
//                 dp[i][j] = min(dp[i][j],1+dp[i][j-k]+dp[i][k]);
//             }
//             for(int k{1};k<i;k++){
//                 dp[i][j] = min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
//             }
//         }
//     }
//     cout << dp[n][m] << "\n";
//     return 0;
// }


// Memoization 

#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int X(int n,int m){
    if(n == m) return 0;
    if(n == 1) return m-1;
    if(m == 1) return n-1;
    if(dp[n][m] != -1) return dp[n][m];
    int ans = 1e9;
    for(int i{1};i<=m/2;i++){
        ans = min(ans,1+X(n,m-i)+X(n,i)); 
    }
    for(int i{1};i<=n/2;i++){
        ans = min(ans,1+X(n-i,m)+X(i,m)); 
    }
    return dp[n][m] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m; cin >> n >> m;
    memset(dp,-1,sizeof(dp));
    int ans = X(n,m);
    cout << ans << "\n";
    return 0;
}