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
//     for(int i{1};i<=s;i++){
//         for(int j{};j<n;j++){
//             if(i-coins[j] >= 0){
//                 dp[i] = (dp[i] + dp[i-coins[j]]) % M;
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
int X(int n,int s,vector<int> &coins,vector<int> &dp){
    if(s == 0) return 1;
    if(dp[s] != -1) return dp[s];
    int ans = 0;
    for(int i{};i<n;i++){
        if(s >= coins[i]){
            ans = (ans + X(n,s-coins[i],coins,dp)) % M;
        }
    }
    return dp[s] = ans;
}
int main()
{
    int n,s; cin >> n >> s;
    vector<int> coins(n);
    for(auto &temp:coins) cin >> temp;
    vector<int> dp(s+1,-1);
    int ans = X(n,s,coins,dp);
    cout << ans << "\n";
    return 0;
}