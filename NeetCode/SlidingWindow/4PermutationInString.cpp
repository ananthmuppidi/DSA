#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()){
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(auto &i : s1){
            freq1[i - 'a']++;
        }
        int a = 0, b = 0;
        for(; b < s1.size(); b++){
            freq2[s2[b] - 'a']++;
        }
        while(b < s2.size()){
            if(cmp(freq1, freq2)) return true;
            else {
                freq2[s2[b] - 'a']++;
                freq2[s2[a] - 'a']--;
                b++;
                a++;
            }
        }
        if(cmp(freq1, freq2)) return true;
        return false;
    }

    bool cmp(vector<int>& freq1, vector<int>& freq2){   
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }
};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cout << Solution().checkInclusion("aasdasdsagfsrfab", "aasdasdsagfsrfab");
}
