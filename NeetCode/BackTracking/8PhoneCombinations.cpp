#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(digits, 0, curr, ans, pad);
        return ans;
    }

    void dfs(string& digits, int index, vector<string>& curr, vector<vector<string>>& ans, vector<string>& pad){
        if(index == digits.size()){
            vector<string> temp(curr);
            ans.push_back(temp);
            return;
        }
        for(auto &c : pad[digits[index]] - '0'){
            curr.push_back(c);
            dfs(digits, index + 1, curr, ans, pad);
            curr.pop_back();
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    auto ans = Solution().
}
