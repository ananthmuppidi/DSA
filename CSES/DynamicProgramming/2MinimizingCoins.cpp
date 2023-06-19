#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define md 1000000007

ll helper(ll target, vector<ll> coins, map<ll, ll> dp){
    if(target < 0) return -1;
    if(target == 0) return 0;
    if(dp.find(target) != dp.end()){
        return dp.find(target)->second;
    }
    ll ans = LLONG_MAX;
    for(ll coin : coins){
        ll temp = helper(target - coin, coins, dp);
        if(temp != -1){
            ans = min(ans, (temp + 1) % md);
        }
    }   
    dp.insert({target, ans});
    return ans;
}

int main(){

    int n, target;
    cin >> n >> target;
    vector<ll> coins(n, 0);
    map<ll, ll> dp;
    for(ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        coins[i] = temp;
    }
    cout << helper(target, coins, dp) << endl;

}