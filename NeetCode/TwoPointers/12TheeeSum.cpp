#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());


        int prev = 0;
        int i = 0;
        while(i < nums.size()){
            if(i != 0){
                if(nums[i] == prev){
                    i++;
                    continue;
                }
            }
            prev = nums[i];
            vector<vector<int>> temp = helper(nums, i + 1, -nums[i]);
            for(auto vec : temp){
                vec.insert(vec.begin(), nums[i]);
                ans.push_back(vec);
            }
            i++;
        }
        return ans;
    }

    vector<vector<int>> helper(vector<int>& nums, int start, int target){
        // returns all pairs that add upto target, starting from start till the last element
        vector<vector<int>> ans;
        int s = start, e = nums.size() - 1;
        while(s < e){
            if(nums[s] + nums[e] == target){
                vector<int> temp;
                temp.push_back(nums[s]);
                temp.push_back(nums[e]);
                ans.push_back(temp);

                s++;
                while(nums[s] == nums[s - 1]){
                    s++;
                }
                e--;
                while(nums[e + 1] == nums[e]){
                    e--;
                }

            } else if(nums[s] + nums[e] < target) {
                s++;
            } else {
                e--;
            }
        }
        return ans;
    }
};


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  vector<int> nums = {-1,0,1,2,-1,-4};
  auto i = Solution().threeSum(nums);
  for(auto &j : i){
    for(auto &nums : j){
        cout << nums << " ";
    }
    cout << endl;
  }

  return 0;
}
