#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int a = 0, b = 0;
        int ans = 0;
        while(b < prices.size()){
            if(prices[b] < prices[a]) {
                a = b;
            } else {
                ans = max(ans, max(0,(prices[b] - prices[a])));
            }
            b++;
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> prices = {7,1,5,3,6,4};
    cout << Solution().maxProfit(prices) << endl;

}
