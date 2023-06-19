#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = cleanString(s);
        int start = 0;
        int end = cleaned.size() - 1;

        while(start <= end){
            if(cleaned[start] != cleaned[end]) return false;
            start++;
            end--; 
        }

        return true;
        
    }

    string cleanString(string s){
        string cleaned = "";
        for(int i = 0; i < s.size(); i++){
            
            if((int(s[i]) <= 122 && int(s[i]) >=97) || (int(s[i]) <= 57 && int(s[i]) >= 48)){
                cleaned.append(string(1, s[i]));
            } else if(int(s[i]) <= 90 && int(s[i]) >= 65){
                cleaned.append(string(1, char(int(s[i]) + 32)));
            } else {

            }
        }
        cout << cleaned;
        return cleaned;
    }
};

int main(){
    cout << Solution().isPalindrome("ab11112ba");
}