#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    string minWindow(string s, string t) {
        
        int finalStart = 0, finalEnd = INT_MAX;
        if (t.size() > s.size()) {
            return "";
        }
        string ans = "";
        unordered_map<char, int> freqS, freqT;
        for (char i : t) {
            freqT[i]++;
        }

        int a = 0, b = 0;
        for (; b < t.size(); b++) {
            freqS[s[b]]++;
        }

        while (b < s.size()) {
            
            if (includes(freqS, freqT)) {
                if ((b - a) < finalEnd - finalStart) {
                    finalStart = a;
                    finalEnd = b;
                }

                freqS[s[a]]--;
                a++;
            } else {
                freqS[s[b]]++;
                b++;
            }
        }
        b--;

        while (includes(freqS, freqT)) {
            if ((b - a) < finalEnd - finalStart) {
                finalStart = a;
                finalEnd = b;
            }
            freqS[s[a]]--;
            a++;
        }

    


        if (finalStart == 0 && finalEnd == INT_MAX) {
            return "";
        }
        return s.substr(finalStart, finalEnd - finalStart + 1);
    }

    bool includes(unordered_map<char, int>& freqS, unordered_map<char, int>& freqT) {
        for (auto& i : freqT) {
            if (freqS[i.first] < i.second) {
                return false;
            }
        }
        return true;
    }
};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << Solution().minWindow("ADOBECODEBANC", "BANC");

}
