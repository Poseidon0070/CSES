#include <bits/stdc++.h>
using namespace std;
#define int long long

class Tri{
public:
    int st,end,rew;
    Tri(int a,int b,int c){
        this->st = a;
        this->end = b;
        this->rew = c;
    }
};

bool X(Tri &a, Tri &b){
    if(a.end == b.end){
        return a.st < b.st;
    }
    return a.end < b.end;
};

int findInd(int st,int n,vector<Tri> &v){
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high){
        int mid = (low+high) >> 1; 
        if(v[mid].end < st){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return ans;
}

signed main()
{
    int n; cin >> n;
    vector<Tri> v;
    for(int i{};i<n;i++){
        int a,b,c; cin >> a >> b >> c;
        v.push_back(Tri(a,b,c));
    } 
    sort(v.begin(),v.end(),X);
    vector<int> dp(n+1);
    for(int i{};i<n;i++){
        auto it = findInd(v[i].st,n,v);
        if(it == -1){
            if(i == 0)
                dp[i] = v[i].rew;
            else
                dp[i] = max(dp[i-1], v[i].rew);
        }else{
            dp[i] = max(dp[i-1], v[i].rew + dp[it]);
        }
    }
    cout << *max_element(dp.begin(),dp.end()) << "\n";
    return 0;
}

// https://www.linkedin.com/posts/ashishps1_15-leetcode-articles-i-wish-id-read-sooner-activity-7122801650494279682-XWtO?utm_source=share&utm_medium=member_desktop