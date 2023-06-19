#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define md 1000000007

int main(){
    ll n;
    cin >> n;

    vector<ll> dp(n + 1 ,0);
    dp[0] = 0;
    dp[1] = 1;
    for(ll i = 2; i <= n; i++ ){
        if(i <= 6) dp[i]++;
        for(ll j = 1; j <= 6; j++){
            if(i - j > 0) dp[i] = (dp[i] + dp[i - j]) % md;
        }
    }
    cout << dp[n];

}
