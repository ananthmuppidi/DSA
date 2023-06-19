#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> set;
        for(auto &i : nums) set.insert(i);

        int maxLength = 1;

        for(auto &i : nums){
            
            if(set.find(i - 1) == set.end()){ // potential start element found
                int curr = i;
                int currLength = 1;
                while(set.find(curr + 1) != set.end()){
                    currLength++;
                    curr++;
                }
                maxLength = max(maxLength, currLength);
            }
        }
        return maxLength;
    }
};

int main(){
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << Solution().longestConsecutive(nums) << endl;

}