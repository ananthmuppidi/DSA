#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
#define FOR(N) for(long long i = 0; i < N: i++)
const ll md = 1000000007;

ll helper(vector<ll>& coins, ll amount, vector<ll>& dp){
    if(amount < 0) return 0;
    if(amount == 0) return 1;
    if( dp[amount] != -1) return dp[amount];

    ll ans = 0;

    
    for(auto &coin : coins){
        ans  = (ans +  helper(coins, amount - coin, dp)) % md;
    }
    dp[amount] = ans;
    return ans;
}


int main() {
    ll n, amount;
    cin >> n >> amount;

    vector<ll> dp(amount + 1, -1);
    vector<ll> coins(n);
    // sort(coins.begin(), coins.end());
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << helper(coins, amount, dp);

}


