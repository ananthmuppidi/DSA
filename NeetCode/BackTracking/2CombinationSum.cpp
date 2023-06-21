#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        unordered_set<int> set;
        for(auto &i : candidates){
            set.insert(i);
        }

        vector<int> cleaned;

        for(auto &i : set){
            cleaned.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> subset;
        dfs(cleaned, subset, target, ans, 0);
        return ans;
        
    }

    void dfs(vector<int>& canidates, vector<int>& subset, int target, vector<vector<int>>& ans, int processed){
        if(target < 0) return;
        if(target == 0) {
            ans.push_back(subset);
            return;
        }
        for(int i = processed; i < canidates.size(); i++){
            subset.push_back(canidates[i]);
            dfs(canidates, subset, target - canidates[i], ans, i);
            subset.pop_back();
        }
    }
};




int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<int> candidates = {2,3,5};
    auto ans = Solution().combinationSum(candidates, 8);
    for(auto i : ans){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}
