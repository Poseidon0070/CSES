#include <bits/stdc++.h>
using namespace std;
bool flg = 0;
set<int> st;
vector<int> path;

void X(int s,int par,vector<int> &vis,vector<vector<int>> &adj){
    if(flg) return ;
    st.insert(s);
    path.push_back(s);
    vis[s] = 1;

    for(auto &j:adj[s]){

        if(j != par && st.count(j)){
            vector<int> temp;
            temp.push_back(j);
            int i = path.size()-1;
            while(path[i] != j){
                temp.push_back(path[i]);
                i--;
            }
            temp.push_back(j);
            cout << temp.size() << "\n";
            for (auto &k:temp){
                cout << k << " ";
            }cout << "\n";
            flg = 1;
            break;
        }

        if(vis[j] == 0){
            X(j,s,vis,adj);
        }
    }

    st.erase(s);
    path.pop_back();
}


int main()
{
    int n,m; cin >> n >> m;
    flg = 0;
    st.clear();
    path.clear();
    vector<vector<int>> adj(n+1);

    for(int i{};i<m;i++){
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n+1,0);
    
    for(int i{1};i<=n;i++){
        if(vis[i] == 0 && !flg){
            st.clear();
            path.clear();
            X(i,-1,vis,adj);
        }
    }

    if(!flg){
        cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}