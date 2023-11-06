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
    int n,m; cin >> n >> m;
    vector<vector<Tri>> adj(n+1);

    for(int i{};i<m;i++){
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back(Tri(a,b,c));
    }

    priority_queue<PII,vector<PII>,greater<PII>> pq;
    vector<int> vis(n+1,0);
    unordered_map<int,int> cost; 
    pq.push({0,1});

    while(!pq.empty()){
        PII f = pq.top();
        pq.pop();

        if(vis[f.ss] == 1) continue;
        vis[f.ss] = 1;
        cost[f.ss] = f.ff;

        for(auto &j:adj[f.ss]) {
            pq.push({f.ff+j.cost,j.des});
        }
    }

    for(int i{1};i<=n;i++){
        cout << cost[i] << " ";
    }cout << "\n";

    return 0;
}