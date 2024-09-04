#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NINF = -1e18;

signed main()
{
    int n,m; cin >> n >> m;
    vector<vector<int>> adj;

    for(int i{};i<m;i++){
        vector<int> temp(3);
        cin >> temp[0] >> temp[1] >> temp[2];
        adj.push_back(temp);
    }

    // for(auto &j:adj){
    //     cout << j[0] << " " << j[1] << " " << j[2] << "\n";
    // }

    vector<int> dist(n+1,NINF);
    dist[1] = 0;

    for(int i{};i<n;i++){
        for(auto &j:adj){
            if(dist[j[0]] != NINF &&  dist[j[1]] < dist[j[0]] + j[2]){
                dist[j[1]] = dist[j[0]] + j[2];
            }
        }
    }
    int ans = dist[n];

    for(int i{};i<n;i++){
        for(auto &j:adj){
            if(dist[j[0]] != NINF && dist[j[1]] < dist[j[0]] + j[2]){
                dist[j[1]] = dist[j[0]] + j[2];
            }
        }
    }

    cout << (dist[n] > ans ? -1 : ans) << "\n";

    return 0;
}