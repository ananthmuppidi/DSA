#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        for(auto str : strs){
            vector<int> signature(26, 0); // length, base value
            for(auto &j : str) signature[j - '0']++;
            cout << generateKey(signature) << endl;
            
        }
        
    }

    string generateKey(vector<int> arr){
        string res = "";
        for(int i = 0; i < arr.size(); i++){
            res.append(string(arr[i], 1));
        }
    }
};

int main() {

    Solution solver;
    
    
}