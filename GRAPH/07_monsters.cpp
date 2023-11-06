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
    vector<PII> monsters;
    vector<vector<int>> per_vis(n,vector<int>(m,0));
    vector<vector<int>> mon_vis(n,vector<int>(m,0));
    bool flg = 0;
    queue<PII> person;
    queue<PII> monster;
    map<PII,PII> par;

    for(int i{};i<n;i++){
        string s; cin >> s;
        for(int j{};j<m;j++){
            if(s[j] == 'A') {
                st = {i,j};
                per_vis[i][j] = 1;
                person.push({i,j});
            }
            if(s[j] == 'M') {
                mon_vis[i][j] = 1;
                monster.push({i,j});
            }
        }
        v.push_back(s);
    }


    while(!person.empty()){

        int mon_sz = monster.size();
        for(int i{};i<mon_sz;i++){
            PII fm = monster.front();
            monster.pop();

            for(int k{};k<4;k++){
                int nr = fm.ff + mov[k].ff;
                int nc = fm.ss + mov[k].ss;
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && mon_vis[nr][nc] == 0 && v[nr][nc] != '#') {
                    mon_vis[nr][nc] = 1;
                    monster.push({nr,nc});
                }
            }
        }

        int per_sz = person.size();
        for(int i{};i<per_sz;i++){
            PII fp = person.front();
            person.pop();

            if(fp.ff == 0 || fp.ff == n-1 || fp.ss == 0 || fp.ss == m-1){
                flg = 1;
                end = {fp.ff,fp.ss};
                break;
            }

            for(int k{};k<4;k++){
                int nr = fp.ff + mov[k].ff;
                int nc = fp.ss + mov[k].ss;
                if(nr >= 0 && nc >= 0 && nr < n && nc < m && mon_vis[nr][nc] == 0 && per_vis[nr][nc] == 0 && v[nr][nc] != '#') {
                    par[{nr,nc}] = fp;
                    per_vis[nr][nc] = 1;
                    person.push({nr,nc});
                }
            }
        }
    }

    if(flg){
        string ans;
        while(end != st){
            PII temp = par[end];
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
    }else{
        cout << "NO" << "\n";
    }
    return 0;
}