#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> subset;

        dfs(nums, subset, 0, ans);
        return ans;
    }

    void dfs(vector<int>& nums, vector<int>& subset, int curr, vector<vector<int>>& ans){
        if(curr >= nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[curr]);
        dfs(nums, subset, curr + 1, ans);

        subset.pop_back();
        dfs(nums, subset, curr + 1, ans);

        // subset remains unchanged because i pushed once and popped once
        return;
    }   

};




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> arr = {1,2,3,4};
    auto ans = Solution().subsets(arr);

    for(auto &i : ans){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }

}
