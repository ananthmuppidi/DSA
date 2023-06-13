#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums); 
        int size = nums.size();
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);
        else {
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            for(int i = 2; i < size; i++){
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
            }
        }
        return dp[size - 1];
    }
};

int main(){
    Solution solver;
    vector<int> nums{1,2,3,1};
    cout << solver.rob(nums) << endl;
    return 0;
}