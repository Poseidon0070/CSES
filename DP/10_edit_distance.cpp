// Memoization

// #include <bits/stdc++.h>
// using namespace std;
// int X(string &s1,string &s2,int n,int m,vector<vector<int>> &dp){
//     if(n == 0) return m;
//     if(m == 0) return n;
//     if(dp[n][m] != -1) return dp[n][m];
//     if(s1[n-1] == s2[m-1]){
//         return dp[n][m] = X(s1,s2,n-1,m-1,dp);
//     }else{
//         return dp[n][m] = 1 + min({X(s1,s2,n-1,m-1,dp),X(s1,s2,n-1,m,dp),X(s1,s2,n,m-1,dp)});
//     }
// }
// int main()
// {
//     string s1,s2;
//     cin >> s1 >> s2;
//     int n = s1.size();
//     int m = s2.size();
//     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//     int ans = X(s1,s2,n,m,dp);
//     cout << ans << "\n";
//     return 0;
// }

