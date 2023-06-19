#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for(auto &str : strs){
            map[generateKey(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto i : map){
            vector<string> temp;
            for(auto j: i.second){
                temp.push_back(j);
            }
            ans.push_back(temp);
        }

        return ans;
    
    }

    string generateKey(string s){
        vector<int> arr(26, 0);
        for(auto c : s){
            // cout << c - '0' << endl;
            arr[c - 'a']++;
        }
        string res = "";
        for(auto c : arr){
            res = res + to_string(c) + ".";
        }
        return res;
    }
    
};

int main() {

    Solution solver;
    vector<string> strs;
    strs.push_back("abs");
    solver.groupAnagrams(strs);
    
    
}