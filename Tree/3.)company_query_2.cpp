#include <bits/stdc++.h>
using namespace std;
vector<int> lvl;
vector<vector<int>> adj;
vector<vector<int>> jump;

void findLevelsofNode(int src, int level){
    lvl[src] = level;
    for(auto &j:adj[src]){
        findLevelsofNode(j,level+1);
    }
}

void binaryJumps(int src, int par){
    jump[src][0] = par;
    for(int i=1;i<20;i++){
        if(jump[src][i-1] != -1){
            int intermediateNode = jump[src][i-1];
            jump[src][i] = jump[intermediateNode][i-1];
        }else{
            jump[src][i] = -1;
        }
    }
    for(auto &j:adj[src]){
        binaryJumps(j,src);
    }
}

int LCB(int x, int y){
    if(lvl[x] > lvl[y]){
        swap(x,y);
    }
    int diff = lvl[y] - lvl[x];
    for(int i=19;i>=0;i--){
        if(diff >= (1 << i)){
            y = jump[y][i];
            diff -= (1 << i);
        }
    }

    if(x == y){
        return x;
    }

    for(int i=19;i>=0;i--){
        if(jump[x][i] != jump[y][i]){
            x = jump[x][i];
            y = jump[y][i];
        }
    }

    return jump[x][0];
}

int main()
{
    int n,q;
    cin >> n >> q;
    adj.assign(n+1,{});
    lvl.assign(n+1,0);
    jump.assign(n+1,vector<int>(20));
    for(int i=2;i<=n;i++){
        int boss;
        cin >> boss;
        adj[boss].push_back(i);
    }
    findLevelsofNode(1,0);
    binaryJumps(1,-1);
    while(q--){
        int x,y;
        cin >> x >> y;
        cout << LCB(x,y) << "\n";
    }
    return 0;
}