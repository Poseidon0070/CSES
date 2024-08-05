#include <bits/stdc++.h>
#define PII pair<int,int>
#define ff first
#define ss second
#define int long long
using namespace std;

class Tri{
public:
    int src,des,cost;

    Tri(int a,int b,int c){
        this->src = a;
        this->des = b;
        this->cost = c;
    }
};

signed main()
{
    int n,m,q; cin >> n >> m >> q;
    vector<vector<int>> dist(n+1,vector<int>(n+1,-1));

    for(int i{};i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        if(dist[a][b] != -1){
            dist[a][b] = min(dist[a][b],c);
            dist[b][a] = min(dist[b][a],c);
        } 
        else{
            dist[a][b] = c;
            dist[b][a] = c;
        }
    }

    for(int i{1};i<=n;i++){
        for(int j{1};j<=n;j++){
            dist[j][j] = 0;
            for(int k{1};k<=n;k++){
                if(dist[j][k] != -1 && dist[j][i] != -1 && dist[i][k] != -1 && dist[j][k] > dist[j][i]+dist[i][k]){
                    dist[j][k] = dist[j][i]+dist[i][k];
                }else if(dist[j][k] == -1 && dist[j][i] != -1 && dist[i][k] != -1){
                    dist[j][k] = dist[j][i]+dist[i][k];
                }
            }
        }
    }

    while(q--){
        int a,b; cin >> a >> b;
        cout << dist[a][b] << "\n";
    }
    return 0;
}

vector<vector<int>> adj = {
    {8},
    {2,4},
    {1,3,5},
    {2,6},
    {1,5,7},
    {2,4,6,8},
    {3,5,9},
    {4,8},
    {0,5,7,9},
    {6,8}
}