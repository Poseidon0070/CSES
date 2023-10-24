#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main()
{
    int n; cin >> n;
    vector<string> v;
    for(int i{};i<n;i++){
        string s; cin >> s;
        v.push_back(s);
    }
    if(v[0][0] == '*'){
        cout << 0 << "\n";
        return 0;
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    dp[1][1] = 1;
    for(int i{1};i<=n;i++){
        for(int j{1};j<=n;j++){
            if(i == 1 && j == 1) continue;
            if(v[i-1][j-1] == '.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % M;
            }
        }
    }
    cout << dp[n][n] << "\n";
    return 0;
}