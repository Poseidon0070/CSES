#include <bits/stdc++.h>
typedef long long ll;
#define vi     vector <int>
#define vll    vector <long long>
#define vs     vector <string>
#define vc     vector <char>
#define PII    pair<int,int>
#define MII    map<int,int>
#define UMII   unordered_map<int,int>
#define sz(v)  (int)v.size()
#define all(v) v.begin(),v.end()
#define ff     first 
#define ss     second 
#define int    long long
#define endl   "\n"
#define TxtIO  freopen("input.txt","r",stdin); \
               freopen("output.txt","w",stdout);
using namespace std;
const int  M  = 1e9+7;
const int  N  = 1e5+7;
int X(int src, vector<vector<int>> &adj, vector<int> &ans){
    int sub = 0;
    for(auto &j:adj[src]){
        sub += X(j,adj,ans);
    }
    ans[src] = sub;
    return 1 + ans[src];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<vector<int>> adj(n+1);
    for(int i{2};i<=n;i++){
        int x; cin >> x;
        adj[x].push_back(i);
    }
    vector<int> ans(n+1);
    int x = X(1,adj,ans);
    for(int i{1};i<=n;i++){
        cout << ans[i] << " ";
    }
    return 0;
}