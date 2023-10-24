#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int main()
{
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for(auto &temp:v) cin >> temp;
    vector<int> mp1(k+1),mp2(k+1);
    if(v[0] == 0){
        for(int i{1};i<=k;i++) mp1[i]++;
    }else{
        mp1[v[0]]++;
    }
    for(int i{1};i<n;i++){
        if(v[i] == 0){
            for(int j{1};j<=k;j++){
                if(mp1[j] >= 1){
                    if(j-1 >= 1)
                        mp2[j-1] = (mp2[j-1] + mp1[j]) % M;
                    mp2[j] = (mp2[j] + mp1[j]) % M;
                    if(j+1 <= k)
                        mp2[j+1] = (mp2[j+1] + mp1[j]) % M;
                }
            }
        }else{
            if(v[i]-1 >= 0)
                mp2[v[i]] = (mp2[v[i]] + mp1[v[i]-1]) % M;
            mp2[v[i]] = (mp2[v[i]] + mp1[v[i]]) % M;
            if(v[1]+1 <= k)
                mp2[v[i]] = (mp2[v[i]] + mp1[v[i]+1]) % M;
        }
        mp1 = mp2;
        fill(mp2.begin(),mp2.end(),0);
    }
    int ans{};
    for(int i{};i<=k;i++){
        ans = (ans + mp1[i]) % M;
    }
    cout << ans << "\n";
    return 0;
}