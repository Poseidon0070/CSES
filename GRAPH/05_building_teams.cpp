#include <bits/stdc++.h>
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

    bool flg = 1;
    queue<int> q;
    vector<int> team(n+1,0);
    vector<int> vis(n+1,0);

    for(int k{1};k<=n;k++){

        if(vis[k] == 1) continue;
        q.push(k);
        vis[k] = 1;
        team[k] = 1;
        int currTeam = 2;

        while(!q.empty()){
            
            int sz = q.size();

            for(int i{};i<sz;i++){
                int f = q.front();
                q.pop();
                for(auto &j:adj[f]){
                    // cout << currTeam << "\n";
                    if(vis[j] == 1){
                        if(team[j] != currTeam){
                            // cout << f << " " << j << " " << currTeam << "\n";
                            flg = 0;
                        }
                    }
                    if(vis[j] == 0){
                        q.push(j);
                        vis[j] = 1;
                        team[j] = currTeam;
                    }
                }
            }

            currTeam == 2 ? currTeam = 1 : currTeam = 2;
        }
    }

    if(!flg){
        cout << "IMPOSSIBLE" << "\n";
    }
    else{

        for(int i{1};i<=n;i++){
            cout << team[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}