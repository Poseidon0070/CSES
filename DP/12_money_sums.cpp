#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &temp:v) cin >> temp;
    vector<bool> v1(1e5+5),v2(1e5+5);
    v1[0] = 1;
    sort(v.begin(),v.end());
    for(int i{};i<n;i++){
        for(int j{};j<=1e5;j++){
            if(v1[j] == 1) v2[j] = 1;
            if(j >= v[i] && v1[j-v[i]] == 1){
                v2[j] = 1;
            }
        }
        v1 = v2;
        fill(v2.begin(),v2.end(),0);
    }
    int cnt{};
    vector<int> ans;
    for(int i{1};i<=1e5;i++){
        if(v1[i] == 1){
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt << "\n";
    for (auto &i:ans){
        cout << i << " ";
    }cout << "\n";
    return 0;
}