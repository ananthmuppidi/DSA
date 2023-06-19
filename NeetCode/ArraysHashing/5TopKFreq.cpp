#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int &i : nums){
            map[i]++;
        }
        vector<vector<int>> reverseArr(nums.size() + 1);
        for(auto i : map){
            reverseArr[i.second].push_back(i.first);
        }
        vector<int> ans;
        int idx = reverseArr.size() - 1;
        while(ans.size() != k){
            if(reverseArr[idx].size() == 0){
                idx--;
            } else {
                ans.push_back(reverseArr[idx].back());
                reverseArr[idx].pop_back();
            }
        }
        return ans;
    }

    

    
};

int main(){

}