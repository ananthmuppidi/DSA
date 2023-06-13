#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &i : nums) {
            // pair<unordered_set<int>::iterator, bool>  temp =  set.insert(i);
            if(set.insert(i).second) return true;
            // if(!temp.second) return true;
        }
        return false;
    }
};

int main(){
    Solution solver;
    vector<int> vec{1,2,3,3};
    cout << solver.containsDuplicate(vec) << endl;

}

