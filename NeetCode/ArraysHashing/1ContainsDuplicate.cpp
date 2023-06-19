#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &i : nums) {
            auto temp =  set.insert(i);
            if(!temp.second) return true;
        }
        return false;
    }
};

int main(){
    Solution solver;
    vector<int> vec{1,2,3,3};
    cout << solver.containsDuplicate(vec) << endl;

}

