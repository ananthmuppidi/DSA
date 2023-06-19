#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0, e = numbers.size() - 1;
        while(numbers[s] + numbers[e] != target){
            if(numbers[s] + numbers[e] < target){
                s = s + 1;
            } else {
                e = e - 1;
            }
        }
        vector<int> ans;
        ans.push_back(s + 1);
        ans.push_back(e + 1);
        return ans;
    }
};

int main(){
    vector<int> nums = {-1,0};
    auto ans = Solution().twoSum(nums, -1);
    for(auto&i : ans) cout << i << " ";
    cout << endl;
}