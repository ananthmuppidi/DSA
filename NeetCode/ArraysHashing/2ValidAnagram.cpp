#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map, t_map;
        for(auto &i : s) s_map[i]++;
        for(auto &i : t) t_map[i]++;
        for(auto &c : s_map)
            if (t_map[c.first] != s_map[c.first]) return false;
        for(auto &c : t_map)
            if (s_map[c.first] != t_map[c.first]) return false;
        return true;
    }
};

int main(){
    Solution solver;
    cout << solver.isAnagram("nagaram", "car") << endl;
}