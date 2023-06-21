#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.size() == 1){
            return 1;
        }
        vector<int> freq(26, 0);
        int a = 0, b = 1;
        freq[s[a] - 'A']++;
        int ans = 0;

        while(b < s.size()){

            freq[s[b] - 'A']++;
            if(maxElement(freq) + k < (b - a + 1)){
                freq[s[a] - 'A']--;
                a++;
            } 
            ans = max(ans, b - a + 1);
            b++;
        }
        return ans;
    }

    int maxElement(vector<int>& freq){
        int result = 0 ;
        for(auto &i : freq){
            result = max(result, i);
        }
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << Solution().characterReplacement("ABBBAA", 2);
}
