#include <bits/stdc++.h>
#define PII pair<int,int>
#define ff first
#define ss second
using namespace std;
int main()
{
    int n,m; cin >> n >> m;
    vector<vector<int>> adj(n+1);

    for(int i{};i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    map<int,int> par;
    int ans = -1;
    queue<PII> q;
    vector<int> vis(n+1,0);
    q.push({1,0});
    vis[1] = 1;

    while(!q.empty()){
        PII f = q.front();
        q.pop();

        if(f.ff == n){
            ans = f.ss;
            break;
        }

        for(auto &j:adj[f.ff]){
            if(vis[j] == 0){
                par[j] = f.ff;
                vis[j] = 1;
                q.push({j,f.ss+1});
            }
        }
    }

    if(ans == -1){
        cout << "IMPOSSIBLE" << "\n";
    }else{
        int curr = n;
        vector<int> path;
        while(curr != 1){
            path.push_back(curr);
            curr = par[curr];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());

        cout << path.size() << "\n";
        for (auto &i:path){
            cout << i << " ";
        }cout << "\n";
    }
    return 0;
}