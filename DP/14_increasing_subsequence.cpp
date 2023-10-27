// Binary Search

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n; cin >> n;
//     vector<int> v(n);
//     for(auto &temp:v) cin >> temp;
//     vector<int> lis;
//     for(int i{};i<n;i++){
//         auto it = lower_bound(lis.begin(),lis.end(),v[i]);
//         if(it == lis.end()){
//             lis.push_back(v[i]);
//         }else{
//             *it = v[i];
//         }
//     }
//     cout << lis.size() << "\n";
//     return 0;
// }

// DP

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &temp:v) cin >> temp;
    vector<int> dp(n);
    for(int i{};i<n;i++){
        dp[i] = 1;
        for(int j{};j<i;j++){
            if(v[j] < v[i]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
    cout << *max_element(dp.begin(),dp.end()) << "\n";
    return 0;
}