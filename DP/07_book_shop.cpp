#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k; cin >> n >> k;
    vector<int> price(n);
    vector<int> pages(n);
    for(auto &temp:price) cin >> temp;
    for(auto &temp:pages) cin >> temp;
    vector<int> dp(k+1);
    for(int i{1};i<=n;i++){
        for(int j{k};j>=0;j--){
            if(j >= price[i-1]){
                dp[j] = max(dp[j], pages[i-1]+dp[j-price[i-1]]);
            }
        }
    }
    cout << dp[k] << "\n";
    return 0;
}