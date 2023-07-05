#include <bits/stdc++.h>
using namespace std;

#define md 1000000007
#define PB push_back


class Solution {
public:
    bool isValid(string s) {
        int idx = 0;
        stack<char> st;

        map<char, char> map;
        map.insert({'(',')'});
        map.insert({'{','}'});
        map.insert({'[',']'});

        while(idx < s.size()){
            if(s[idx] == '(' || s[idx] == '{' || s[idx] == '[' ){
                st.push(s[idx]);
            } else {
                if(st.size() == 0) { 
                    return false;
                }
                else if(map[st.top()] == s[idx]) {
                    st.pop();
                }
                else return false;
            }
            idx++;
        }
        if(st.size() == 0) return true;
        else return false;
    
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << Solution().isValid("(]");
}
