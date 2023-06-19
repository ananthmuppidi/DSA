#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // handle arrsize = 1
        vector<int> right(nums.size());
        vector<int> left(nums.size());

        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                right[0] = nums[0];
            } else {
                right[i] = right[i - 1] * nums[i];
            }
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            if(i == nums.size() - 1){
                left[nums.size() - 1] = nums[nums.size() - 1];
            } else {
                left[i] = left[i + 1] * nums[i];
            }
        }

        // preprocessed the left and the right arrays, now handle the edge cases
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            if(i == 0) ans[i] = left[i + 1];
            else if(i == nums.size() - 1) ans[i] = right[i - 1];
            else ans[i] = right[i - 1] * left[i + 1];
        }

        return ans;

    }
};  


int main(){
    Solution solver;
    vector<int> nums = {-1,1,0,-3,3};
    auto ans = solver.productExceptSelf(nums);
    for(auto i : ans){
        cout << i << " ";
    }
    cout << endl;

}