// DSU 

// #include <bits/stdc++.h>
// using namespace std;
// int find(int x,vector<int> &par){
//     if(par[x] == x) return x;
//     par[x] = find(par[x],par);
//     return par[x];  
// }
// void merge(int a,int b,vector<int> &par,vector<int> &rank) {
//     int rep_a = find(a,par);
//     int rep_b = find(b,par);
//     if(rep_a == rep_b) return;
//     if(rank[rep_a] > rank[rep_b]) par[rep_b] = rep_a; 
//     if(rank[rep_a] < rank[rep_b]) par[rep_a] = rep_b;
//     else{
//         par[rep_b] = rep_a; 
//         rank[rep_a]++;
//     }
// }
// bool isConnected(int x,int y,vector<int> &par,vector<int> &rank){
//     if(find(x,par) == find(y,par)) return 1;
//     return 0;
// }
// int main()
// {
//     int n,m; cin >> n >> m;

//     vector<int> par(n+1);
//     vector<int> rank(n+1);

//     for(int i{1};i<=n;i++){
//         par[i] = i;
//         rank[i] = 1;
//     }

//     for(int i{};i<m;i++){
//         int a,b; cin >> a >> b;
//         merge(a,b,par,rank);
//     }

//     set<int> st;
//     for(int i{1};i<=n;i++) st.insert(find(i,par));
//     cout << st.size()-1 << "\n";
//     for(auto it = st.begin(); it != st.end(); it++) {
//         if(it == st.begin()) continue;
//         cout << *st.begin() << " " << *it << "\n"; 
//     }
//     return 0;
// }


//BFS

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
// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     int n,m; cin >> n >> m;
//     vector<int> v;
//     vector<vector<int>> adj(n+1);
//     vector<int> vis(n+1,0);
//     for(int i{};i<m;i++){
//         int a,b; cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     for(int i{1};i<=n;i++){
//         if(vis[i] == 0){
//             v.push_back(i);
//             queue<int> q;
//             q.push(i);
//             while(!q.empty()){
//                 int f = q.front();
//                 q.pop();
//                 if(vis[f] == 1) continue;
//                 vis[f] = 1;
//                 for(auto &j:adj[f]){
//                     if(vis[j] == 0){
//                         q.push(j);
//                     }
//                 }
//             }
//         }
//     }
//     cout << v.size()-1 << "\n";
//     for(int i{1};i<v.size();i++) cout << v[i-1] << " " << v[i] << "\n";
//     return 0;
// }
