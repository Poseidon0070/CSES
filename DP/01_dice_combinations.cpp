// Tabulation

// #include <bits/stdc++.h>
// using namespace std;
// const int M = 1e9+7;
// int main()
// {
//     int n; cin >> n;
//     vector<int> dp(n+1);
//     dp[0] = 1;
//     for(int i{1};i<=n;i++){
//         if(i <= 6){
//             for(int j{1};j<=i;j++){
//                 dp[i] = (dp[i]+dp[i-j])%M;
//             }
//         }else{
//             for(int j{1};j<=6;j++){
//                 dp[i] = (dp[i]+dp[i-j])%M;
//             }
//         }
//     }
//     cout << dp[n] << "\n";
//     return 0;
// }

// Memoization

// #include <bits/stdc++.h>
// using namespace std;
// const int M = 1e9+7;
// int X(int n,vector<int> &dp){
//     if(n == 0) return 1;
//     if(n < 0) return 0;
//     if(dp[n] != -1) return dp[n];
//     int ans = 0;
//     for(int i{1};i<=6;i++){
//         ans = (ans + X(n-i,dp)) % M;
//     }
//     return dp[n] = ans;
// }
// int main()
// {
//     int n; cin >> n;
//     vector<int> dp(n+1,-1);
//     int ans = X(n,dp);
//     cout << ans << "\n";
//     return 0;
// }

