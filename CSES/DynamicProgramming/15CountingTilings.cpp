#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll helper(ll n, ll m){
    if(n <= 0 || m <= 0) return 0;
    if(n == 1 && m == 2) return 1;
    if(n == 2 && m == 1) return 1;

    else return 2 + helper(n - 1, m - 2) + helper(n - 2, m - 1);

}

int main(){
    ll n, m;
    cin >> n >> m;
    cout << helper(n , m);
}

