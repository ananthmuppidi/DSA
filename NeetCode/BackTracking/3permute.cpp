#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> permutation;
        dfs(nums, 0, ans);
        return ans;

    }

    void dfs(vector<int>& nums, int start, vector<vector<int>>& ans){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            swap(nums, start, i);
            dfs(nums, start + 1, ans);
            swap(nums, start, i);
        }
    }

    void swap(vector<int>& arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
};





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> nums = {'a', 'b', 'c', 'd'};
    auto ans = Solution().permute(nums);

    for(auto &i : ans){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
