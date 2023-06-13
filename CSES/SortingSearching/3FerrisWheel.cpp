#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    int s = 0, e = arr.size() - 1;
    int ans = 0;
    while(s <= e){
        if(arr[s] + arr[e] <= x) { 
            s++;
            e--;
        } else {
            e--;
        }
        ans++;
    }
    cout << ans << endl;
}