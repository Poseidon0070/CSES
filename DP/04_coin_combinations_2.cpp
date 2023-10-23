// Tabulation

// #include <bits/stdc++.h>
// using namespace std;
// const int M = 1e9+7;
// int main()
// {
//     int n,s; cin >> n >> s;
//     vector<int> coins(n);
//     for(auto &temp:coins) cin >> temp;
//     vector<int> dp(s+1);
//     dp[0] = 1;
//     for(int i{};i<n;i++){
//         for(int j{1};j<=s;j++){
//             if(j >= coins[i]){
//                 dp[j] = (dp[j] + dp[j-coins[i]]) % M;
//             }
//         }
//     }
//     cout << dp[s] << "\n";
//     return 0;
// }

// Memoization

#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int X(int i,int n,int s,vector<int> &coins,vector<vector<int>> &dp){
    if(s == 0) {
        return 1;
    }
    if(i == n) {
        return 0;
    }
    if(dp[i][s] != -1) return dp[i][s];
    if(coins[i] <= s){
        return dp[i][s] = X(i+1,n,s,coins,dp) + X(i,n,s-coins[i],coins,dp);
    }else{
        return dp[i][s] = X(i+1,n,s,coins,dp);
    }
}
int main()
{
    int n,s; cin >> n >> s;
    vector<int> coins(n);
    for(auto &temp:coins) cin >> temp;
    vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
    int ans = X(0,n,s,coins,dp);
    cout << ans << "\n";
    return 0;
}