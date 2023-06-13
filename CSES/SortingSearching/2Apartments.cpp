#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants;
    vector<int> apartments;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        applicants.push_back(temp);
    }

    for(int j = 0; j < m; j++){
        int temp;
        cin >> temp;
        apartments.push_back(temp);
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());
    

    int i = 0, j = 0;
    int ans = 0;
    while(i < n && j < m){
        if(abs(applicants[i] - apartments[j]) <= k){
            ans++;            
            i++;
            j++;
        } else {
            if(applicants[i] < apartments[j]) i++;
            else j++;
        }

    }

    cout << ans << endl;
    return 0;

}