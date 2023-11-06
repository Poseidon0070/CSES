#include <bits/stdc++.h>
#define PII pair<int,int>
#define ff first
#define ss second
using namespace std;

vector<pair<int,int>> mov = {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    int n,m; cin >> n >> m;
    vector<string> v;
    PII st,end;

    for(int i{};i<n;i++){
        string s; cin >> s;
        for(int j{};j<m;j++){
            if(s[j] == 'A') st = {i,j};
            if(s[j] == 'B') end = {i,j};
        }
        v.push_back(s);
    }
    
    map<PII,PII> parent;
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<PII> q;
    q.push(st);
    vis[st.ff][st.ss] = 1;
    bool flg = 0;

    while(!q.empty()){
        PII f = q.front();
        q.pop();

        if(f == end){
            flg = 1;
            break;
        }

        for(int k{};k<4;k++){
            int nr = f.ff + mov[k].ff;
            int nc = f.ss + mov[k].ss;

            if(nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0 && v[nr][nc] != '#'){
                parent[{nr,nc}] = f;
                vis[nr][nc] = 1;
                q.push({nr,nc});
            }
        }
    }

    if(!flg){
        cout << "NO" << "\n";
        return 0;
    }

    string ans;
    while(end != st){
        PII temp = parent[end];
        if(temp.ss == end.ss){
            if(temp.ff > end.ff) ans += 'U';
            else ans += 'D';
        }else{
            if(temp.ss > end.ss) ans += 'L';
            else ans += 'R';
        }
        end = temp;
    }

    reverse(ans.begin(),ans.end());
    cout << "YES" << "\n";
    cout << ans.size() << "\n";
    cout << ans << "\n";

    return 0;
}