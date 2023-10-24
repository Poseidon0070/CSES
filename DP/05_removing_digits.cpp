// Tabulation
#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[0] = 0;
    for(int i{1};i<=n;i++){
        string z = to_string(i);
        dp[i] = 1e9;
        for(int j{};j<z.size();j++){
            if(dp[i-(z[j]-'0')] != 1e9){
                dp[i] = min(dp[i], 1+dp[i-(z[j]-'0')]);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}