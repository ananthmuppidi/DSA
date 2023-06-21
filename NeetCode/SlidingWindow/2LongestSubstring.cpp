#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         if(s.size() == 0){
            return 0;
        }
        unordered_set<char> charSet;
        int a = 0, b = 1; // a points to the start of my (current) substring, and b points to end 

        charSet.insert(s[0]);
        int maxSubstring = 1;

        while(b < s.size()){
            // want to make sure that the start and the end pointer always point to a valid substring
            if(!charSet.insert(s[b]).second){
                while(!charSet.insert(s[b]).second){
                    charSet.erase(s[a]);
                    a++;
                }
            } 
            maxSubstring = max(maxSubstring, b - a + 1);
            b++;
        }
        maxSubstring = max(maxSubstring, b - a);
        return maxSubstring;
    }   
};



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s = "pwwkew";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
}
