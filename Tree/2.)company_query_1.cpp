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

int anc[200005][20];

void X(int src, int par, vector<vector<int>> &adj){
    anc[src][0] = par;
    for(int i{1};i<20;i++){
        if(anc[src][i-1] != -1){
            anc[src][i] = anc[anc[src][i-1]][i-1];
        }else{
            anc[src][i] = -1;
        }
    }
    for(auto &j:adj[src]){
        X(j, src, adj);
    }
}

int binary_lift(int x,int y){
    if(x == -1 || y == 0){
        return x;
    }
    for(int i{19};i>=0;i--){
        if(y >= (1 << i)){
            return binary_lift(anc[x][i],y-(1<<i));
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    vector<vector<int>> adj(n+1);
    for(int i{2};i<=n;i++){
        int x; cin >> x;
        adj[x].push_back(i);
    }
    X(1,-1,adj);
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << binary_lift(x,y) << "\n";
    }
    return 0;
}