// DFS

// #include <bits/stdc++.h>
// typedef long long ll;
// #define vi     vector <int>
// #define vll    vector <long long>
// #define vs     vector <string>
// #define vc     vector <char>
// #define PII    pair<int,int>
// #define MII    map<int,int>
// #define UMII   unordered_map<int,int>
// #define sz(v)  (int)v.size()
// #define all(v) v.begin(),v.end()
// #define ff     first 
// #define ss     second 
// #define int    long long
// #define endl   "\n"
// #define TxtIO  freopen("input.txt","r",stdin); \
//                freopen("output.txt","w",stdout);
// using namespace std;
// const int  M  = 1e9+7;
// const int  N  = 1e5+7;

// vector<pair<int,int>> mov = {{0,1},{1,0},{0,-1},{-1,0}};

// void X(int i,int j,int n,int m,vector<vector<int>> &vis,vector<string> &v){
//     vis[i][j] = 1;
//     for(int k{};k<4;k++){
//         int nr = i+mov[k].first;
//         int nc = j+mov[k].second;
//         if(nr >= 0 && nc >= 0 && nr < n && nc < m && vis[nr][nc] == 0 && v[nr][nc] == '.'){
//             X(nr,nc,n,m,vis,v);
//         }
//     }
// }

// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     int n,m; cin >> n >> m;
//     vector<string> v;
//     for(int i{};i<n;i++){
//         string s; cin >> s;
//         v.push_back(s);
//     }

//     vector<vector<int>> vis(n,vector<int>(m,0));

//     int cnt{};
//     for(int i{};i<n;i++){
//         for(int j{};j<m;j++){
//             if(v[i][j] == '.' && vis[i][j] == 0){
//                 cnt++;
//                 X(i,j,n,m,vis,v);
//             }
//         }
//     }

//     cout << cnt << "\n";
//     return 0;
// }

// BFS

// #include <bits/stdc++.h>
// typedef long long ll;
// #define vi     vector <int>
// #define vll    vector <long long>
// #define vs     vector <string>
// #define vc     vector <char>
// #define PII    pair<int,int>
// #define MII    map<int,int>
// #define UMII   unordered_map<int,int>
// #define sz(v)  (int)v.size()
// #define all(v) v.begin(),v.end()
// #define ff     first 
// #define ss     second 
// #define int    long long
// #define endl   "\n"
// #define TxtIO  freopen("input.txt","r",stdin); \
//                freopen("output.txt","w",stdout);
// using namespace std;
// const int  M  = 1e9+7;
// const int  N  = 1e5+7;
// vector<pair<int,int>> mov = {{0,1},{1,0},{0,-1},{-1,0}};
// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n,m; cin >> n >> m;
//     vector<string> v;
//     for(int i{};i<n;i++){
//         string s; cin >> s;
//         v.push_back(s);
//     }
//     vector<vector<int>> vis(n,vector<int>(m,0));
//     int ans{};
//     for(int i{};i<n;i++){
//         for(int j{};j<m;j++){
//             if(vis[i][j] == 0 && v[i][j] == '.'){
//                 ans++;
//                 queue<PII> q;
//                 q.push({i,j});
//                 while(!q.empty()){
//                     PII f = q.front();
//                     q.pop();
//                     if(vis[f.ff][f.ss] == 1) continue;
//                     vis[f.ff][f.ss] = 1;
//                     for(int k{};k<4;k++){
//                         int nr = f.ff+mov[k].ff;
//                         int nc = f.ss+mov[k].ss;
//                         if(nr < n && nc < m && nr >= 0 && nc >= 0 && vis[nr][nc] == 0 && v[nr][nc] == '.'){
//                             q.push({nr,nc});
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     cout << ans << "\n";
//     return 0;
// }
